#pragma once

#include "_SKSEPlugin_Message_OnSaveGame_.h"  // IWYU pragma: export

#define SKSEPlugin_OnSaveGame _SKSEPlugin_Message_OnSaveGame_(DEFAULT)(std::string_view __fileName)
