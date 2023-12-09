add_library(reminecraftpe-gui STATIC
    Drawer.cpp Drawer.hpp
    Gui.cpp Gui.hpp
    Screen.cpp Screen.hpp
    controls/Button.cpp controls/Button.hpp
    controls/IControl.hpp
    screens/MainScreen.cpp screens/MainScreen.hpp
)
target_link_libraries(reminecraftpe-gui PUBLIC reminecraftpe-common reminecraftpe-client)
