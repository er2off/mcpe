/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#include "Pig.hpp"
#include "world/level/Level.hpp"

Pig::Pig(Level* level, float x, float y, float z) : Mob(level)
{
	setSize(1.5f, 0.5f);
	field_84 = field_8C;

	setPos(x, y, z);
	field_3C.x = x;
	field_3C.y = y;
	field_3C.z = z;
}

Model *Pig::getModel()
{
	return &m_model;
}
