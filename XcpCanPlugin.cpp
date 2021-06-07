#include "XcpCanPlugin.h"

#include "LXcpCanTrans.h"

LTransmission *XcpCanPlugin::createTransInstance()
{
    return new LXcpCanTrans;
}
