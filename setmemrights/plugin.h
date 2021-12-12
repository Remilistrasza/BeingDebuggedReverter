#pragma once

#include "pluginmain.h"

//plugin data
#define PLUGIN_NAME "BeingDebuggedReverter"
#define PLUGIN_VERSION 1

//functions
bool pluginInit(PLUG_INITSTRUCT* initStruct);
bool pluginStop();
void pluginSetup();
