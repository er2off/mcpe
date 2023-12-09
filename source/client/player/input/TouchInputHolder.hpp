/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once

#include "client/app/Minecraft.hpp"
#include "IInputHolder.hpp"
#include "TouchscreenInput_TestFps.hpp"
#include "UnifiedTurnBuild.hpp"

class Minecraft;
class Options;

static inline RectangleArea getRectangleArea(IGui *gui, bool b)
{
	float centerX = Minecraft::width / 2;
	float hotbarWidthHalf = (10 * gui->getNumSlots() + 5) / gui->scale;
	return RectangleArea(
		b ? (centerX - hotbarWidthHalf) : 0,
		Minecraft::height - 24.0f / gui->scale,
		centerX + hotbarWidthHalf,
		Minecraft::height);
}

class TouchInputHolder : public IInputHolder
{
public:
	TouchInputHolder(Minecraft*, Options*);
	bool allowPicking() override;
	IMoveInput* getMoveInput() override;
	ITurnInput* getTurnInput() override;
	IBuildInput* getBuildInput() override;
	void setScreenSize(int width, int height) override;

public:
	TouchscreenInput_TestFps m_touchScreenInput;
	UnifiedTurnBuild m_unifiedTurnBuild;
	Minecraft* m_pMinecraft;
};

