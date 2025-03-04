#define _GLOBAL_MACRO_FUNCTIONS_COMPILATION_UNIT_NAME _SkyrimScripting_SKSE_Messages_

#if __has_include(<SkyrimScripting/Logging.h>)
    #include <SkyrimScripting/Logging.h>
#endif

#if __has_include(<_Log_.h>)
    #include <_Log_.h>
#elifndef _Log_
    #define _Log_(...)
#endif

#include "SkyrimScripting/SKSE_Messages/Internal/MessageCallbacks.h"

namespace SkyrimScripting::SKSE_Messages::Internal {

    std::string_view MessageCallbacks::MessageDataAsStringView(SKSE::MessagingInterface::Message* message) { return {static_cast<char*>(message->data), message->dataLen}; }

    MessageCallbacks& MessageCallbacks::GetSingleton() {
        static MessageCallbacks instance;
        return instance;
    }

    void MessageCallbacks::HandleMessage(const char* sender, SKSE::MessagingInterface::Message* message) {
        for (auto& callback : _onMessage_Callbacks) callback(sender, message);
        if (strcmp(sender, SKSE_SENDER) == 0) {
            switch (message->type) {
                case SKSE::MessagingInterface::kPostLoad:
                    _Log_("Running post-load callbacks");
                    for (auto& callback : _onPostLoad_Callbacks) callback();
                    break;
                case SKSE::MessagingInterface::kPostPostLoad:
                    _Log_("Running post-post-load callbacks");
                    for (auto& callback : _onPostPostLoad_Callbacks) callback();
                    break;
                case SKSE::MessagingInterface::kPreLoadGame: {
                    _Log_("Running pre-load-game callbacks");
                    auto path = MessageDataAsStringView(message);
                    for (auto& callback : _onPreLoadGame_Callbacks) callback(path);
                    break;
                }
                case SKSE::MessagingInterface::kPostLoadGame: {
                    _Log_("Running post-load-game callbacks");
                    auto success = static_cast<bool>(reinterpret_cast<uintptr_t>(message->data));
                    for (auto& callback : _onPostLoadGame_Callbacks) callback(success);
                    break;
                }
                case SKSE::MessagingInterface::kSaveGame: {
                    _Log_("Running save-game callbacks");
                    auto path = MessageDataAsStringView(message);
                    for (auto& callback : _onSaveGame_Callbacks) callback(path);
                    break;
                }
                case SKSE::MessagingInterface::kDeleteGame: {
                    _Log_("Running delete-game callbacks");
                    auto path = MessageDataAsStringView(message);
                    for (auto& callback : _onDeleteGame_Callbacks) callback(path);
                    break;
                }
                case SKSE::MessagingInterface::kNewGame: {
                    _Log_("Running new-game callbacks");
                    auto quest = static_cast<RE::TESQuest*>(message->data);
                    for (auto& callback : _onNewGame_Callbacks) callback(quest);
                    break;
                }
                case SKSE::MessagingInterface::kInputLoaded:
                    _Log_("Running input-loaded callbacks");
                    for (auto& callback : _onInputLoaded_Callbacks) callback();
                    break;
                case SKSE::MessagingInterface::kDataLoaded:
                    _Log_("Running data-loaded callbacks");
                    for (auto& callback : _onDataLoaded_Callbacks) callback();
                    break;
                default:
                    _Log_("SKSE message type not handled: {}", message->type);
                    break;
            }
        }
    }

    void MessageCallbacks::RegisterForOnMessage(std::function<void(std::string_view, SKSE::MessagingInterface::Message*)> callback) { _onMessage_Callbacks.push_back(callback); }
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
