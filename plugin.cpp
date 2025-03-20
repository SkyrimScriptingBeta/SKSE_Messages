#include <RE/Skyrim.h>
#include <SKSE/SKSE.h>
#include <SkyrimScripting/SKSE_Messages.h>

extern "C" __declspec(dllexport) bool SKSEPlugin_Load(const SKSE::LoadInterface* a_skse) {
    SKSE::Init(a_skse);
    SkyrimScripting::SKSE_Messages::ListenForSkseMessages();
    SkyrimScripting::SKSE_Messages::ListenForMessagesFromAll();
    return true;
}

SKSEPlugin_OnMessage(SKSE::MessagingInterface::Message* message) { SKSE::log::info("Message from {}: {}", message->sender, message->type); }

SKSEPlugin_OnDataLoaded { SKSE::log::info("Data loaded"); }

SKSEPlugin_OnDeleteGame { SKSE::log::info("Game deleted"); }
SKSEPlugin_OnDeleteGame_WithFilename(std::string_view a_filename) { SKSE::log::info("Game deleted: {}", a_filename); }

SKSEPlugin_OnInputLoaded { SKSE::log::info("Input loaded"); }

SKSEPlugin_OnNewGame { SKSE::log::info("New game started"); }
SKSEPlugin_OnNewGame_WithQuest(RE::TESQuest* a_quest) { SKSE::log::info("New game started: {}", a_quest->GetName()); }

SKSEPlugin_OnPostLoad {
    SKSE::log::info("Post load");

    // Now that all the plugins are loaded, send a message to all of them
    SKSE::GetMessagingInterface()->Dispatch(6420, nullptr, 0, nullptr);
}

SKSEPlugin_OnPreLoadGame { SKSE::log::info("Pre load game"); }
SKSEPlugin_OnPreLoadGame_WithFilename(std::string_view a_filename) { SKSE::log::info("Pre load game: {}", a_filename); }

SKSEPlugin_OnPostLoadGame { SKSE::log::info("Post load game"); }
SKSEPlugin_OnPostLoadGame_WithSuccess(bool success) { SKSE::log::info("Post load game: {}", success); }

SKSEPlugin_OnPostPostLoad { SKSE::log::info("Post post load"); }

SKSEPlugin_OnSaveGame { SKSE::log::info("Game saved"); }
SKSEPlugin_OnSaveGame_WithFilename(std::string_view fileName) { SKSE::log::info("Game saved: {}", fileName); }
