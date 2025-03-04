#include <SkyrimScripting/Entrypoint.h>
#include <SkyrimScripting/Logging.h>
#include <SkyrimScripting/SKSE_Messages.h>

_SKSEPlugin_Init_ { SKSE::log::info("Plugin loaded!"); }

_OnPostLoad_ { SKSE::log::info("Post load!"); }
_OnPostPostLoad_ { SKSE::log::info("Post post load!"); }

_OnDataLoaded_ {
    SKSE::log::info("Data loaded! hello?");
    PrintToConsole("Data loaded!");
    SKSE::log::info("Data loaded! from SKSE::log");
}

_OnInputLoaded_ { SKSE::log::info("Input loaded!"); }

_OnNewGame__ { SKSE::log::info("New game started!"); }
_OnSaveGame__ { SKSE::log::info("Game saved!"); }
_OnDeleteGame__ { SKSE::log::info("Game deleted!"); }

_OnPreLoadGame__ {
    SKSE::log::info("Pre load game!");
}
