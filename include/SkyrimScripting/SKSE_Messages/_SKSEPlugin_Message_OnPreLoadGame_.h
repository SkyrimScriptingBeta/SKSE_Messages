#pragma once

#include <global_macro_functions.h>

#include "MessageCallbacks.h"  // IWYU pragma: export

#define _SKSEPlugin_Message_OnPreLoadGame_(scopeSymbol)                                                                          \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_ARGUMENTS(                                                          \
        scopeSymbol, SkyrimScripting::SKSE_Messages::MessageCallbacks::GetSingleton().RegisterForOnPreLoadGame, std::string_view \
    )

#define SKSEPlugin_OnPreLoadGame _SKSEPlugin_Message_OnPreLoadGame_(DEFAULT)(std::string_view _sksePlugin_onPreLoadGame_filename_)

#define SKSEPlugin_OnPreLoadGame_WithFilename _SKSEPlugin_Message_OnPreLoadGame_(DEFAULT)
