#pragma once

#define _GLOBAL_MACRO_FUNCTIONS_COMPILATION_UNIT_NAME _SkyrimScripting_SKSEMessages_

#include <global_macro_functions.h>

#include "Internal/MessageCallbacks.h"  // IWYU pragma: export

#define __SKSEMessages_OnPreLoadGame__(scopeSymbol)                                                                                        \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_ARGUMENTS(                                                                    \
        scopeSymbol, SkyrimScripting::SKSE_Messages::Internal::MessageCallbacks::GetSingleton().RegisterForOnPreLoadGame, std::string_view \
    )

#define _OnPreLoadGame_ __SKSEMessages_OnPreLoadGame__(DEFAULT)

#define _OnPreLoadGame__ _OnPreLoadGame_(std::string_view __fileName)
