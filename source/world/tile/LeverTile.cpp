/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#include "LeverTile.hpp"
#include "world/level/Level.hpp"

LeverTile::LeverTile(int id, int texture, Material* pMtl) : Tile(id, texture, pMtl)
{
}

AABB* LeverTile::getAABB(Level*, int x, int y, int z)
{
	return nullptr;
}

bool LeverTile::isSolidRender()
{
	return false;
}

bool LeverTile::isCubeShaped()
{
	return false;
}

int LeverTile::getRenderShape()
{
	return SHAPE_LEVER;
}

HitResult LeverTile::clip(Level* level, int x, int y, int z, Vec3 a, Vec3 b)
{
	switch (level->getData(x, y, z) & 7)
	{
		case 1:
			setShape(0.0f, 0.2f, 0.35f, 0.3f, 0.8f, 0.65f);
			break;
		case 2:
			setShape(0.7f, 0.2f, 0.35f, 1.0f, 0.8f, 0.65f);
			break;
		case 3:
			setShape(0.35f, 0.2f, 0.0f, 0.65f, 0.8f, 0.3f);
			break;
		case 4:
			setShape(0.35f, 0.2f, 0.7f, 0.65f, 0.8f, 1.0f);
			break;
		default:
			setShape(0.4f, 0.0f, 0.4f, 0.6f, 0.6f, 0.6f);
			break;
	}

	return Tile::clip(level, x, y, z, a, b);
}

bool LeverTile::mayPlace(Level* level, int x, int y, int z)
{
	if (level->isSolidTile(x, y - 1, z)) return true;
	if (level->isSolidTile(x - 1, y, z)) return true;
	if (level->isSolidTile(x + 1, y, z)) return true;
	if (level->isSolidTile(x, y, z - 1)) return true;
	if (level->isSolidTile(x, y, z + 1)) return true;

	return false;
}

bool LeverTile::checkCanSurvive(Level* level, int x, int y, int z)
{
	if (mayPlace(level, x, y, z))
		return true;

	spawnResources(level, x, y, z, 0);
	level->setTile(x, y, z, TILE_AIR);

	return false;
}

void LeverTile::neighborChanged(Level* level, int x, int y, int z, int dir)
{
	if (!checkCanSurvive(level, x, y, z))
		return;

	int data = level->getData(x, y, z);
	data &= 7;

	bool flag = false;
	if (!level->isSolidTile(x - 1, y, z) && data == 1) flag = true;
	if (!level->isSolidTile(x + 1, y, z) && data == 2) flag = true;
	if (!level->isSolidTile(x, y, z - 1) && data == 3) flag = true;
	if (!level->isSolidTile(x, y, z + 1) && data == 4) flag = true;
	if (!level->isSolidTile(x, y - 1, z) && data == 5) flag = true;

	if (!flag)
		return; // all good

	spawnResources(level, x, y, z, 0);
	level->setTile(x, y, z, TILE_AIR);
}

void LeverTile::onPlace(Level* level, int x, int y, int z)
{
	if (level->isSolidTile(x - 1, y, z))
		level->setData(x, y, z, 1);
	else if (level->isSolidTile(x + 1, y, z))
		level->setData(x, y, z, 2);
	else if (level->isSolidTile(x, y, z - 1))
		level->setData(x, y, z, 3);
	else if (level->isSolidTile(x, y, z + 1))
		level->setData(x, y, z, 4);
	else if (level->isSolidTile(x, y - 1, z))
		level->setData(x, y, z, 5);

	checkCanSurvive(level, x, y, z);
	updateNeighbors(level, x, y, z, m_ID);
}

void LeverTile::onRemove(Level* level, int x, int y, int z)
{
	updateNeighbors(level, x, y, z, m_ID);
}

int LeverTile::use(Level* level, int x, int y, int z, Player* player)
{
	int data = level->getData(x, y, z);
	// toggling
	data ^= 8;
	level->setData(x, y, z, data);
	level->playSound(float(x) + 0.5f, float(y) + 0.5f, float(z) + 0.5f, "random.explode", 1.0f, 0.9f + 0.1f * level->m_random.nextFloat());
	updateNeighbors(level, x, y, z, m_ID);

	return 1;
}

bool LeverTile::isSignalSource()
{
	return true;
}

int LeverTile::getTickDelay()
{
	return 2; // 2 in game ticks per redstone tick
}

int LeverTile::getSignal(LevelSource* level, int x, int y, int z, int dir)
{
	//if (dir == DIR_YNEG)
		return getDirectSignal(level, x, y, z, dir);

	return 0;
}

int LeverTile::getDirectSignal(LevelSource* level, int x, int y, int z, int dir)
{
	int data = level->getData(x, y, z);
	if ((data & 8) == 0)
		return 0;
	data &= 7;

	// check for the sides _behind_ the torch
	//if (data == 5 && dir == DIR_YPOS) return 0;
	//if (data == 3 && dir == DIR_ZPOS) return 0;
	//if (data == 4 && dir == DIR_ZNEG) return 0;
	//if (data == 1 && dir == DIR_XPOS) return 0;
	//if (data == 2 && dir == DIR_XNEG) return 0;

	return 1;
}

void LeverTile::updateNeighbors(Level* level, int x, int y, int z, int id)
{
	level->updateNeighborsAt(x, y - 1, z, id);
	level->updateNeighborsAt(x, y + 1, z, id);
	level->updateNeighborsAt(x - 1, y, z, id);
	level->updateNeighborsAt(x + 1, y, z, id);
	level->updateNeighborsAt(x, y, z - 1, id);
	level->updateNeighborsAt(x, y, z + 1, id);

	level->updateNeighborsAt(x - 1, level->isSolidTile(x - 1, y, z) ? y + 1 : y - 1, z, id);
	level->updateNeighborsAt(x + 1, level->isSolidTile(x + 1, y, z) ? y + 1 : y - 1, z, id);
	level->updateNeighborsAt(x, level->isSolidTile(x - 1, y, z) ? y + 1 : y - 1, z - 1, id);
	level->updateNeighborsAt(x, level->isSolidTile(x + 1, y, z) ? y + 1 : y - 1, z + 1, id);
}

