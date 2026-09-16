#include "natives.h"

static cell_t Crash(IPluginContext* pContext, const cell_t* params) 
{
	int *p = nullptr;
	int a = *p;
	return (cell_t)a;
}

const sp_nativeinfo_t g_ExtensionNatives[] =
{
	{ "CrashExt_DoCrash",                    Crash },
	{ nullptr,                              nullptr }
};