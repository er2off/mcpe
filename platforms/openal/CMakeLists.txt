cmake_minimum_required(VERSION 3.16.0)
project(reminecraftpe-openal)

# Build
add_library(reminecraftpe-openal STATIC
    SoundSystemAL.cpp SoundSystemAL.hpp
)

target_compile_definitions(reminecraftpe-openal PUBLIC USE_OPENAL)

# Core
target_link_libraries(reminecraftpe-openal PUBLIC Core)

# OpenAL
if (ANDROID)
    # Use vendored OpenAL
    set(ALSOFT_UTILS FALSE CACHE BOOL "" FORCE)
    set(ALSOFT_EXAMPLES FALSE CACHE BOOL "" FORCE)
    set(ALSOFT_TESTS FALSE CACHE BOOL "" FORCE)
    set(ALSOFT_REQUIRE_OPENSL TRUE CACHE BOOL "" FORCE)
    add_subdirectory(../../thirdparty/OpenAL openal EXCLUDE_FROM_ALL)
    target_link_libraries(reminecraftpe-openal PUBLIC OpenAL::OpenAL)
elseif (WIN32)
    # Use vendored OpenAL
    set(ALSOFT_UTILS FALSE CACHE BOOL "" FORCE)
    set(ALSOFT_EXAMPLES FALSE CACHE BOOL "" FORCE)
    set(ALSOFT_TESTS FALSE CACHE BOOL "" FORCE)
    # WHY they are enabled for even not win32?
    set(ALSOFT_BACKEND_PIPEWIRE FALSE CACHE BOOL "" FORCE)
    set(ALSOFT_BACKEND_PULSEAUDIO FALSE CACHE BOOL "" FORCE)
    add_subdirectory(../../thirdparty/OpenAL openal EXCLUDE_FROM_ALL)
    target_link_libraries(reminecraftpe-openal PUBLIC OpenAL::OpenAL)
elseif(EMSCRIPTEN)
    # Use Emscripten's OpenAL
    target_link_libraries(reminecraftpe-openal PUBLIC openal)
else()
    # Use System OpenAL
    find_package(OpenAL REQUIRED)
    target_link_libraries(reminecraftpe-openal PUBLIC OpenAL::OpenAL)
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND (ANDROID OR WIN32))
    target_compile_options(OpenAL PRIVATE -Wno-ignored-attributes -Wno-sign-conversion -Wno-unused-function)
endif()

# Headers
target_include_directories(reminecraftpe-openal PUBLIC .)
