#pragma once

#include "globals.h"
#include "raylib/raylib.h"
#include "rlimgui/imgui.h"
using namespace ImGui;

inline bool settings_open = false;
inline bool style_editor_open = false;

inline void HandleMainMenuBar();
inline void HandleGameSceneViewer();
inline void HandleObjectViewer();
inline void HandleSettingsMenu();

inline void HandleMainMenuBar() {
  BeginMainMenuBar(); // Starting the EndMainMenuBar
#ifdef VERSION
  Text(VERSION);
#endif

  if (BeginMenu("File")) { // Starting File menu
    if (MenuItem("Open..", "Ctrl+O")) {
    }
    if (MenuItem("New", "Ctrl+N")) {
    }
    if (MenuItem("Save", "Ctrl+S")) {
    }
    if (MenuItem("Close", "Ctrl+W")) {
      globals::running = false;
    }
    EndMenu(); // Ending the "File" menu
  }
  if (MenuItem("Settings")) {
    settings_open = !settings_open;
  }
  if (settings_open) {
    HandleSettingsMenu();
  }
  if (MenuItem("Style Editor")) {
    style_editor_open = !style_editor_open;
  }
  if (style_editor_open) {
    Begin("Style Editor");
    ShowStyleEditor();
    if (Button("Close"))
      style_editor_open = false;
    End();
  }

  EndMainMenuBar(); // Ending the MainMenuBar
}

inline void HandleSettingsMenu() {
  Begin("Settings", NULL,
        ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_AlwaysAutoResize); // Starting Settings Window
  if (Checkbox("Fullscreen", &globals::fullscreen)) {
    if (globals::fullscreen) {
      globals::borderless = false;
      globals::maximized = false;
    }
    globals::wasResized = true;
  }
  if (Checkbox("Borderless", &globals::borderless)) {
    if (globals::borderless) {
      globals::fullscreen = false;
      globals::maximized = false;
    }
    globals::wasResized = true;
  }
  if (Checkbox("Maximized", &globals::maximized)) {
    if (globals::maximized) {
      globals::fullscreen = false;
      globals::borderless = false;
    }
    globals::wasResized = true;
  }
  Text("Resolution");
  if (SliderInt("Width", &globals::width, MIN_WIDTH,
                GetMonitorWidth(GetCurrentMonitor()))) {
    globals::wasResized = true;
  }
  if (SliderInt("Height", &globals::height, MIN_HEIGHT,
                GetMonitorHeight(GetCurrentMonitor()))) {
    globals::wasResized = true;
  }
  Text("Misc settings");
  if (SliderInt("FPS", &globals::fps, 30, 320)) {
    globals::wasResized = true;
  }
  if (Checkbox("VSYNC", &globals::vsync)) {
    globals::wasResized = true;
  }
  if (Button("Close"))
    settings_open = false;
  End(); // Ending Settings Window
}

inline void HandleGameSceneViewer() {
  Begin("Game Scene Viewer"); // Starting Game Scene Viewer
  End();                      // Ending Game Scene Viewer
}

inline void HandleObjectViewer() {
  Begin("ObjectViewer"); // Starting Game Scene Viewer
  End();                 // Ending Object Viewer
}
