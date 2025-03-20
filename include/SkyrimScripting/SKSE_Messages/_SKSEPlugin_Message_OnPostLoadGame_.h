#pragma once

#include <global_macro_functions.h>

#include "MessageCallbacks.h"  // IWYU pragma: export

#define _SKSEPlugin_Message_OnPostLoadGame_(scopeSymbol)                                                              \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_ARGUMENTS(                                               \
        scopeSymbol, SkyrimScripting::SKSE_Messages::MessageCallbacks::GetSingleton().RegisterForOnPostLoadGame, bool \
    )

#define SKSEPlugin_OnPostLoadGame _SKSEPlugin_Message_OnPostLoadGame_(DEFAULT)(bool __success)

#define SKSEPlugin_OnPostLoadGame_WithSuccess _SKSEPlugin_Message_OnPostLoadGame_(DEFAULT)
