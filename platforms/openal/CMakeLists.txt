cmake_minimum_required(VERSION 3.16.0)
project(reminecraftpe-openal)

# Build
add_library(reminecraftpe-openal STATIC
	SoundSystemAL.cpp
)

# Core
target_link_libraries(reminecraftpe-openal PUBLIC reminecraftpe-core)

# OpenAL
if(EMSCRIPTEN)
    target_link_libraries(reminecraftpe-openal PUBLIC openal)
else()
    find_package(OpenAL REQUIRED)
    target_link_libraries(reminecraftpe-openal PUBLIC OpenAL::OpenAL)
endif()

# Headers
target_include_directories(reminecraftpe-openal PUBLIC .)
