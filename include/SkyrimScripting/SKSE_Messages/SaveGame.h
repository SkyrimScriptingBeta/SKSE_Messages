#pragma once

#include <global_macro_functions.h>

#include "MessageCallbacks.h"  // IWYU pragma: export

#define _SKSEPlugin_Message_OnSaveGame_(scopeSymbol)                                                                          \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_ARGUMENTS(                                                       \
        scopeSymbol, SkyrimScripting::SKSE_Messages::MessageCallbacks::GetSingleton().RegisterForOnSaveGame, std::string_view \
    )

#define _OnSaveGame_ _SKSEPlugin_Message_OnSaveGame_(DEFAULT)

#define _OnSaveGame__ _OnSaveGame_(std::string_view __fileName)
