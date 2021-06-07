#ifndef XCPCANPLUGIN_H
#define XCPCANPLUGIN_H

#include "XcpCanPlugin_global.h"

#include "LTransPluginFactory.h"

class XCPCANPLUGIN_EXPORT XcpCanPlugin : public LTransPluginFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Lobster.LTransPluginFactory" FILE "XcpCanPlugin.json")
    Q_INTERFACES(LTransPluginFactory)

public:
    XcpCanPlugin() {}
    ~XcpCanPlugin() Q_DECL_OVERRIDE {}

    //! create the transmission instance
    virtual LTransmission* createTransInstance() Q_DECL_OVERRIDE;
};

#endif // XCPCANPLUGIN_H
