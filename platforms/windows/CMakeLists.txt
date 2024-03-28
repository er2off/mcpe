# Windows Build

add_executable(ReMinecraftPE WIN32
    AppPlatform_win32.cpp AppPlatform_win32.hpp
    LoggerWin32.cpp LoggerWin32.hpp
    main.cpp
)

if (NOT WINDOWS_STORE)
    target_sources(ReMinecraftPE PRIVATE SoundSystemDS.cpp SoundSystemDS.hpp)
endif()

# stb_image
add_subdirectory(../../thirdparty/stb_image stb_image)
target_link_libraries(ReMinecraftPE stb_image)

target_link_libraries(ReMinecraftPE Core dsound dinput8 dxguid)
