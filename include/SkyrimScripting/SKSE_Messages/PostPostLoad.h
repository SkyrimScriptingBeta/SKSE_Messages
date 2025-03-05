#pragma once

#include <global_macro_functions.h>

#include "Internal/MessageCallbacks.h"  // IWYU pragma: export

#define __SKSEMessages_OnPostPostLoad__(scopeSymbol)                                                                                                                       \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION(scopeSymbol, SkyrimScripting::SKSE_Messages::Internal::MessageCallbacks::GetSingleton().RegisterForOnPostPostLoad) \
    ()

#define _OnPostPostLoad_ __SKSEMessages_OnPostPostLoad__(DEFAULT)
