/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2024 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/
#include "RedStoneRepeaterTile.hpp"
#include "world/level/Level.hpp"

RedStoneRepeaterTile::RedStoneRepeaterTile(int id, int texture, Material* pMtl) : Tile(id, texture, pMtl)
{
	m_bActive = id == TILE_REPEATER_ON;
	m_delay = 0;

	setShape(0, 0, 0, 1, 0.125f, 1);
}

bool RedStoneRepeaterTile::isCubeShaped()
{
	return false;
}

bool RedStoneRepeaterTile::isSolidRender()
{
	return false;
}

bool RedStoneRepeaterTile::isSignalSource()
{
	return true;
}

int RedStoneRepeaterTile::getTickDelay()
{
	return 2; // 2 in game ticks per redstone tick
}

int RedStoneRepeaterTile::getRenderShape()
{
	return SHAPE_REPEATER;
}

int RedStoneRepeaterTile::getTexture(int dir, int data)
{
	switch (dir)
	{
	case DIR_YPOS:
		return m_TextureFrame;
	case DIR_YNEG:
		return TEXTURE_STONE_SLAB_TOP;
	}
	return m_TextureFrame;
}

void RedStoneRepeaterTile::onPlace(Level* level, int x, int y, int z)
{
	if (isActive())
		updateNeighbors(level, x, y, z, m_ID);
	m_delay = level->getData(x, y, z) >> 2;
}

void RedStoneRepeaterTile::onRemove(Level* level, int x, int y, int z)
{
	if (isActive())
		updateNeighbors(level, x, y, z, m_ID);
}

void RedStoneRepeaterTile::neighborChanged(Level* level, int x, int y, int z, int dir)
{
	Tile::neighborChanged(level, x, y, z, dir);
	level->addToTickNextTick(x, y, z, m_ID, getTickDelay() * (m_delay + 1));
}

int RedStoneRepeaterTile::getResource(int data, Random* random)
{
	return Tile::repeater_off->m_ID;
}

void RedStoneRepeaterTile::tick(Level* level, int x, int y, int z, Random* random)
{
	//if (level->m_bIsMultiplayer)
	//	return;

	if (hasSignalFromBehind(level, x, y, z))
		level->setTileAndData(x, y, z, Tile::repeater_on->m_ID, level->getData(x, y, z));
	else
		level->setTileAndData(x, y, z, Tile::repeater_off->m_ID, level->getData(x, y, z));
}

int RedStoneRepeaterTile::getDirectSignal(LevelSource* level, int x, int y, int z, int dir)
{
	return getSignal(level, x, y, z, dir);
}

int RedStoneRepeaterTile::getSignal(LevelSource* level, int x, int y, int z, int dir)
{
	if (!isActive()) return 0;
	int face = level->getData(x, y, z) & 3;
	switch (dir)
	{
	case DIR_ZNEG:
		return face == 1;
	case DIR_ZPOS:
		return face == 3;
	case DIR_XNEG:
		return face == 0;
	case DIR_XPOS:
		return face == 2;
	}
	return 0;
}

void RedStoneRepeaterTile::setPlacedBy(Level* level, int x, int y, int z, Mob* mob)
{
	int data = level->getData(x, y, z);

	data &= 0xC; // 0b1100
	if (data == 0)
		data |= m_delay << 2;

	data |= mob->getDirection();

	level->setData(x, y, z, data);
}

int RedStoneRepeaterTile::use(Level* level, int x, int y, int z, Player* player)
{
	m_delay = (m_delay + 1) % 3;
	level->setData(x, y, z, (level->getData(x, y, z) & 3) | (m_delay << 2));
	return 1;
}

void RedStoneRepeaterTile::updateNeighbors(Level* level, int x, int y, int z, int id)
{
	level->updateNeighborsAt(x - 1, y, z, id);
	level->updateNeighborsAt(x + 1, y, z, id);
	level->updateNeighborsAt(x, y, z - 1, id);
	level->updateNeighborsAt(x, y, z + 1, id);
}

bool RedStoneRepeaterTile::hasSignalFromBehind(Level* level, int x, int y, int z)
{
	int data = level->getData(x, y, z) & 3;
	if (data == 0 && level->getSignal(x - 1, y, z, DIR_XPOS)) return true;
	if (data == 2 && level->getSignal(x + 1, y, z, DIR_XNEG)) return true;
	if (data == 1 && level->getSignal(x, y, z - 1, DIR_ZPOS)) return true;
	if (data == 3 && level->getSignal(x, y, z + 1, DIR_ZNEG)) return true;
	return false;
}

void RedStoneRepeaterTile::animateTick(Level* level, int x, int y, int z, Random* random)
{
	float partX = float(x) + 0.5f, partZ = float(z) + 0.5f, partY = float(y) + 0.7f;

	// @NOTE: Need to use addParticle("reddust") 5 times. Invalid data values don't actually generate a smoke
	switch (level->getData(x, y, z) & 3)
	{
	case 0:
		partX -= 0.27f;
		partY += 0.22f;
		level->addParticle("reddust", partX, partY, partZ, 0.0f, 0.0f, 0.0f);
		break;
	case 1:
		partX += 0.27f;
		partY += 0.22f;
		level->addParticle("reddust", partX, partY, partZ, 0.0f, 0.0f, 0.0f);
		break;
	case 2:
		partZ -= 0.27f;
		partY += 0.22f;
		level->addParticle("reddust", partX, partY, partZ, 0.0f, 0.0f, 0.0f);
		break;
	case 3:
		partZ += 0.27f;
		partY += 0.22f;
		level->addParticle("reddust", partX, partY, partZ, 0.0f, 0.0f, 0.0f);
		break;
	}
}
