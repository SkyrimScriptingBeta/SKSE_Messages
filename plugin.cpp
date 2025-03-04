#include <SkyrimScripting/SKSE_Messages.h>

_OnPostLoad_ { SKSE::log::info("Post load!"); }
_OnPostPostLoad_ { SKSE::log::info("Post post load!"); }
_OnDataLoaded_ { SKSE::log::info("Data loaded!"); }
_OnInputLoaded_ { SKSE::log::info("Input loaded!"); }
_OnNewGame__ { SKSE::log::info("New game started!"); }
_OnSaveGame__ { SKSE::log::info("Game saved!"); }
_OnDeleteGame__ { SKSE::log::info("Game deleted!"); }
_OnPreLoadGame__ { SKSE::log::info("Pre load game!"); }
_OnPostLoadGame__ { SKSE::log::info("Post load game!"); }
