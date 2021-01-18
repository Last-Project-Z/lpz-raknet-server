#include "precompiler.h"
#include "native.h"

typedef void(*logprintf_t)(const char* format, ...);
logprintf_t logprintf;
extern void* pAMXFunctions;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = reinterpret_cast<logprintf_t>(ppData[PLUGIN_DATA_LOGPRINTF]);
	logprintf("\n =================================");
	logprintf("   lpz-raknet-server -> Yuklendi  ");
	logprintf(" =================================\n");
	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	logprintf("\n ==================================");
	logprintf("   lpz-raknet-server -> Kapatildi  ");
	logprintf(" ==================================\n");
}

AMX_NATIVE_INFO PluginNatives[] =
{
	{ "ProjectZ", Native::ProjectZ},
	{0, 0}
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx)
{
	return amx_Register(amx, PluginNatives, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx)
{
	return AMX_ERR_NONE;
}