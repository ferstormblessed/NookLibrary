cmake_minimum_required(VERSION 3.16)
project(Nook VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(ImGui
        GIT_REPOSITORY https://github.com/ocornut/imgui
        GIT_TAG v1.90.9-docking)
FetchContent_MakeAvailable(ImGui)
FetchContent_GetProperties(ImGui SOURCE_DIR IMGUI_DIR)

set(IMGUI_SFML_FIND_SFML OFF)
FetchContent_Declare(ImGui-SFML
        GIT_REPOSITORY https://github.com/SFML/imgui-sfml
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(ImGui-SFML)

option(BOX2D_BUILD_UNIT_TESTS OFF)
FetchContent_Declare(box2d
        GIT_REPOSITORY      https://github.com/erincatto/Box2D.git
        GIT_TAG             v3.0.0)
FetchContent_MakeAvailable(box2d)

install(TARGETS box2d
        EXPORT Box2DTARGETS
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

install(EXPORT Box2DTARGETS
        FILE Box2DTargets.cmake
        NAMESPACE Box2D::
        DESTINATION lib/cmake/Box2D
)

# Añadir la biblioteca como un objetivo
add_library(NOOK SHARED
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
)

# Include SFML headers
include_directories(${SFML_INCLUDE_DIR})
# Include Imgui-SFML headers
include_directories(${imgui-sfml_SOURCE_DIR})
# Include Box2d headers
include_directories(${box2d_SOURCE_DIR}/include)

# Specify the include directories for the NOOK library
target_include_directories(NOOK
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>    # For users building the library
        $<INSTALL_INTERFACE:include>                        # For users using the installed library
        $<BUILD_INTERFACE:${SFML_SOURCE_DIR}/include>       # Incluye SFML para la construcción
        $<BUILD_INTERFACE:${imgui-sfml_SOURCE_DIR}>         # Incluye ImGui-SFML
        $<BUILD_INTERFACE:${box2d_SOURCE_DIR}>         # Incluye ImGui-SFML
)

target_link_libraries(NOOK PRIVATE sfml-graphics sfml-audio ImGui-SFML::ImGui-SFML box2d)
target_compile_features(NOOK PRIVATE cxx_std_17)

# Instalación (opcional)
install(TARGETS NOOK
        EXPORT NookTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)

install(DIRECTORY include/
        DESTINATION include
)

install(EXPORT NookTargets
        FILE NookTargets.cmake
        NAMESPACE NOOK::
        DESTINATION lib/cmake/Nook
)