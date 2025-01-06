# Nimble2D
Nimble2D is a part time project of mine to create a tool for myself creating my own 2D Video game!
The Project is open to use for everyone under the [MIT License](https://mit-license.org/).
## Engine
The **engine** will be light weight providing features to create 2D scenes and handle **gameobjects** inside of them.
**Gameobjects** will be handled using an own written **ECS** **(Entity Component System)** that supports [LUA](https://www.lua.org/) as scripting language with the [sol](https://github.com/ThePhD/sol2) Wrapper!
## Rendering
Rendering is provided by [Raylib](https://www.raylib.com/) while the UI I am using is [rlImGuI](https://github.com/raylib-extras/rlImGui) and [ImGuI](https://github.com/ocornut/imgui)

## Building the engine
### Windows:
***Requirements***:
- [Make](https://www.gnu.org/software/make/)
- Any c++ Compiler that supports c++11 or higher like gcc

**Building debug:**
cd into the cloned repository and enter:
```sh
make debug
```
After building the Project in **debug mode** you can find the **Executable** under "bin/debug/"

**Building release:**
cd into the cloned repository and enter:
```sh
make release
```
After building the Project in **release mode** you can find the **Executable** under "bin/release/"
### Linux:
Linux is currently not supported but it is planned to be in the future!

## License
MIT
