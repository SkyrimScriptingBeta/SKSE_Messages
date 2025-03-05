#pragma once

#include <global_macro_functions.h>

#include "Internal/MessageCallbacks.h"  // IWYU pragma: export

#define __SKSEMessages_OnDataLoaded__(scopeSymbol)                                                                                                                       \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION(scopeSymbol, SkyrimScripting::SKSE_Messages::Internal::MessageCallbacks::GetSingleton().RegisterForOnDataLoaded) \
    ()

#define _OnDataLoaded_ __SKSEMessages_OnDataLoaded__(DEFAULT)
