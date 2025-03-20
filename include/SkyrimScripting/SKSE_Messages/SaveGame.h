#pragma once

#include <global_macro_functions.h>

#include "MessageCallbacks.h"  // IWYU pragma: export

#define __SKSEMessages_OnSaveGame__(scopeSymbol)                                                                              \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_ARGUMENTS(                                                       \
        scopeSymbol, SkyrimScripting::SKSE_Messages::MessageCallbacks::GetSingleton().RegisterForOnSaveGame, std::string_view \
    )

#define _OnSaveGame_ __SKSEMessages_OnSaveGame__(DEFAULT)

#define _OnSaveGame__ _OnSaveGame_(std::string_view __fileName)
