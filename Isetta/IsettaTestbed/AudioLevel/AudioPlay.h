/*
 * Copyright (c) 2018 Isetta
 */
#pragma once
namespace Isetta {
BEGIN_COMPONENT(AudioPlay, Component, true)
private:
class AudioSource* const src = nullptr;
KeyCode key;
U64 handle;

public:
AudioPlay(KeyCode key, class AudioSource* const src) : key{key}, src{src} {}

void OnEnable() override;
void OnDisable() override;
END_COMPONENT(AudioPlay, Component)
}  // namespace Isetta
