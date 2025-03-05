#pragma once

#include <global_macro_functions.h>

#include "Internal/MessageCallbacks.h"  // IWYU pragma: export

#define __SKSEMessages_OnPostLoadGame__(scopeSymbol)                                                                            \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_ARGUMENTS(                                                         \
        scopeSymbol, SkyrimScripting::SKSE_Messages::Internal::MessageCallbacks::GetSingleton().RegisterForOnPostLoadGame, bool \
    )

#define _OnPostLoadGame_ __SKSEMessages_OnPostLoadGame__(DEFAULT)

#define _OnPostLoadGame__ _OnPostLoadGame_(bool __success)
