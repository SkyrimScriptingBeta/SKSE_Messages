#pragma once

#include "_SKSEPlugin_OnPreLoadGame_.h"  // IWYU pragma: export

#define SKSEPlugin_OnPreLoadGame _SKSEPlugin_OnPreLoadGame_(DEFAULT)(std::string_view _sksePlugin_onPreLoadGame_filename_)
