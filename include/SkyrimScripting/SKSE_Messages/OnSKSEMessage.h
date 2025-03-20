#pragma once

#include <global_macro_functions.h>

#include "MessageCallbacks.h"  // IWYU pragma: export

#define __SKSEMessages_OnMessage__(scopeSymbol) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_ARGUMENTS(scopeSymbol, SkyrimScripting::SKSE_Messages::MessageCallbacks::GetSingleton().RegisterForOnMessage, std::string_view, SKSE::MessagingInterface::Message*)

#define _OnMessage_ __SKSEMessages_OnMessage__(DEFAULT)
