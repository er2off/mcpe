cmake_minimum_required(VERSION 3.16.0)
project(Core)

include_directories(. ..)

# Build
add_subdirectory(common)
add_subdirectory(network)
add_subdirectory(server)
add_subdirectory(world)

add_library(Core INTERFACE)
target_include_directories(Core INTERFACE . ..)

target_link_libraries(Core INTERFACE
    Common
    Renderer
    Network
    Server
    World
)

if (NOT platform STREQUAL server)
    add_subdirectory(client)
    add_subdirectory(renderer)
    target_link_libraries(Core INTERFACE Client)
endif()

# Assets
if (NOT ANDROID AND NOT EMSCRIPTEN)
    file(MAKE_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
    file(CREATE_LINK "${CMAKE_CURRENT_SOURCE_DIR}/../game/assets" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets" SYMBOLIC)
endif()
