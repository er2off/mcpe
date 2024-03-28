# SDL Build

# Clang
#if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#    add_compile_options(-Wno-inconsistent-missing-override -Wno-enum-compare-switch -Wno-register)
#endif()

# Network library
if (HAIKU)
    link_libraries(network)
endif()

# Build
set(SOURCES
    main.cpp
    base/AppPlatform_sdl_base.cpp base/AppPlatform_sdl_base.hpp
)
if (EMSCRIPTEN)
    list(APPEND SOURCES emscripten/AppPlatform_sdl.cpp emscripten/AppPlatform_sdl.hpp)
else()
    list(APPEND SOURCES desktop/AppPlatform_sdl.cpp desktop/AppPlatform_sdl.hpp)
endif()
if (ANDROID)
    add_library(reminecraftpe SHARED ${SOURCES})
    set_target_properties(reminecraftpe PROPERTIES OUTPUT_NAME main)
else()
    add_executable(reminecraftpe ${SOURCES})
endif()

# OpenAL
add_subdirectory(../openal openal)
target_link_libraries(reminecraftpe reminecraftpe-openal)

# stb_image (If Needed)
if (NOT EMSCRIPTEN)
    add_subdirectory(../../thirdparty/stb_image stb_image)
    target_link_libraries(reminecraftpe stb_image)
endif()

target_link_libraries(reminecraftpe
    Core
    SDL
)

message(STATUS "Find dependencies")
## SDL2
if(ANDROID OR WIN32)
    message(STATUS "Vendored SDL2 (only for Android and Windows)")
    set(SDL_OPENGL TRUE CACHE BOOL "" FORCE)
    #set(SDL_OPENGLES TRUE CACHE BOOL "" FORCE)
    add_subdirectory(../../thirdparty/SDL2/src SDL EXCLUDE_FROM_ALL)
    target_link_libraries(SDL INTERFACE SDL2::SDL2)
elseif(EMSCRIPTEN)
    message(STATUS "Emscripten's SDL2")
    set(SDL_FLAG -sUSE_SDL=2)
    target_compile_options(SDL "${SDL_FLAG}")
    target_link_options(SDL "${SDL_FLAG}")
else()
    message(STATUS "System SDL2")
    find_package(SDL2 REQUIRED)
    target_link_libraries(SDL INTERFACE SDL2::SDL2)
endif()

if (TARGET SDL2::SDL2main)
    target_link_libraries(reminecraftpe SDL2::SDL2main)
endif()

# WASM
if (EMSCRIPTEN)
    target_link_options(reminecraftpe PRIVATE -Wno-pthreads-mem-growth)
    target_link_options(reminecraftpe PRIVATE -sALLOW_MEMORY_GROWTH=1)
    # Export Resize Function
    target_link_options(reminecraftpe PRIVATE -sEXPORTED_FUNCTIONS=_main,_resize_from_js -sEXPORTED_RUNTIME_METHODS=ccall)
    target_link_options(reminecraftpe PRIVATE --use-preload-plugins --preload-file "${CMAKE_CURRENT_SOURCE_DIR}/../../game@/")
endif()
