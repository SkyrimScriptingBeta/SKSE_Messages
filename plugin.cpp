#include <RE/Skyrim.h>
#include <SKSE/SKSE.h>
#include <SkyrimScripting/SKSE_Messages.h>

extern "C" __declspec(dllexport) bool SKSEPlugin_Load(const SKSE::LoadInterface* a_skse) {
    SKSE::Init(a_skse);
    SkyrimScripting::SKSE_Messages::ListenForSkseMessages();
    return true;
}

SKSEPlugin_OnDataLoaded { SKSE::log::info("Data loaded"); }

SKSEPlugin_OnDeleteGame { SKSE::log::info("Game deleted"); }
SKSEPlugin_OnDeleteGame_WithFilename(std::string_view a_filename) { SKSE::log::info("Game deleted: {}", a_filename); }

SKSEPlugin_OnInputLoaded { SKSE::log::info("Input loaded"); }

SKSEPlugin_OnNewGame { SKSE::log::info("New game started"); }
SKSEPlugin_OnNewGame_WithQuest(RE::TESQuest* a_quest) { SKSE::log::info("New game started: {}", a_quest->GetName()); }

SKSEPlugin_OnPostLoad { SKSE::log::info("Post load"); }

SKSEPlugin_OnPreLoadGame { SKSE::log::info("Pre load game"); }
SKSEPlugin_OnPreLoadGame_WithFilename(std::string_view a_filename) { SKSE::log::info("Pre load game: {}", a_filename); }

SKSEPlugin_OnPostLoadGame { SKSE::log::info("Post load game"); }
SKSEPlugin_OnPostLoadGame_WithSuccess(bool success) { SKSE::log::info("Post load game: {}", success); }

SKSEPlugin_OnPostPostLoad { SKSE::log::info("Post post load"); }

SKSEPlugin_OnSaveGame { SKSE::log::info("Game saved"); }
SKSEPlugin_OnSaveGame_WithFilename(std::string_view fileName) { SKSE::log::info("Game saved: {}", fileName); }
