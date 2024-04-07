# Common (low-level?) stuff

add_library(Common STATIC
    CThread.cpp CThread.hpp
    Logger.cpp Logger.hpp
    LongHack.hpp
    Matrix.cpp Matrix.hpp
    Mth.cpp Mth.hpp
    Random.cpp Random.hpp
    SmoothFloat.cpp SmoothFloat.hpp
    Timer.cpp Timer.hpp
    Util.cpp Util.hpp
    Utils.cpp Utils.hpp
    ../../GameMods.hpp
)

#target_link_libraries(Common PRIVATE Renderer)

# zlib
if (WIN32)
    # Use vendored ZLib
    add_subdirectory(../../thirdparty/zlib zlib)
    target_link_libraries(Common PRIVATE zlib)
elseif (EMSCRIPTEN)
    # Use Emscripten's ZLib
    set(ZLIB_FLAG -sUSE_ZLIB=1)
    target_compile_options(Common PUBLIC "${ZLIB_FLAG}")
    target_link_options(Common PRIVATE "${ZLIB_FLAG}")
else()
    # Use System ZLib
    find_package(ZLIB REQUIRED)
    target_link_libraries(Common PRIVATE ZLIB::ZLIB)
endif()
if (ANDROID)
    target_link_libraries(Common PRIVATE log)
endif()
