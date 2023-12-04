add_library(reminecraftpe-client STATIC
    app/App.cpp app/App.hpp
    app/AppPlatform.cpp app/AppPlatform.hpp
    app/Minecraft.cpp app/Minecraft.hpp
    app/NinecraftApp.cpp app/NinecraftApp.hpp
    model/Cube.cpp model/Cube.hpp
    model/HumanoidModel.cpp model/HumanoidModel.hpp
    model/Model.cpp model/Model.hpp
    model/PigModel.cpp model/PigModel.hpp
    model/PolygonQuad.cpp model/PolygonQuad.hpp
    network/ClientSideNetworkHandler.cpp network/ClientSideNetworkHandler.hpp
    options/Options.cpp options/Options.hpp
    player/LocalPlayer.cpp player/LocalPlayer.hpp
    player/input/Controller.cpp player/input/Controller.hpp
    player/input/ControllerTurnInput.cpp player/input/ControllerTurnInput.hpp
    player/input/CustomInputHolder.cpp player/input/CustomInputHolder.hpp
    player/input/IBuildInput.cpp player/input/IBuildInput.hpp
    player/input/IInputHolder.cpp player/input/IInputHolder.hpp
    player/input/IMoveInput.cpp player/input/IMoveInput.hpp
    player/input/ITouchScreenModel.cpp player/input/ITouchScreenModel.hpp
    player/input/ITurnInput.cpp player/input/ITurnInput.hpp
    player/input/IncludeExcludeArea.cpp player/input/IncludeExcludeArea.hpp
    player/input/Keyboard.cpp player/input/Keyboard.hpp
    player/input/KeyboardInput.cpp player/input/KeyboardInput.hpp
    player/input/Mouse.cpp player/input/Mouse.hpp
    player/input/MouseDevice.cpp player/input/MouseDevice.hpp
    player/input/MouseHandler.cpp player/input/MouseHandler.hpp
    player/input/MouseTurnInput.cpp player/input/MouseTurnInput.hpp
    player/input/Multitouch.cpp player/input/Multitouch.hpp
    player/input/PolygonArea.cpp player/input/PolygonArea.hpp
    player/input/RectangleArea.cpp player/input/RectangleArea.hpp
    player/input/TouchAreaModel.cpp player/input/TouchAreaModel.hpp
    player/input/TouchInputHolder.cpp player/input/TouchInputHolder.hpp
    player/input/TouchscreenInput_TestFps.cpp player/input/TouchscreenInput_TestFps.hpp
    player/input/UnifiedTurnBuild.cpp player/input/UnifiedTurnBuild.hpp
    renderer/Chunk.cpp renderer/Chunk.hpp
    renderer/Culler.cpp renderer/Culler.hpp
    renderer/DynamicTexture.cpp renderer/DynamicTexture.hpp
    renderer/FireTexture.cpp
    renderer/FoliageColor.cpp renderer/FoliageColor.hpp
    renderer/Font.cpp renderer/Font.hpp
    renderer/Frustum.cpp renderer/Frustum.hpp
    renderer/FrustumCuller.cpp renderer/FrustumCuller.hpp
    renderer/GameRenderer.cpp renderer/GameRenderer.hpp
    renderer/GrassColor.cpp renderer/GrassColor.hpp
    renderer/ItemInHandRenderer.cpp renderer/ItemInHandRenderer.hpp
    renderer/LavaSideTexture.cpp
    renderer/LavaTexture.cpp
    renderer/LevelRenderer.cpp renderer/LevelRenderer.hpp
    renderer/LightLayer.cpp renderer/LightLayer.hpp
    renderer/LightUpdate.cpp renderer/LightUpdate.hpp
    renderer/Matrix.cpp renderer/Matrix.hpp
    renderer/PatchManager.cpp renderer/PatchManager.hpp
    renderer/RenderChunk.cpp renderer/RenderChunk.hpp
    renderer/RenderList.cpp renderer/RenderList.hpp
    renderer/Tesselator.cpp renderer/Tesselator.hpp
    renderer/Textures.cpp renderer/Textures.hpp
    renderer/TileRenderer.cpp renderer/TileRenderer.hpp
    renderer/WaterSideTexture.cpp
    renderer/WaterTexture.cpp
    renderer/entity/EntityRenderDispatcher.cpp renderer/entity/EntityRenderDispatcher.hpp
    renderer/entity/EntityRenderer.cpp renderer/entity/EntityRenderer.hpp
    renderer/entity/FallingTileRenderer.cpp renderer/entity/FallingTileRenderer.hpp
    renderer/entity/HumanoidMobRenderer.cpp renderer/entity/HumanoidMobRenderer.hpp
    renderer/entity/ItemRenderer.cpp renderer/entity/ItemRenderer.hpp
    renderer/entity/ItemSpriteRenderer.cpp renderer/entity/ItemSpriteRenderer.hpp
    renderer/entity/MobRenderer.cpp renderer/entity/MobRenderer.hpp
    renderer/entity/TntRenderer.cpp renderer/entity/TntRenderer.hpp
    renderer/entity/TripodCameraRenderer.cpp renderer/entity/TripodCameraRenderer.hpp
    sound/SoundData.cpp sound/SoundData.hpp
    sound/SoundEngine.cpp sound/SoundEngine.hpp
    sound/SoundRepository.cpp sound/SoundRepository.hpp
    sound/SoundSystem.cpp sound/SoundSystem.hpp
)
add_subdirectory(gui)
#add_subdirectory(player/input)

#add_library(reminecraftpe-client INTERFACE)
target_link_libraries(reminecraftpe-client PUBLIC
    reminecraftpe-gui
    reminecraftpe-renderer
    #reminecraftpe-network
    #reminecraftpe-input
)
