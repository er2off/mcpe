# CMake build system
# (c) Er2 2024 <er2@dismail.de>
# Zlib License

cmake_minimum_required(VERSION 3.16)
if ("${CMAKE_CURRENT_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_BINARY_DIR}")
    message(FATAL_ERROR "Prevented in-tree build.\n"
        "Use cmake -S. -Bbuild instead."
    )
endif()

# Use actual name as some IDEs can show them
project(ReMinecraftPE LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 11)

set(PLATFORMS android sdl windows server)
set(RENDERERS gl gles)

if (ANDROID)
    set(_DEFAULT_PLAT android)
    set(_DEFAULT_RENDER gles)
elseif (WIN32)
    set(_DEFAULT_PLAT windows)
    set(_DEFAULT_RENDER gl) # TODO: DirectX
elseif (EMSCRIPTEN)
    set(_DEFAULT_PLAT sdl)
    set(_DEFAULT_RENDER gles)
else()
    set(_DEFAULT_PLAT sdl)
    set(_DEFAULT_RENDER gl)
endif()

set(platform ${_DEFAULT_PLAT} CACHE STRING "Active platform")
set(render ${_DEFAULT_RENDER} CACHE STRING "Active renderer")
set_property(CACHE platform PROPERTY STRINGS ${PLATFORMS})
set_property(CACHE render PROPERTY STRINGS ${RENDERERS})

message(STATUS "Active platform: ${platform}")
message(STATUS "Active renderer: ${render}")

if (ANDROID)
    message(STATUS "Android library will be only built. For apk use gradle")
elseif (EMSCRIPTEN)
    # Code should be built with -pthread to use pthread
    add_compile_options(-pthread)
    add_link_options(-pthread)
    set(CMAKE_EXECUTABLE_SUFFIX ".js")
    add_link_options("$<$<CONFIG:DEBUG>:-gsource-map>")
endif()
if (platform STREQUAL android)
    # set -fPIC
    set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)
    set(USE_NATIVE_ANDROID 1)
    add_compile_definitions(USE_NATIVE_ANDROID)
elseif (platform STREQUAL sdl)
    set(USE_SDL 1)
    add_compile_definitions(USE_SDL)
#elseif (platform STREQUAL server)
#    set(BUILD_SERVER 1)
#    add_compile_definitions(SERVER)
endif()

if (WIN32 OR ANDROID)
    set(USE_GLES1_COMPATIBILITY_LAYER FALSE CACHE BOOL "" FORCE)
elseif (platform STREQUAL gles)
    set(USE_GLES1_COMPATIBILITY_LAYER TRUE CACHE BOOL "" FORCE)
else()
    option(USE_GLES1_COMPATIBILITY_LAYER "Whether To Enable The GLESv1_CM Compatibility Layer" TRUE)
endif()
if (USE_GLES1_COMPATIBILITY_LAYER OR platform STREQUAL sdl)
    # Prepare SDL library
    add_library(SDL INTERFACE)
    if (NOT platform STREQUAL sdl)
        message(FATAL_ERROR "GLESv1 compatibility layer can't be currently used without sdl2")
    endif()
endif()

if (EMSCRIPTEN)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/wasm/dist")
    file(MAKE_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
    file(INSTALL "platforms/sdl/emscripten/wasm_shell.html" DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
    file(INSTALL "thirdparty/coi-serviceworker/coi-serviceworker.min.js" DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
else()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/app")
endif()
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

# Platforms
if ("${platform}" IN_LIST PLATFORMS)
    add_subdirectory(platforms/${platform})
else()
    message(FATAL_ERROR "Unknown platform!")
endif()

set_property(DIRECTORY "${CMAKE_SOURCE_DIR}" PROPERTY VS_STARTUP_PROJECT ReMinecraftPE)
set_target_properties(${APP_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/app")

# Include source code
add_subdirectory(source)
