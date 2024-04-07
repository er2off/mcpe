/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once

#include "Tile.hpp"

class LeverTile : public Tile
{
public:
	LeverTile(int id, int texture, Material* pMtl);

	virtual AABB* getAABB(Level*, int x, int y, int z) override;
	virtual bool isSolidRender() override;
	virtual bool isCubeShaped() override;
	virtual int getRenderShape() override;
	virtual HitResult clip(Level*, int x, int y, int z, Vec3 a, Vec3 b) override;
	virtual bool mayPlace(Level*, int, int, int) override;
	virtual void neighborChanged(Level*, int, int, int, int) override;
	int use(Level*, int x, int y, int z, Player*) override;
	//virtual void setPlacedOnFace(Level*, int, int, int, int) override;
	//virtual void tick(Level*, int, int, int, Random*) override;

	bool checkCanSurvive(Level*, int, int, int);

	bool isSignalSource() override;
	int getTickDelay() override;
	void onPlace(Level*, int x, int y, int z) override;
	void onRemove(Level*, int x, int y, int z) override;
	//int getResource(int data, Random* random) override;
	int getSignal(LevelSource*, int x, int y, int z, int dir) override;
	int getDirectSignal(LevelSource*, int x, int y, int z, int dir) override;

	void updateNeighbors(Level*, int x, int y, int z, int id);
};
