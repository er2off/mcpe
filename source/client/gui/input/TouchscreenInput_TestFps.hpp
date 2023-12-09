/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once

#include "client/gui/GuiComponent.hpp"
#include "client/player/input/IMoveInput.hpp"
#include "client/player/input/RectangleArea.hpp"
#include "client/player/input/PolygonArea.hpp"
#include "client/player/input/TouchAreaModel.hpp"

class Minecraft;
class Options;

class TouchscreenInput_TestFps : public IMoveInput, public GuiComponent
{
public:
	TouchscreenInput_TestFps(Minecraft*, Options*);

	// IMoveInput
	void releaseAllKeys() override;
	void setKey(int key, bool state) override;
	void setScreenSize(int width, int height) override;
	void onTick(Player*) override;
	void onRender(float f) override;

	RectangleArea getRectangleArea();
	bool isButtonDown(int key);

private:
	RectangleArea m_rectArea;
	bool field_30[10];
	Options* m_pOptions;
	bool field_40;
	bool m_bJumpBeingHeld;
	TouchAreaModel m_touchAreaModel;
	Minecraft* m_pMinecraft;
	PolygonArea* m_pAreaLeft;
	PolygonArea* m_pAreaRight;
	PolygonArea* m_pAreaForward;
	PolygonArea* m_pAreaBackward;
	PolygonArea* m_pAreaJump;
	bool field_6C[8];
};

