#include "SkyrimScripting/SKSE_Messages/MessageCallbacks.h"

namespace SkyrimScripting::SKSE_Messages {

    void ListenForSkseMessages() {
        SKSE::GetMessagingInterface()->RegisterListener(SKSE_Messages::MessageCallbacks::SKSE_SENDER, [](SKSE::MessagingInterface::Message* message) {
            SKSE_Messages::MessageCallbacks::GetSingleton().HandleSkseMessage(message);
        });
    }

    void ListenForMessagesFrom(std::string_view sender) {
        SKSE::GetMessagingInterface()->RegisterListener(sender.data(), [](SKSE::MessagingInterface::Message* message) {
            SKSE_Messages::MessageCallbacks::GetSingleton().HandleMessage(message);
        });
    }

    void ListenForMessagesFromAll() {
        SKSE::GetMessagingInterface()->RegisterListener(nullptr, [](SKSE::MessagingInterface::Message* message) {
            SKSE_Messages::MessageCallbacks::GetSingleton().HandleMessage(message);
        });
    }

    std::string_view MessageCallbacks::MessageDataAsStringView(SKSE::MessagingInterface::Message* message) { return {static_cast<char*>(message->data), message->dataLen}; }

    MessageCallbacks& MessageCallbacks::GetSingleton() {
        static MessageCallbacks instance;
        return instance;
    }

    void MessageCallbacks::HandleMessage(SKSE::MessagingInterface::Message* message) {
        for (auto& callback : _onMessage_Callbacks) callback(message);
    }

    void MessageCallbacks::HandleSkseMessage(SKSE::MessagingInterface::Message* message) {
        switch (message->type) {
            case SKSE::MessagingInterface::kPostLoad:
                SKSE::log::trace("Running post-load callbacks");
                for (auto& callback : _onPostLoad_Callbacks) callback();
                break;
            case SKSE::MessagingInterface::kPostPostLoad:
                SKSE::log::trace("Running post-post-load callbacks");
                for (auto& callback : _onPostPostLoad_Callbacks) callback();
                break;
            case SKSE::MessagingInterface::kPreLoadGame: {
                SKSE::log::trace("Running pre-load-game callbacks");
                auto path = MessageDataAsStringView(message);
                for (auto& callback : _onPreLoadGame_Callbacks) callback(path);
                break;
            }
            case SKSE::MessagingInterface::kPostLoadGame: {
                SKSE::log::trace("Running post-load-game callbacks");
                auto success = static_cast<bool>(reinterpret_cast<uintptr_t>(message->data));
                for (auto& callback : _onPostLoadGame_Callbacks) callback(success);
                break;
            }
            case SKSE::MessagingInterface::kSaveGame: {
                SKSE::log::trace("Running save-game callbacks");
                auto path = MessageDataAsStringView(message);
                for (auto& callback : _onSaveGame_Callbacks) callback(path);
                break;
            }
            case SKSE::MessagingInterface::kDeleteGame: {
                SKSE::log::trace("Running delete-game callbacks");
                auto path = MessageDataAsStringView(message);
                for (auto& callback : _onDeleteGame_Callbacks) callback(path);
                break;
            }
            case SKSE::MessagingInterface::kNewGame: {
                SKSE::log::trace("Running new-game callbacks");
                auto quest = static_cast<RE::TESQuest*>(message->data);
                for (auto& callback : _onNewGame_Callbacks) callback(quest);
                break;
            }
            case SKSE::MessagingInterface::kInputLoaded:
                SKSE::log::trace("Running input-loaded callbacks");
                for (auto& callback : _onInputLoaded_Callbacks) callback();
                break;
            case SKSE::MessagingInterface::kDataLoaded:
                SKSE::log::trace("Running data-loaded callbacks");
                for (auto& callback : _onDataLoaded_Callbacks) callback();
                break;
            default:
                SKSE::log::trace("SKSE message type not handled: {}", message->type);
                break;
        }
    }

    void MessageCallbacks::RegisterForOnMessage(std::function<void(SKSE::MessagingInterface::Message*)> callback) { _onMessage_Callbacks.push_back(callback); }
    void MessageCallbacks::RegisterForOnPostLoad(std::function<void()> callback) { _onPostLoad_Callbacks.push_back(callback); }
    void MessageCallbacks::RegisterForOnPostPostLoad(std::function<void()> callback) { _onPostPostLoad_Callbacks.push_back(callback); }
    void MessageCallbacks::RegisterForOnPreLoadGame(std::function<void(std::string_view)> callback) { _onPreLoadGame_Callbacks.push_back(callback); }
    void MessageCallbacks::RegisterForOnPostLoadGame(std::function<void(bool)> callback) { _onPostLoadGame_Callbacks.push_back(callback); }
    void MessageCallbacks::RegisterForOnSaveGame(std::function<void(std::string_view)> callback) { _onSaveGame_Callbacks.push_back(callback); }
    void MessageCallbacks::RegisterForOnDeleteGame(std::function<void(std::string_view)> callback) { _onDeleteGame_Callbacks.push_back(callback); }
    void MessageCallbacks::RegisterForOnNewGame(std::function<void(RE::TESQuest*)> callback) { _onNewGame_Callbacks.push_back(callback); }
    void MessageCallbacks::RegisterForOnInputLoaded(std::function<void()> callback) { _onInputLoaded_Callbacks.push_back(callback); }
    void MessageCallbacks::RegisterForOnDataLoaded(std::function<void()> callback) { _onDataLoaded_Callbacks.push_back(callback); }
}
