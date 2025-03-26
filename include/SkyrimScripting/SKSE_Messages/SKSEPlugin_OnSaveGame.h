#pragma once

#include "_SKSEPlugin_OnSaveGame_.h"  // IWYU pragma: export

#define SKSEPlugin_OnSaveGame _SKSEPlugin_OnSaveGame_(DEFAULT)(std::string_view __fileName)
