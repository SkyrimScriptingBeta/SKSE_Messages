#pragma once

#define _GLOBAL_MACRO_FUNCTIONS_COMPILATION_UNIT_NAME _SkyrimScripting_SKSEMessages_

#include <global_macro_functions.h>

#include "Internal/MessageCallbacks.h"  // IWYU pragma: export

#define __SKSEMessages_OnSaveGame__(scopeSymbol)                                                                                        \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_ARGUMENTS(                                                                 \
        scopeSymbol, SkyrimScripting::SKSE_Messages::Internal::MessageCallbacks::GetSingleton().RegisterForOnSaveGame, std::string_view \
    )

#define _OnSaveGame_ __SKSEMessages_OnSaveGame__(DEFAULT)

#define _OnSaveGame__ _OnSaveGame_(std::string_view __fileName)
