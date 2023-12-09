/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once

class Minecraft;

class IScreen
{
public:
	IScreen();
	virtual ~IScreen() = default;

	virtual void init(Minecraft*, int, int);
	virtual void init();
	//virtual void updateTabButtonSelection();
	virtual void setSize(int width, int height);
	virtual void onRender(int mouseX, int mouseY, float f);
	virtual int getYOffset();

	virtual void render(int, int, float);
	virtual void onEvents();
	virtual void mouseEvent();
	virtual void keyboardEvent();
	virtual bool handleBackEvent(bool);
	virtual void tick();
	virtual void removed();
	virtual void renderBackground();
	virtual bool isPauseScreen();
	virtual bool isErrorScreen();
	virtual bool isInGameScreen();
	virtual void confirmResult(bool, int);
	virtual void charInput(char);

	// ported from 0.8
	//virtual void renderMenuBackground(float f);

	int m_width;
	int m_height;
	bool m_bIgnore;
	Minecraft *m_pMinecraft;
};
