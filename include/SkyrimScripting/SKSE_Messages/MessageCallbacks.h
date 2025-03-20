#pragma once

#include <SKSE/SKSE.h>

#include <functional>
#include <string_view>
#include <vector>

namespace SkyrimScripting::SKSE_Messages {

    class MessageCallbacks {
        std::vector<std::function<void(std::string_view, SKSE::MessagingInterface::Message*)>> _onMessage_Callbacks;
        std::vector<std::function<void()>>                                                     _onPostLoad_Callbacks;
        std::vector<std::function<void()>>                                                     _onPostPostLoad_Callbacks;
        std::vector<std::function<void(std::string_view)>>                                     _onPreLoadGame_Callbacks;
        std::vector<std::function<void(bool)>>                                                 _onPostLoadGame_Callbacks;
        std::vector<std::function<void(std::string_view)>>                                     _onSaveGame_Callbacks;
        std::vector<std::function<void(std::string_view)>>                                     _onDeleteGame_Callbacks;
        std::vector<std::function<void(RE::TESQuest*)>>                                        _onNewGame_Callbacks;
        std::vector<std::function<void()>>                                                     _onInputLoaded_Callbacks;
        std::vector<std::function<void()>>                                                     _onDataLoaded_Callbacks;

        std::string_view MessageDataAsStringView(SKSE::MessagingInterface::Message* message);

    public:
        static inline auto SKSE_SENDER = "SKSE";

        static MessageCallbacks& GetSingleton();

        void HandleMessage(const char* sender, SKSE::MessagingInterface::Message* message);
        void RegisterForOnMessage(std::function<void(std::string_view, SKSE::MessagingInterface::Message*)> callback);
        void RegisterForOnPostLoad(std::function<void()> callback);
        void RegisterForOnPostPostLoad(std::function<void()> callback);
        void RegisterForOnPreLoadGame(std::function<void(std::string_view)> callback);
        void RegisterForOnPostLoadGame(std::function<void(bool)> callback);
        void RegisterForOnSaveGame(std::function<void(std::string_view)> callback);
        void RegisterForOnDeleteGame(std::function<void(std::string_view)> callback);
        void RegisterForOnNewGame(std::function<void(RE::TESQuest*)> callback);
        void RegisterForOnInputLoaded(std::function<void()> callback);
        void RegisterForOnDataLoaded(std::function<void()> callback);
    };
}
