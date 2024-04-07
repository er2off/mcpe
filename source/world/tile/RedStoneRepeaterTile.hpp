/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2024 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once

#include "Tile.hpp"

class RedStoneRepeaterTile : public Tile
{
public:
	RedStoneRepeaterTile(int id, int texture, Material* pMtl);

	bool isCubeShaped() override;
	bool isSolidRender() override;
	bool isSignalSource() override;
	int getTickDelay() override;
	int getRenderShape() override;
	int getTexture(int dir, int data) override;
	void onPlace(Level*, int x, int y, int z) override;
	void onRemove(Level*, int x, int y, int z) override;
	void neighborChanged(Level*, int x, int y, int z, int dir) override;
	int getResource(int data, Random* random) override;
	void tick(Level*, int, int, int, Random*) override;
	int getSignal(LevelSource*, int x, int y, int z, int dir) override;
	int getDirectSignal(LevelSource*, int x, int y, int z, int dir) override;
	void animateTick(Level* level, int x, int y, int z, Random* random) override;
	void setPlacedBy(Level* level, int x, int y, int z, Mob* mob) override;
	int use(Level* level, int x, int y, int z, Player* player) override;

	void updateNeighbors(Level*, int x, int y, int z, int id);
	bool hasSignalFromBehind(Level*, int x, int y, int z);

	bool isActive() {
		return m_bActive;
	}

private:
	bool m_bActive;
	int m_delay;
};
