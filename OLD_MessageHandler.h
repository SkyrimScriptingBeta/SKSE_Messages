// #pragma once

// #include <SKSE/SKSE.h>
// #include <SkyrimScripting/Entrypoint.h>

// #include "MessageCallbacks.h"

// __SKSEPlugin_Init_HighPriority__(SetupSKSEMessageHandler) {
//     // SKSE messages:
//     SKSE::GetMessagingInterface()->RegisterListener([](SKSE::MessagingInterface::Message* message) {
//         SkyrimScripting::SKSE_Messages::MessageCallbacks::GetSingleton().HandleMessage(message->sender, message);
//     });

//     // All other messages:
//     SKSE::GetMessagingInterface()->RegisterListener(nullptr, [](SKSE::MessagingInterface::Message* message) {
//         SkyrimScripting::SKSE_Messages::MessageCallbacks::GetSingleton().HandleMessage(message->sender, message);
//     });
// }
