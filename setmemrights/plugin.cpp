#include "plugin.h"

static bool cbCommand(int argc, char* argv[])
{
	duint BeingDebugged;
	int data = 0;
	if (!DbgIsDebugging)
		return false;
	BeingDebugged = (duint)GetPEBLocation(DbgGetProcessHandle());
	_plugin_logprintf("%llu  %llx  ", BeingDebugged, BeingDebugged);
	//bool result = DbgCmdExecDirect("mov [{BeingDebugged}+2], 0400");
	//bool result = DbgMemWrite(BeingDebugged, &data, 1);
	DbgScriptLoad("plugin.txt");
	DbgScriptRun(0);
	//_plugin_logprintf(result ? "true" : "false");
	return true;
}

//Initialize your plugin data here.
bool pluginInit(PLUG_INITSTRUCT* initStruct)
{
    if(!_plugin_registercommand(pluginHandle, PLUGIN_NAME, cbCommand, false))
        _plugin_logputs("[" PLUGIN_NAME "] Error registering the \"" PLUGIN_NAME "\" command!");
    return true; //Return false to cancel loading the plugin.
}

//Deinitialize your plugin data here (clearing menus optional).
bool pluginStop()
{
    return true;
}

//Do GUI/Menu related things here.
void pluginSetup()
{
}
