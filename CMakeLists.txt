cmake_minimum_required(VERSION 3.16)
project(Nook VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

include(FetchContent)

# Fetch dependencies
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(ImGui
        GIT_REPOSITORY https://github.com/ocornut/imgui
        GIT_TAG v1.90.9-docking)
FetchContent_MakeAvailable(ImGui)

FetchContent_Declare(ImGui-SFML
        GIT_REPOSITORY https://github.com/SFML/imgui-sfml
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(ImGui-SFML)

FetchContent_Declare(box2d
        GIT_REPOSITORY https://github.com/erincatto/Box2D.git
        GIT_TAG v3.0.0)
FetchContent_MakeAvailable(box2d)

# Define the NOOK library
add_library(NOOK SHARED
        include/NOOK/core/Types.h
        include/NOOK/core/System.h
        src/core/ResourceManager.cpp
        src/GUI/Screens.cpp
        src/Systems/Debug/DebugSystem.cpp
        src/Systems/GameLogic/GameLogicSystem.cpp
        src/Systems/GameLogic/GameOverSystem.cpp
        src/Systems/GameLogic/PauseSystem.cpp
        src/Systems/Movement/MovementSystem.cpp
        src/Systems/Movement/JumpSystem.cpp
        src/Systems/Physics/PhysicsSystem.cpp
        src/Systems/Render/RenderShapeSystem.cpp
        src/Systems/Render/RenderSpriteSystem.cpp
        src/Systems/Render/RenderTextSystem.cpp
        src/Utils/utils.cpp
        src/Utils/Register.cpp
)

# Include directories
target_include_directories(NOOK
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${SFML_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${imgui-sfml_SOURCE_DIR}>
        $<BUILD_INTERFACE:${box2d_SOURCE_DIR}/include>
)

# Link dependencies
target_link_libraries(NOOK PUBLIC sfml-graphics sfml-audio ImGui-SFML::ImGui-SFML box2d)

# Installation
install(TARGETS NOOK
        EXPORT NookTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)

install(EXPORT NookTargets
        FILE NookTargets.cmake
        NAMESPACE NOOK::
        DESTINATION lib/cmake/Nook
)