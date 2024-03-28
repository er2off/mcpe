add_library(Server STATIC
    Options.cpp Options.hpp
    Server.cpp Server.hpp
)
target_link_libraries(Server PRIVATE
    Common
    Network
    World
)
if (USE_SDL)
    target_link_libraries(Server PRIVATE SDL)
endif()
