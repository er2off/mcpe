add_library(reminecraftpe-network
    MinecraftPackets.cpp MinecraftPackets.hpp
    NetEventCallback.cpp NetEventCallback.hpp
    Packet.hpp
    PingedCompatibleServer.hpp
    RakNetInstance.cpp RakNetInstance.hpp
    ServerSideNetworkHandler.cpp ServerSideNetworkHandler.hpp
    packets/AddPlayerPacket.cpp
    packets/ChunkDataPacket.cpp
    packets/LevelDataPacket.cpp
    packets/LoginPacket.cpp
    packets/MessagePacket.cpp
    packets/MovePlayerPacket.cpp
    packets/PlaceBlockPacket.cpp
    packets/PlayerEquipmentPacket.cpp
    packets/RemoveBlockPacket.cpp
    packets/RemoveEntityPacket.cpp
    packets/RequestChunkPacket.cpp
    packets/StartGamePacket.cpp
    packets/UpdateBlockPacket.cpp
)
# RakNet
add_subdirectory(../../thirdparty/raknet raknet)
target_link_libraries(reminecraftpe-network PUBLIC raknet)
target_link_libraries(reminecraftpe-network PRIVATE reminecraftpe-renderer)
