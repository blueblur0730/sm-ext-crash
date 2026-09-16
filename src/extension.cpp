/**
 * vim: set ts=4 :
 * =============================================================================
 * SourceMod CCrashExtension Extension
 * Copyright (C) 2004-2008 AlliedModders LLC.  All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 *
 * Version: $Id$
 */

#include "extension.h"

/**
 * @file extension.cpp
 * @brief Implement extension code here.
 */

CCrashExtension g_CCrashExtension;		/**< Global singleton for extension's main interface */
SMEXT_LINK(&g_CCrashExtension);

void cc_sv_crash_ext( const CCommand &args )
{
	int *p = nullptr;
	int a = *p;
}
static ConCommand sv_crash_ext("sv_crash_ext", cc_sv_crash_ext, "Crashes server.", FCVAR_CHEAT);

bool CCrashExtension::SDK_OnLoad(char* error, size_t maxlen, bool late) 
{
	sharesys->RegisterLibrary(myself, "crash_ext");
	smutils->LogMessage(myself, "[SM] CrashExtension extension has been loaded.");
	return true;
}

void Sample::SDK_OnAllLoaded() {
{
	sharesys->AddNatives(myself, g_ExtensionNatives);
}

void CCrashExtension::SDK_OnUnload()
{
	smutils->LogMessage(myself, "[SM] CrashExtension extension has been unloaded.");
}
/*
bool CCrashExtension::SDK_OnMetamodLoad(ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
	ismm->RegisterConCommand(g_PLAPI, &sv_crash_ext);
	return true;
}

bool CCrashExtension::SDK_OnMetamodUnload(char *error, size_t maxlen)
{
	return true;
}

bool CCrashExtension::RegisterConCommandBase( ConCommandBase* command )
{
	return META_REGCVAR(command);
}
*/