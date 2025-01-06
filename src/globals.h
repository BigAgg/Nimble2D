#pragma once

#include "raylib/raylib.h"
#include <string>

#define MIN_WIDTH 1080
#define MIN_HEIGHT 720

namespace globals {
inline bool running;
inline bool wasResized = false;

inline Camera2D gameCam;
inline Camera2D menuCam;

inline int width, height, fps;
inline bool fullscreen, borderless, vsync, maximized, paused, darkTheme;
} // namespace globals
