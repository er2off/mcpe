/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once

#include "Mob.hpp"
#include "client/model/PigModel.hpp"

class Level;
class Player;
class PigModel;

class Pig : public Mob
{
public:
	Pig(Level*, float, float, float);

	Model *getModel();

private:
	PigModel m_model = PigModel(0.0f, 0.0f);
};

