#include <QMessageBox>
#include "LXcpCanTrans.h"

// Static class data
const QString LXcpCanTrans::s_strProtocolName = "XcpCan";
const QString LXcpCanTrans::s_strSwVersion = "1.0";


LXcpCanTrans::LXcpCanTrans()
{
    m_bIsDeviceReady = false;
    m_pCanDataManager = nullptr;

    m_pDataProc = new LDataProcessing(m_mapAllData, m_mutex);
    m_pDataProcThread = new QThread;
    /// \note This will move ALL the slots of LDataProcessing processed in the sub-thread
#if 0
    m_pDataProc->moveToThread(m_pDataProcThread);
#endif

    m_pSettingsWidget = new LXcpCanSettingsWidget;
    m_pToolWidget = new LXcpCanToolWidget;

    m_pSettingsRelier = new LXcpCanSettingsRelier(m_mapAllData, m_pToolWidget->getElfVarEditorWidget());

    m_pToolWidget->getElfVarEditorWidget()->setDataMap(&m_mapAllData);

    connect(m_pSettingsWidget, &LXcpCanSettingsWidget::sendDeviceReady, this, &LXcpCanTrans::receiveDeviceReady);
    connect(m_pSettingsWidget, &LXcpCanSettingsWidget::sendDeviceReady, m_pDataProc, &LDataProcessing::receiveDeviceReady);
    connect(m_pToolWidget->getElfVarEditorWidget(), &LElfVarEditorWidget::applyAllData, m_pDataProc, &LDataProcessing::applyAllData);
    connect(m_pDataProc, &LDataProcessing::sendSingleVar, this, &LXcpCanTrans::receiveSingleVar);
    connect(m_pToolWidget->getElfVarEditorWidget(), &LElfVarEditorWidget::saveSettings, m_pSettingsRelier, &LXcpCanSettingsRelier::saveSettings);

#if 0
    // Start data processing thread
    m_pDataProcThread->start();
#endif
}

LXcpCanTrans::~LXcpCanTrans()
{
    // Make sure the thread quits
    m_pDataProcThread->quit();
    m_pDataProcThread->wait();

    // we only need delete this map, other LEvoxVarData* containers all point to memory managed by this one
    qDeleteAll(m_mapAllData);
    m_mapAllData.clear();

    m_pDataProc->deleteLater();

    if(m_pSettingsWidget != NULL) {
        delete m_pSettingsWidget, m_pSettingsWidget = NULL;
    }
    if(m_pSettingsRelier != NULL) {
        delete m_pSettingsRelier, m_pSettingsRelier = NULL;
    }
    if (m_pToolWidget != NULL) {
        delete m_pToolWidget, m_pToolWidget = NULL;
    }
}

void LXcpCanTrans::configurate(const LObixObjIter &a_rConfigIter)
{
    // Parse the configuration file and add points
    m_bErrorFlag = false;
    parseConfigTree(a_rConfigIter);

    m_pDataProc->setCanMsgId(m_iSlaveRxCanId, m_iSlaveTxCanId);
}

bool LXcpCanTrans::getDataList(LDataNameList &a_rDataNameList) const
{
    if(m_bErrorFlag) {
        return false;
    }
    else {
        a_rDataNameList = m_mapAllData.keys();
        return true;
    }
}

void LXcpCanTrans::resetCaredDataList(const LDataNameList &a_rCaredDataNameList)
{
    // clear the old list
    m_mapCaredData.clear();

    // build a new one
    LDataNameListIter i(a_rCaredDataNameList);
    QString strName;
    while (i.hasNext()) {
        strName = i.next();
        if(m_mapAllData.contains(strName)) {
            m_mapCaredData[strName] = m_mapAllData[strName];
        }
    }
}

void LXcpCanTrans::start()
{
    m_pDataProc->startProcessing(true);
}

void LXcpCanTrans::stop()
{
    m_pDataProc->startProcessing(false);
}

void LXcpCanTrans::setChannelPrefix(const QString &a_rPrefix)
{
    m_strPrefix = a_rPrefix;
}

const QString &LXcpCanTrans::getProtocolName() const
{
    return s_strProtocolName;
}

const QString &LXcpCanTrans::getSwVersion() const
{
    return s_strSwVersion;
}

QWidget *LXcpCanTrans::getSettingsWidget()
{
    return m_pSettingsWidget;
}

LSettingsRelier *LXcpCanTrans::getSettingsRelier()
{
    return m_pSettingsRelier;
}

QWidget *LXcpCanTrans::getToolWidget()
{
    return m_pToolWidget;
}

void LXcpCanTrans::setDataValue(QString a_strDataName, LDataValue a_dataValue)
{
    // remove prefix
    QString strNameWithoutPrefix = a_strDataName.right(a_strDataName.length()-1-m_strPrefix.length());

    m_pDataProc->setValueCmd(strNameWithoutPrefix, a_dataValue.getValue());
}

void LXcpCanTrans::setUniqueResource(const LUniqueResource &a_rUniqueResource)
{
    m_pCanDataManager = a_rUniqueResource.pUsbCan;

    m_pSettingsWidget->setCanDataManager(m_pCanDataManager);
    m_pDataProc->setCanDataManager(m_pCanDataManager);
}

void LXcpCanTrans::pullAttributes()
{
    // Nothing
}

void LXcpCanTrans::pullDataValue(QString a_strDataName)
{
    // remove prefix
    QString strNameWithoutPrefix = a_strDataName.right(a_strDataName.length()-1-m_strPrefix.length());

    m_pDataProc->pullValueCmd(strNameWithoutPrefix);
}

void LXcpCanTrans::receiveSingleVar(QString a_strDataName, LDataValue a_dataValue)
{
    LDataValueList valueList;
    valueList.append(a_dataValue);
    emit notifySingleVar(m_strPrefix+"_"+a_strDataName, valueList);
}

void LXcpCanTrans::parseConfigTree(const LObixObjIter &a_rConfigIter)
{
    LObixObjIter configIter = a_rConfigIter;
    if ((configIter.getValue().getType() == eObj) && (configIter.getValue().getProperty("is") == "XcpCan Plugin Config")) {
        configIter.moveToFirstChild();
    }
    else {
        m_bErrorFlag = true;
        return;
    }

    if ((configIter.getValue().getType() == eInt) && (configIter.getValue().getProperty("name") == "Slave Receive CAN ID")) {
        m_iSlaveRxCanId = configIter.getValue().getProperty("val").toInt(nullptr, 16);
    }
    else {
        m_bErrorFlag = true;
        return;
    }

    configIter.moveToNextSibling();
    if ((configIter.getValue().getType() == eInt) && (configIter.getValue().getProperty("name") == "Slave Transmit CAN ID")) {
        m_iSlaveTxCanId = configIter.getValue().getProperty("val").toInt(nullptr, 16);
    }
    else {
        m_bErrorFlag = true;
        return;
    }
}

void LXcpCanTrans::receiveDeviceReady(bool isConnected, unsigned long deviceIndex, unsigned long canIndex, unsigned long devType)
{
    m_bIsDeviceReady = isConnected;
}
