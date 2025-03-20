#pragma once

#include <global_macro_functions.h>

#include "MessageCallbacks.h"  // IWYU pragma: export

#define _SKSEPlugin_Message_OnInputLoaded_(scopeSymbol)                                                                                                         \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION(scopeSymbol, SkyrimScripting::SKSE_Messages::MessageCallbacks::GetSingleton().RegisterForOnInputLoaded) \
    ()

#define _OnInputLoaded_ _SKSEPlugin_Message_OnInputLoaded_(DEFAULT)
