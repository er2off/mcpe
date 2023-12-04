# Build
add_library(reminecraftpe-openal STATIC
    SoundSystemAL.cpp SoundSystemAL.hpp
)

target_link_libraries(reminecraftpe-openal PUBLIC reminecraftpe-client)

# OpenAL
if(EMSCRIPTEN)
    target_link_libraries(reminecraftpe-openal PUBLIC openal)
else()
    find_package(OpenAL REQUIRED)
    target_link_libraries(reminecraftpe-openal PUBLIC OpenAL::OpenAL)
endif()

# Headers
target_include_directories(reminecraftpe-openal PUBLIC .)
target_include_directories(reminecraftpe-openal PRIVATE ../../source)
