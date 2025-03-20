#pragma once

#include <string_view>

namespace SkyrimScripting::SKSE_Messages {

    void ListenForSkseMessages();
    void ListenForMessagesFrom(std::string_view sender);
    void ListenForMessagesFromAll();
}
