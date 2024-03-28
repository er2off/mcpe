SET(MC_ROOT ../..)

# Native Android Build
add_compile_definitions(USE_NATIVE_ANDROID)
set(USE_NATIVE_ANDROID TRUE)

add_library(reminecraftpe SHARED
    AppPlatform_android.cpp
    SoundSystemSL.cpp
    android_native_app_glue.c
    main.cpp
)

# Check for the presence of some optional asset based features.
if(EXISTS "${MC_ROOT}/game/assets/gui/background/panorama_0.png")
    target_compile_definitions(reminecraftpe PUBLIC FEATURE_MENU_BACKGROUND)
endif()

if(EXISTS "${MC_ROOT}/game/assets/environment/clouds.png")
    target_compile_definitions(reminecraftpe PUBLIC FEATURE_CLOUDS)
endif()

if(EXISTS "${MC_ROOT}/game/assets/misc/grasscolor.png")
    target_compile_definitions(reminecraftpe PUBLIC FEATURE_GRASS_COLOR)
endif()

if(EXISTS "${MC_ROOT}/game/assets/misc/foliagecolor.png")
    target_compile_definitions(reminecraftpe PUBLIC FEATURE_FOLIAGE_COLOR)
endif()

# Add the core as part of the library
target_link_libraries(reminecraftpe Core)

# stb_image
add_subdirectory(${MC_ROOT}/thirdparty/stb_image stb_image)
target_link_libraries(reminecraftpe stb_image)

# Extra Dependencies
target_link_libraries(reminecraftpe android OpenSLES)
