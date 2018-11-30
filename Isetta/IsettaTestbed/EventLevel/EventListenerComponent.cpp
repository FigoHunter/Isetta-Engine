/*
 * Copyright (c) 2018 Isetta
 */
#include "EventListenerComponent.h"

namespace Isetta {
void EventListenerComponent::OnEnable() {
  // Register event listener to a specific event
  handle = Events::Instance().RegisterEventListener(
      "RaiseEvent", [](const Isetta::EventObject& eventObject) {
        std::string message{std::get<std::string>(eventObject.eventParams[0])};
        LOG_INFO(Isetta::Debug::Channel::Gameplay,
                 Isetta::Debug::Verbosity::Info, "Event: %s", message.c_str());
      });
}

void EventListenerComponent::OnDisable() {
  Events::Instance().UnregisterEventListener("RaiseEvent", handle);
}
}  // namespace Isetta
