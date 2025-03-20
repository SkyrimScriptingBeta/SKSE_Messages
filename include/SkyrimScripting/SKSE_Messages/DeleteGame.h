#pragma once

#include <global_macro_functions.h>

#include "MessageCallbacks.h"  // IWYU pragma: export

#define __SKSEMessages_OnDeleteGame__(scopeSymbol)                                                                              \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_ARGUMENTS(                                                         \
        scopeSymbol, SkyrimScripting::SKSE_Messages::MessageCallbacks::GetSingleton().RegisterForOnDeleteGame, std::string_view \
    )

#define _OnDeleteGame_ __SKSEMessages_OnDeleteGame__(DEFAULT)

#define _OnDeleteGame__ _OnDeleteGame_(std::string_view __fileName)
