add_library(reminecraftpe-input STATIC
    Controller.cpp Controller.hpp
    ControllerTurnInput.cpp ControllerTurnInput.hpp
    CustomInputHolder.cpp CustomInputHolder.hpp
    IBuildInput.cpp IBuildInput.hpp
    IInputHolder.cpp IInputHolder.hpp
    IMoveInput.cpp IMoveInput.hpp
    ITouchScreenModel.cpp ITouchScreenModel.hpp
    ITurnInput.cpp ITurnInput.hpp
    IncludeExcludeArea.cpp IncludeExcludeArea.hpp
    Keyboard.cpp Keyboard.hpp
    KeyboardInput.cpp KeyboardInput.hpp
    Mouse.cpp Mouse.hpp
    MouseDevice.cpp MouseDevice.hpp
    MouseHandler.cpp MouseHandler.hpp
    MouseTurnInput.cpp MouseTurnInput.hpp
    Multitouch.cpp Multitouch.hpp
    PolygonArea.cpp PolygonArea.hpp
    RectangleArea.cpp RectangleArea.hpp
    TouchAreaModel.cpp TouchAreaModel.hpp
    TouchInputHolder.cpp TouchInputHolder.hpp
    TouchscreenInput_TestFps.cpp TouchscreenInput_TestFps.hpp
    UnifiedTurnBuild.cpp UnifiedTurnBuild.hpp
)
target_link_libraries(reminecraftpe-input PRIVATE reminecraftpe-client)
