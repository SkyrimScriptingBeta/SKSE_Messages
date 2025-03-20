#pragma once

#include <global_macro_functions.h>

#include "MessageCallbacks.h"  // IWYU pragma: export

#define __SKSEMessages_OnPreLoadGame__(scopeSymbol)                                                                              \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_ARGUMENTS(                                                          \
        scopeSymbol, SkyrimScripting::SKSE_Messages::MessageCallbacks::GetSingleton().RegisterForOnPreLoadGame, std::string_view \
    )

#define _OnPreLoadGame_ __SKSEMessages_OnPreLoadGame__(DEFAULT)

#define _OnPreLoadGame__ _OnPreLoadGame_(std::string_view __fileName)
