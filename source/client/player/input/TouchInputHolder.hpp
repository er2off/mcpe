/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once

#include "client/app/Minecraft.hpp"
#include "IInputHolder.hpp"
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

class TouchInput : public IMoveInput, public IScreen
{
public:
	TouchInput(Minecraft* pMinecraft, Options* pOptions) :
		m_pMinecraft(pMinecraft),
		m_pOptions(pOptions),
		m_rectArea(0, 0, 0, 0)
	{
	}

	RectangleArea getRectangleArea()
	{
		return m_rectArea;
	}

protected:
	Minecraft* m_pMinecraft;
	Options* m_pOptions;
	RectangleArea m_rectArea;
};

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
	TouchInput *m_touchScreenInput;
	UnifiedTurnBuild m_unifiedTurnBuild;
	Minecraft* m_pMinecraft;
};

