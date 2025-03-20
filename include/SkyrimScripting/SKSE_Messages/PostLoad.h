#pragma once

#include <global_macro_functions.h>

#include "MessageCallbacks.h"  // IWYU pragma: export

#define _SKSEPlugin_Message_OnPostLoad_(scopeSymbol)                                                                                                         \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION(scopeSymbol, SkyrimScripting::SKSE_Messages::MessageCallbacks::GetSingleton().RegisterForOnPostLoad) \
    ()

#define _OnPostLoad_ _SKSEPlugin_Message_OnPostLoad_(DEFAULT)
