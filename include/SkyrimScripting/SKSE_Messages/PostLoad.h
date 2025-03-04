#pragma once

#define _GLOBAL_MACRO_FUNCTIONS_COMPILATION_UNIT_NAME _SkyrimScripting_SKSEMessages_

#include <global_macro_functions.h>

#include "Internal/MessageCallbacks.h"  // IWYU pragma: export

#define __SKSEMessages_OnPostLoad__(scopeSymbol)                                                                                                                       \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION(scopeSymbol, SkyrimScripting::SKSE_Messages::Internal::MessageCallbacks::GetSingleton().RegisterForOnPostLoad) \
    ()

#define _OnPostLoad_ __SKSEMessages_OnPostLoad__(DEFAULT)
