/*
 * Copyright (c) 2018 Isetta
 */
#pragma once

namespace Isetta {
BEGIN_COMPONENT(NetworkTestComp, Component, true)
public:
void Start() override;
void GuiUpdate() override;
END_COMPONENT(NetworkTestComp, Component)
}  // namespace Isetta