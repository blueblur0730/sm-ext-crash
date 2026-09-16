#if defined _crash_included
  #endinput
#endif
#define _crash_included

/**
 * Do Crash.
 *
 * @noreturn
 */
native void CrashExt_DoCrash();

public Extension __ext_crash = 
{
	name = "crash",
	file = "crash.ext",
#if defined AUTOLOAD_EXTENSIONS
	autoload = 1,
#else
	autoload = 0,
#endif
#if defined REQUIRE_EXTENSIONS
	required = 1,
#else
	required = 0,
#endif
};

#if !defined REQUIRE_EXTENSIONS
public void __ext_crash_SetNTVOptional()
{
    MarkNativeAsOptional("CrashExt_DoCrash");
}
#endif