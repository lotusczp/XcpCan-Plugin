QT       += widgets network

TEMPLATE = lib
DEFINES += XCPCANPLUGIN_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    LDataProcessing.cpp \
    LElfParser.cpp \
    LElfVarEditorWidget.cpp \
    LXcpCanSettingsRelier.cpp \
    LXcpCanSettingsWidget.cpp \
    LXcpCanToolWidget.cpp \
    LXcpCanTrans.cpp \
    XcpCanPlugin.cpp \
    common/LCanDataManager.cpp \
    common/LDbcManagerDllWrapper.cpp \
    common/LTmctlWrapper.cpp \
    common/LUniqueResource.cpp \
    common/LUsbAdcDataManager.cpp \
    common/LUsbCanDllWrapper.cpp \
    common/LYavUsbAdcDllWrapper.cpp \
    xcpmaster/CmdPacketConnect.cpp \
    xcpmaster/CmdPacketDisconnect.cpp \
    xcpmaster/CmdPacketDownload.cpp \
    xcpmaster/CmdPacketGetSeed.cpp \
    xcpmaster/CmdPacketGetStatus.cpp \
    xcpmaster/CmdPacketSetMta.cpp \
    xcpmaster/CmdPacketShortUpload.cpp \
    xcpmaster/CmdPacketSync.cpp \
    xcpmaster/CmdPacketUnlock.cpp \
    xcpmaster/CmdPacketUpload.cpp \
    xcpmaster/DAQ.cpp \
    xcpmaster/DAQPackets.cpp \
    xcpmaster/DTO.cpp \
    xcpmaster/ErrorPacketAccessLocked.cpp \
    xcpmaster/ErrorPacketCmdUnknown.cpp \
    xcpmaster/ErrorPacketMemoryOverflow.cpp \
    xcpmaster/ErrorPacketOutOfRange.cpp \
    xcpmaster/ErrorPacketSequence.cpp \
    xcpmaster/ErrorPacketSync.cpp \
    xcpmaster/IncomingPacketHandler.cpp \
    xcpmaster/PacketFactory.cpp \
    xcpmaster/ResPacketConnect.cpp \
    xcpmaster/ResPacketGetSeed.cpp \
    xcpmaster/ResPacketGetStatus.cpp \
    xcpmaster/ResPacketUnlock.cpp \
    xcpmaster/ResPacketUpload.cpp \
    xcpmaster/XcpMaster.cpp \
    xcpmaster/XcpMessage.cpp \
    xcpmaster/transport/can/CanHeader.cpp \
    xcpmaster/transport/can/CanMessage.cpp \
    xcpmaster/transport/can/CanMessageFactory.cpp \
    xcpmaster/transport/can/CanTail.cpp \
    xcpmaster/transport/ethernet/EthernetHeader.cpp \
    xcpmaster/transport/ethernet/EthernetMessage.cpp \
    xcpmaster/transport/ethernet/EthernetMessageFactory.cpp \
    xcpmaster/transport/ethernet/EthernetTail.cpp

HEADERS += \
    LDataProcessing.h \
    LElfParser.h \
    LElfVarEditorWidget.h \
    LXcpCanData.h \
    LXcpCanSettingsRelier.h \
    LXcpCanSettingsWidget.h \
    LXcpCanToolWidget.h \
    LXcpCanTrans.h \
    XcpCanPlugin.h \
    XcpCanPlugin_global.h \
    common/LAttributes.h \
    common/LCanDataManager.h \
    common/LCanDataReceiver.h \
    common/LCommon.h \
    common/LCommonError.h \
    common/LDataValue.h \
    common/LDbcManagerDllWrapper.h \
    common/LObixObj.h \
    common/LObixObjTree.h \
    common/LPath.h \
    common/LSettingsRelier.h \
    common/LTmctlWrapper.h \
    common/LTransPluginFactory.h \
    common/LTransmission.h \
    common/LTree.h \
    common/LUniqueResource.h \
    common/LUsbAdcDataManager.h \
    common/LUsbAdcDataReceiver.h \
    common/LUsbCanDllWrapper.h \
    common/LYavUsbAdcDllWrapper.h \
    xcpmaster/CTO.h \
    xcpmaster/CmdPacket.h \
    xcpmaster/CmdPacketConnect.h \
    xcpmaster/CmdPacketDisconnect.h \
    xcpmaster/CmdPacketDownload.h \
    xcpmaster/CmdPacketGetSeed.h \
    xcpmaster/CmdPacketGetStatus.h \
    xcpmaster/CmdPacketSetMta.h \
    xcpmaster/CmdPacketShortUpload.h \
    xcpmaster/CmdPacketSync.h \
    xcpmaster/CmdPacketUnlock.h \
    xcpmaster/CmdPacketUpload.h \
    xcpmaster/DAQ.h \
    xcpmaster/DAQPackets.h \
    xcpmaster/DTO.h \
    xcpmaster/ErrorPacket.h \
    xcpmaster/ErrorPacketAccessLocked.h \
    xcpmaster/ErrorPacketCmdUnknown.h \
    xcpmaster/ErrorPacketMemoryOverflow.h \
    xcpmaster/ErrorPacketOutOfRange.h \
    xcpmaster/ErrorPacketSequence.h \
    xcpmaster/ErrorPacketSync.h \
    xcpmaster/EventPacket.h \
    xcpmaster/IncomingPacketHandler.h \
    xcpmaster/MessageFactory.h \
    xcpmaster/PacketFactory.h \
    xcpmaster/ResPacket.h \
    xcpmaster/ResPacketConnect.h \
    xcpmaster/ResPacketGetSeed.h \
    xcpmaster/ResPacketGetStatus.h \
    xcpmaster/ResPacketUnlock.h \
    xcpmaster/ResPacketUpload.h \
    xcpmaster/XcpHeader.h \
    xcpmaster/XcpMaster.h \
    xcpmaster/XcpMessage.h \
    xcpmaster/XcpPacket.h \
    xcpmaster/XcpTail.h \
    xcpmaster/transport/can/CanHeader.h \
    xcpmaster/transport/can/CanMessage.h \
    xcpmaster/transport/can/CanMessageFactory.h \
    xcpmaster/transport/can/CanTail.h \
    xcpmaster/transport/ethernet/EthernetHeader.h \
    xcpmaster/transport/ethernet/EthernetMessage.h \
    xcpmaster/transport/ethernet/EthernetMessageFactory.h \
    xcpmaster/transport/ethernet/EthernetTail.h


INCLUDEPATH += \
    common \
    xcpmaster \


# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    LElfVarEditorWidget.ui \
    LXcpCanSettingsWidget.ui \
    LXcpCanToolWidget.ui
