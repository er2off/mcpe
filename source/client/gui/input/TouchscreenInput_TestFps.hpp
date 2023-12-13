/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once

#include "client/gui/GuiComponent.hpp"
#include "client/player/input/RectangleArea.hpp"
#include "client/player/input/PolygonArea.hpp"
#include "client/player/input/TouchAreaModel.hpp"
#include "client/player/input/TouchInputHolder.hpp"

class Minecraft;
class Options;

class TouchscreenInput_TestFps : public TouchInput, public GuiComponent
{
public:
	TouchscreenInput_TestFps(Minecraft*, Options*);

	// IMoveInput
	void releaseAllKeys() override;
	void setKey(int key, bool state) override;
	void setScreenSize(int width, int height) override;
	void onTick(Player*) override;
	void onRender(float f) override;

	bool isButtonDown(int key);

private:
	bool field_30[10];
	bool m_bForwardHeld;
	bool m_bJumpingHeld;
	bool m_bFlyActive;
	int m_jumpTick;
	TouchAreaModel m_touchAreaModel;
	PolygonArea* m_pAreaLeft;
	PolygonArea* m_pAreaRight;
	PolygonArea* m_pAreaForward;
	PolygonArea* m_pAreaBackward;
	PolygonArea* m_pAreaJump;
	bool field_6C[8];
};

