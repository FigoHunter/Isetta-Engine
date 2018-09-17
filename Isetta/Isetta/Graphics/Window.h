/*
 * Copyright (c) 2018 Isetta
 */
#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include "Core/Config/CVar.h"
#include "Core/IModule.h"
#include "Core/ModuleManager.h"

namespace Isetta {
class WindowModule {
 public:
  struct WindowConfig {
    CVarInt windowWidth{"window_width", 1024};
    CVarInt windowHeight{"window_height", 768};
    CVarString windowTitle{"window_title", "Game"};
    CVarInt windowFullScreen{"window_fullscreen", 0};
    CVarInt windowShowCursor{"window_show_cursor", 1};
  };

 private:
  WindowModule() = default;
  ~WindowModule() = default;

  void StartUp();
  void Update(float deltaTime);
  void ShutDown();

  std::string winTitle;
  int initWinWidth;
  int initWinHeight;
  bool winFullScreen;
  bool winShowCursor;

  void InitWindow();
  void InitRenderConfig();

  GLFWwindow* winHandle;

  class RenderModule* renderModule;
  class InputModule* inputModule;
  friend class ModuleManager;
};
}  // namespace Isetta
