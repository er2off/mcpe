add_library(World STATIC
    entity/Animal.cpp entity/Animal.hpp
    entity/Entity.cpp entity/Entity.hpp
    entity/FallingTile.cpp entity/FallingTile.hpp
    entity/ItemEntity.cpp entity/ItemEntity.hpp
    entity/Mob.cpp entity/Mob.hpp
    entity/PathfinderMob.cpp entity/PathfinderMob.hpp
    entity/Pig.cpp entity/Pig.hpp
    entity/Player.cpp entity/Player.hpp
    entity/PrimedTnt.cpp entity/PrimedTnt.hpp
    entity/Rocket.cpp entity/Rocket.hpp
    entity/TripodCamera.cpp entity/TripodCamera.hpp
    item/CameraItem.cpp item/CameraItem.hpp
    item/DoorItem.cpp item/DoorItem.hpp
    item/Inventory.cpp item/Inventory.hpp
    item/Item.cpp item/Item.hpp
    item/ItemInstance.cpp item/ItemInstance.hpp
    item/RocketItem.cpp item/RocketItem.hpp
    item/TileItem.cpp item/TileItem.hpp
    item/TilePlanterItem.cpp item/TilePlanterItem.hpp
    level/Dimension.cpp level/Dimension.hpp
    level/Explosion.cpp level/Explosion.hpp
    level/Level.cpp level/Level.hpp
    level/LevelListener.cpp level/LevelListener.hpp
    level/LightLayer.cpp level/LightLayer.hpp
    level/LightUpdate.cpp level/LightUpdate.hpp
    level/Material.cpp level/Material.hpp
    level/Region.cpp level/Region.hpp
    level/TickNextTickData.cpp level/TickNextTickData.hpp
    level/levelgen/biome/Biome.cpp level/levelgen/biome/Biome.hpp
    level/levelgen/biome/BiomeSource.cpp level/levelgen/biome/BiomeSource.hpp
    level/levelgen/chunk/ChunkCache.cpp level/levelgen/chunk/ChunkCache.hpp
    level/levelgen/chunk/ChunkSource.cpp level/levelgen/chunk/ChunkSource.hpp
    level/levelgen/chunk/LevelChunk.cpp level/levelgen/chunk/LevelChunk.hpp
    level/levelgen/chunk/PerformanceTestChunkSource.cpp level/levelgen/chunk/PerformanceTestChunkSource.hpp
    level/levelgen/chunk/RandomLevelSource.cpp level/levelgen/chunk/RandomLevelSource.hpp
    level/levelgen/chunk/TestChunkSource.cpp level/levelgen/chunk/TestChunkSource.hpp
    level/levelgen/feature/BirchFeature.cpp
    level/levelgen/feature/ClayFeature.cpp
    level/levelgen/feature/Feature.cpp level/levelgen/feature/Feature.hpp
    level/levelgen/feature/FlowerFeature.cpp
    level/levelgen/feature/LargeCaveFeature.cpp
    level/levelgen/feature/LargeFeature.cpp
    level/levelgen/feature/OreFeature.cpp
    level/levelgen/feature/PineFeature.cpp
    level/levelgen/feature/ReedsFeature.cpp
    level/levelgen/feature/SpringFeature.cpp
    level/levelgen/feature/SpruceFeature.cpp
    level/levelgen/feature/TreeFeature.cpp
    level/levelgen/synth/ImprovedNoise.cpp level/levelgen/synth/ImprovedNoise.hpp
    level/levelgen/synth/PerlinNoise.cpp level/levelgen/synth/PerlinNoise.hpp
    level/levelgen/synth/Synth.cpp level/levelgen/synth/Synth.hpp
    level/path/BinaryHeap.cpp level/path/BinaryHeap.hpp
    level/path/Node.cpp level/path/Node.hpp
    level/path/Path.cpp level/path/Path.hpp
    level/path/PathFinder.cpp level/path/PathFinder.hpp
    level/storage/ChunkStorage.cpp level/storage/ChunkStorage.hpp
    level/storage/ExternalFileLevelStorage.cpp level/storage/ExternalFileLevelStorage.hpp
    level/storage/ExternalFileLevelStorageSource.cpp level/storage/ExternalFileLevelStorageSource.hpp
    level/storage/LevelData.cpp level/storage/LevelData.hpp
    level/storage/LevelSource.cpp level/storage/LevelSource.hpp
    level/storage/LevelStorage.cpp level/storage/LevelStorage.hpp
    level/storage/LevelStorageSource.cpp level/storage/LevelStorageSource.hpp
    level/storage/MemoryChunkStorage.cpp level/storage/MemoryChunkStorage.hpp
    level/storage/MemoryLevelStorage.cpp level/storage/MemoryLevelStorage.hpp
    level/storage/MemoryLevelStorageSource.cpp level/storage/MemoryLevelStorageSource.hpp
    level/storage/RegionFile.cpp level/storage/RegionFile.hpp
    phys/AABB.cpp phys/AABB.hpp
    phys/HitResult.cpp phys/HitResult.hpp
    phys/Vec3.cpp phys/Vec3.hpp
    tile/BookshelfTile.cpp tile/BookshelfTile.hpp
    tile/Bush.cpp tile/Bush.hpp
    tile/ClayTile.cpp tile/ClayTile.hpp
    tile/ClothTile.cpp tile/ClothTile.hpp
    tile/DirtTile.cpp tile/DirtTile.hpp
    tile/DoorTile.cpp tile/DoorTile.hpp
    tile/FarmTile.cpp tile/FarmTile.hpp
    tile/FireTile.cpp tile/FireTile.hpp
    tile/GlassTile.cpp tile/GlassTile.hpp
    tile/GrassTile.cpp tile/GrassTile.hpp
    tile/GravelTile.cpp tile/GravelTile.hpp
    tile/HalfTransparentTile.cpp tile/HalfTransparentTile.hpp
    tile/IceTile.cpp tile/IceTile.hpp
    tile/InvisibleTile.cpp tile/InvisibleTile.hpp
    tile/LadderTile.cpp tile/LadderTile.hpp
    tile/LeafTile.cpp tile/LeafTile.hpp
    tile/LeverTile.cpp tile/LeverTile.hpp
    tile/LiquidTile.cpp tile/LiquidTile.hpp
    tile/LiquidTileDynamic.cpp tile/LiquidTileDynamic.hpp
    tile/LiquidTileStatic.cpp tile/LiquidTileStatic.hpp
    tile/MetalTile.cpp tile/MetalTile.hpp
    tile/ObsidianTile.cpp tile/ObsidianTile.hpp
    tile/OreTile.cpp tile/OreTile.hpp
    tile/RedStoneOreTile.cpp tile/RedStoneOreTile.hpp
    tile/RedStoneRepeaterTile.cpp tile/RedStoneRepeaterTile.hpp
    tile/RedStoneTorchTile.cpp tile/RedStoneTorchTile.hpp
    tile/ReedTile.cpp tile/ReedTile.hpp
    tile/RocketLauncherTile.cpp tile/RocketLauncherTile.hpp
    tile/SandStoneTile.cpp tile/SandStoneTile.hpp
    tile/SandTile.cpp tile/SandTile.hpp
    tile/Sapling.cpp tile/Sapling.hpp
    tile/SpongeTile.cpp tile/SpongeTile.hpp
    tile/StairTile.cpp tile/StairTile.hpp
    tile/StoneSlabTile.cpp tile/StoneSlabTile.hpp
    tile/StoneTile.cpp tile/StoneTile.hpp
    tile/Tile.cpp tile/Tile.hpp
    tile/TntTile.cpp tile/TntTile.hpp
    tile/TopSnowTile.cpp tile/TopSnowTile.hpp
    tile/TorchTile.cpp tile/TorchTile.hpp
    tile/TorchUpdateEvent.hpp
    tile/TransparentTile.cpp tile/TransparentTile.hpp
    tile/TreeTile.cpp tile/TreeTile.hpp
    tile/WireTile.cpp tile/WireTile.hpp
)
if (NOT BUILD_SERVER)
    target_sources(World PRIVATE
        gamemode/CreativeMode.cpp gamemode/CreativeMode.hpp
        gamemode/GameMode.cpp gamemode/GameMode.hpp
        gamemode/SurvivalMode.cpp gamemode/SurvivalMode.hpp
        particle/BubbleParticle.cpp
        particle/ExplodeParticle.cpp
        particle/FlameParticle.cpp
        particle/LavaParticle.cpp
        particle/Particle.cpp particle/Particle.hpp
        particle/ParticleEngine.cpp particle/ParticleEngine.hpp
        particle/RedDustParticle.cpp
        particle/SmokeParticle.cpp
        particle/TerrainParticle.cpp
    )
    target_link_libraries(World PRIVATE Renderer)
endif()
target_link_libraries(World PUBLIC Common)
