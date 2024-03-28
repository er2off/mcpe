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
project(ReMinecraftPE LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

set(PLATFORMS android sdl windows server)
set(RENDERERS gl gles)

if (ANDROID)
    set(_DEFAULT_PLAT android)
    set(_DEFAULT_RENDER gles)
elseif (WIN32)
    set(_DEFAULT_PLAT windows)
    set(_DEFAULT_RENDER gl) # TODO: DirectX
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
elseif (platform STREQUAL macos)
    message(FATAL_ERROR "${PLATFORM} currently can't be built using cmake. Use XCode instead")
elseif (platform STREQUAL sdl)
    set(USE_SDL 1)
    add_compile_definitions(USE_SDL)
#elseif (platform STREQUAL server)
#    set(BUILD_SERVER 1)
#    add_compile_definitions(SERVER)
endif()

if(WIN32)
       set(USE_GLES1_COMPATIBILITY_LAYER FALSE CACHE BOOL "" FORCE)
elseif(NOT EMSCRIPTEN AND NOT ANDROID)
    option(USE_GLES1_COMPATIBILITY_LAYER "Whether To Enable The GLESv1_CM Compatibility Layer" TRUE)
else()
    set(USE_GLES1_COMPATIBILITY_LAYER TRUE CACHE BOOL "" FORCE)
endif()
if(USE_GLES1_COMPATIBILITY_LAYER OR platform STREQUAL sdl)
    # Prepare SDL library
    add_library(SDL INTERFACE)
    if (NOT platform STREQUAL sdl)
        message(FATAL_ERROR "GLESv1 compatibility layer can't be currently used without sdl2")
    endif()
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/app")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

# WASM
if (EMSCRIPTEN)
    function(add_compile_and_link_options)
        add_compile_options(${ARGV})
        add_link_options(${ARGV})
    endfunction()
    set(CMAKE_EXECUTABLE_SUFFIX ".js")
    add_link_options("$<$<CONFIG:DEBUG>:-gsource-map>")
endif()

# Threads
if (EMSCRIPTEN)
    add_compile_and_link_options(-pthread)
elseif (WIN32)
    # using winapi so no pthread
else()
    find_package(Threads)
    link_libraries(Threads::Threads)
endif()

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
