#ifndef LXCPCANSETTINGSWIDGET_H
#define LXCPCANSETTINGSWIDGET_H

#include <QWidget>
#include "LUniqueResource.h"

namespace Ui {
class LXcpCanSettingsWidget;
}

class LXcpCanSettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LXcpCanSettingsWidget(QWidget *parent = nullptr);
    ~LXcpCanSettingsWidget();

    void setCanDataManager(LCanDataManager *a_pCanDataManager);

signals:
    void sendDeviceReady(bool isReady, unsigned long deviceIndex, unsigned long canIndex, unsigned long devType);

private slots:
    void on_buttonConnect_clicked();

    void on_buttonDisconnect_clicked();

private:
    void deviceConnected();

private:
    Ui::LXcpCanSettingsWidget *ui;
    LCanDataManager         *m_pCanDataManager;
};

#endif // LXCPCANSETTINGSWIDGET_H
