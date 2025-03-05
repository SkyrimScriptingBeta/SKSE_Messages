#pragma once

#include <SKSE/SKSE.h>  // IWYU pragma: keep
#include <global_macro_functions.h>

#include <string_view>  // IWYU pragma: keep

#include "Internal/MessageCallbacks.h"  // IWYU pragma: export

#define __SKSEMessages_OnMessage__(scopeSymbol) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION_WITH_ARGUMENTS(scopeSymbol, SkyrimScripting::SKSE_Messages::Internal::MessageCallbacks::GetSingleton().RegisterForOnMessage, std::string_view, SKSE::MessagingInterface::Message*)

#define _OnMessage_ __SKSEMessages_OnMessage__(DEFAULT)
