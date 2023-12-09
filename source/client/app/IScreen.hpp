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
	virtual void setSize(int width, int height);
	virtual int getYOffset();

	virtual void onInit();
	virtual void onRender(int mouseX, int mouseY, float f);
	virtual void onEvents();
	virtual void onTick();

	virtual void mouseEvent();
	virtual void keyboardEvent();
	virtual bool handleBackEvent(bool);
	virtual void removed();
	virtual void renderBackground();
	virtual bool isPauseScreen();
	virtual bool isErrorScreen();
	virtual bool isInGameScreen();
	virtual void confirmResult(bool, int);
	virtual void charInput(char);

	int m_width;
	int m_height;
	bool m_bIgnore;
	Minecraft *m_pMinecraft;
};
