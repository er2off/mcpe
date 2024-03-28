/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp
	
	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once

#include "thirdparty/raknet/RakNetTypes.h"
#include "Packet.hpp"
class Packet;
class LoginPacket;
class MessagePacket;
class StartGamePacket;
class AddPlayerPacket;
class RemoveEntityPacket;
class MovePlayerPacket;
class PlaceBlockPacket;
class RemoveBlockPacket;
class UpdateBlockPacket;
class RequestChunkPacket;
class ChunkDataPacket;
class PlayerEquipmentPacket;
class LevelDataPacket;
#include "world/level/Level.hpp"
class LocalPlayer;
class Level;
class LevelChunk;

class NetEventCallback
{
public:
	virtual ~NetEventCallback() {}
	virtual void levelGenerated(Level*, LocalPlayer*);
	virtual void onConnect(const RakNet::RakNetGUID&);
	virtual void onUnableToConnect();
	virtual void onNewClient(const RakNet::RakNetGUID&);
	virtual void onDisconnect(const RakNet::RakNetGUID&);
	virtual void handle(const RakNet::RakNetGUID&, LoginPacket*);
	virtual void handle(const RakNet::RakNetGUID&, MessagePacket*);
	virtual void handle(const RakNet::RakNetGUID&, StartGamePacket*);
	virtual void handle(const RakNet::RakNetGUID&, AddPlayerPacket*);
	virtual void handle(const RakNet::RakNetGUID&, RemoveEntityPacket*);
	virtual void handle(const RakNet::RakNetGUID&, MovePlayerPacket*);
	virtual void handle(const RakNet::RakNetGUID&, PlaceBlockPacket*);
	virtual void handle(const RakNet::RakNetGUID&, RemoveBlockPacket*);
	virtual void handle(const RakNet::RakNetGUID&, UpdateBlockPacket*);
	virtual void handle(const RakNet::RakNetGUID&, RequestChunkPacket*);
	virtual void handle(const RakNet::RakNetGUID&, ChunkDataPacket*);
	virtual void handle(const RakNet::RakNetGUID&, PlayerEquipmentPacket*);
	virtual void handle(const RakNet::RakNetGUID&, LevelDataPacket*);
};

