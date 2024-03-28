add_library(Renderer STATIC)

if (render STREQUAL gl)
    # OpenGL
    set(USE_GL 1)
    target_sources(Renderer PRIVATE GL/GL.cpp GL/GL.hpp)
elseif (render STREQUAL gles)
    # OpenGL ES
    # nothing?
    target_sources(Renderer PRIVATE GL/GL.cpp GL/GL.hpp)
else()
    message(FATAL_ERROR "Unknown renderer!")
endif()

#target_include_directories(Renderer PUBLIC .)
target_include_directories(Renderer PRIVATE ../..)

# Find OpenGL library
if(USE_GLES1_COMPATIBILITY_LAYER)
    message(STATUS "GLESv1 compatibility layer")
    set(GLES_COMPATIBILITY_LAYER_USE_SDL TRUE CACHE BOOL "" FORCE)
    set(GLES_COMPATIBILITY_LAYER_DEPENDENCY SDL CACHE STRING "" FORCE)
    #set(GLES_COMPATIBILITY_LAYER_USE_ES3 FALSE CACHE BOOL "" FORCE)
    add_subdirectory(../../thirdparty/gles-compatibility-layer gles-compatibility-layer)
    target_link_libraries(Renderer PUBLIC gles-compatibility-layer)
    target_compile_definitions(Renderer PUBLIC USE_GLES1_COMPATIBILITY_LAYER)
    if(EMSCRIPTEN)
        # Use WebGL 2
	target_link_options(Renderer PUBLIC -sMIN_WEBGL_VERSION=2 -sMAX_WEBGL_VERSION=2)
    endif()
elseif(WIN32)
    message(STATUS "Windows's opengl32")
    target_link_libraries(Renderer PUBLIC opengl32 glu32)
    target_sources(Renderer PRIVATE ../../thirdparty/GL/GLExt.cpp)
else()
    message(STATUS "System OpenGL")
    find_package(OpenGL REQUIRED)
    target_link_libraries(Renderer PUBLIC OpenGL::OpenGL)
endif()
if (platform STREQUAL sdl)
    target_link_libraries(Renderer PUBLIC SDL)
endif()
