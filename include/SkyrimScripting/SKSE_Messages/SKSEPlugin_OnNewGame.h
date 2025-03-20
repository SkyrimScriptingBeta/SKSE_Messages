#pragma once

#include "_SKSEPlugin_Message_OnNewGame_.h"  // IWYU pragma: export

#define SKSEPlugin_OnNewGame _SKSEPlugin_Message_OnNewGame_(DEFAULT)(RE::TESQuest * _sksePlugin_onNewGame_quest_)
