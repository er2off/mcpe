cmake_minimum_required(VERSION 3.16.0)

# Use actual name as some IDEs can show them
project(ReMinecraftPE)

set(PLATFORM sdl2 CACHE STRING "Active platform")
set_property(CACHE PLATFORM PROPERTY STRINGS android macos sdl2 windows xenon)

message(STATUS "Current platform: ${PLATFORM}")
if (PLATFORM STREQUAL android)
    message(STATUS "Android library will be only built. For apk use gradle")
    # Set -fPIC
    set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)
    add_subdirectory(platforms/android/project/app/src/main/cpp)
elseif (PLATFORM STREQUAL macos)
    message(FATAL_ERROR "${PLATFORM} currently can't be built using cmake. Use XCode instead")
elseif (PLATFORM STREQUAL sdl2)
    set(USE_SDL 1)
    add_compile_definitions(USE_SDL USE_OPENAL HANDLE_CHARS_SEPARATELY)
    add_subdirectory(platforms/sdl)
elseif (PLATFORM STREQUAL windows
        OR PLATFORM STREQUAL xenon)
    message(FATAL_ERROR "${PLATFORM} currently can't be built using cmake. Use Visual Studio instead")
else()
    message(FATAL_ERROR "Unknown platform!")
endif()

# Sound Data
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/sound_data/sounds.h")
	if(NOT DEFINED ENV{CI})
		message(WARNING "Missing sound data! Did you run tools/grabsounds.py?")
	endif()
	target_compile_definitions(reminecraftpe-core PRIVATE MISSING_SOUND_DATA)
endif()

# Include source code tree
add_subdirectory(source)
