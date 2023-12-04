# Common (low-level?) stuff

add_library(reminecraftpe-common STATIC
    Random.cpp Random.hpp
    Utils.cpp Utils.hpp
    Mth.cpp Mth.hpp
    Timer.cpp Timer.hpp
    CThread.cpp CThread.hpp
    Util.cpp Util.hpp
    Logger.cpp Logger.hpp
    SmoothFloat.cpp SmoothFloat.hpp
)

target_link_libraries(reminecraftpe-common PUBLIC
    reminecraftpe-network
)
#target_link_libraries(reminecraftpe-common PRIVATE
#    reminecraftpe-renderer
#)

# zlib - Android builds with its own version
# Hack - If we're not building for Android, surely we're building with SDL
if (USE_SDL)
    add_subdirectory(../../thirdparty/zlib zlib)
    target_link_libraries(reminecraftpe-common PUBLIC zlib)
elseif (NOT ANDROID)
    target_include_directories(reminecraftpe-common PRIVATE ../../thirdparty/zlib)
endif()
