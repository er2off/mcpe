# SDL Build

# WASM
if(EMSCRIPTEN)
    function(add_compile_and_link_options)
        add_compile_options(${ARGV})
        add_link_options(${ARGV})
    endfunction()
    set(CMAKE_EXECUTABLE_SUFFIX ".js")
    add_link_options("$<$<CONFIG:DEBUG>:-gsource-map>")
endif()

# Clang
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wno-inconsistent-missing-override -Wno-enum-compare-switch -Wno-register)
endif()

# Network library
if(HAIKU)
    link_libraries(network)
endif()

# Threads
if(EMSCRIPTEN)
    add_compile_and_link_options(-pthread)
else()
    find_package(Threads)
    link_libraries(Threads::Threads)
endif()

# Build
set(SOURCES
    main.cpp
    base/AppPlatform_sdl_base.cpp base/AppPlatform_sdl_base.hpp
)
if(EMSCRIPTEN)
    list(APPEND SOURCES emscripten/AppPlatform_sdl.cpp emscripten/AppPlatform_sdl.hpp)
else()
    list(APPEND SOURCES desktop/AppPlatform_sdl.cpp desktop/AppPlatform_sdl.hpp)
endif()
add_executable(reminecraftpe ${SOURCES})

# OpenAL
add_subdirectory(../openal openal)

target_link_libraries(reminecraftpe
    reminecraftpe-core
    reminecraftpe-openal
)

# LibPNG (If Needed)
if(NOT EMSCRIPTEN)
    find_package(PNG REQUIRED)
    target_link_libraries(reminecraftpe PNG::PNG)
endif()

# SDL
add_library(SDL INTERFACE)
if(EMSCRIPTEN)
    set(SDL_FLAG -sUSE_SDL=2)
    target_compile_options(SDL INTERFACE "${SDL_FLAG}")
    target_link_options(SDL INTERFACE "${SDL_FLAG}")
else()
    find_package(SDL2 REQUIRED)
    target_link_libraries(SDL INTERFACE SDL2::SDL2)
endif()
target_link_libraries(reminecraftpe SDL)

if(TARGET SDL2::SDL2main)
    target_link_libraries(reminecraftpe SDL2::SDL2main)
endif()

# WASM
if(EMSCRIPTEN)
    target_link_options(reminecraftpe PRIVATE -Wno-pthreads-mem-growth)
    target_link_options(reminecraftpe PRIVATE -sALLOW_MEMORY_GROWTH=1)
    # Export Resize Function
    target_link_options(reminecraftpe PRIVATE -sEXPORTED_FUNCTIONS=_main,_resize_from_js -sEXPORTED_RUNTIME_METHODS=ccall)
endif()

# Assets
if(EMSCRIPTEN)
    target_link_options(reminecraftpe PRIVATE --use-preload-plugins --preload-file "${CMAKE_CURRENT_SOURCE_DIR}/../../game/assets@/assets")
else()
    file(CREATE_LINK "${CMAKE_CURRENT_SOURCE_DIR}/../../game/assets" "${CMAKE_CURRENT_BINARY_DIR}/assets" SYMBOLIC)
endif()
