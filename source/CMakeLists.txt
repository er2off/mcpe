cmake_minimum_required(VERSION 3.16.0)
project(reminecraftpe-core)

include_directories(. ..)

# Build
add_subdirectory(common)
add_subdirectory(network)
add_subdirectory(renderer)
add_subdirectory(world)

add_subdirectory(client)

add_library(reminecraftpe-core INTERFACE)
target_include_directories(reminecraftpe-core INTERFACE . ..)
target_link_libraries(reminecraftpe-core INTERFACE
    reminecraftpe-common
    #reminecraftpe-network
    #reminecraftpe-renderer
    reminecraftpe-world
    reminecraftpe-client
)
