#pragma once

#include <global_macro_functions.h>

#include "MessageCallbacks.h"  // IWYU pragma: export

#define _SKSEPlugin_Message_OnNewGame_(scopeSymbol) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_ARGUMENTS(scopeSymbol, SkyrimScripting::SKSE_Messages::MessageCallbacks::GetSingleton().RegisterForOnNewGame, RE::TESQuest*)

#define _OnNewGame_ _SKSEPlugin_Message_OnNewGame_(DEFAULT)

#define _OnNewGame__ _OnNewGame_(RE::TESQuest* __quest)
