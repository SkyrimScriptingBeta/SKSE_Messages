#pragma once

#define _GLOBAL_MACRO_FUNCTIONS_COMPILATION_UNIT_NAME _SkyrimScripting_SKSEMessages_

#include <global_macro_functions.h>

#include "Internal/MessageCallbacks.h"  // IWYU pragma: export

#define __SKSEMessages_OnNewGame__(scopeSymbol) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_ARGUMENTS(scopeSymbol, SkyrimScripting::SKSE_Messages::Internal::MessageCallbacks::GetSingleton().RegisterForOnNewGame, RE::TESQuest*)

#define _OnNewGame_ __SKSEMessages_OnNewGame__(DEFAULT)

#define _OnNewGame__ _OnNewGame_(RE::TESQuest* __quest)
