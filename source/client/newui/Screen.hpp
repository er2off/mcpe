/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once
#include "client/app/IScreen.hpp"
#include "controls/IControl.hpp"
#include "Drawer.hpp"

class Screen : public IScreen, public Drawer
{
public:
	Screen();
	virtual ~Screen();

	void init(Minecraft*, int, int) override;
	void setSize(int width, int height) override;
	int getYOffset() override;

	virtual void onInit() override;
	virtual void onRender(int mouseX, int mouseY, float f) override;
	virtual void onEvents() override;
	virtual void onTick() override;

	virtual void mouseEvent() override;
	virtual void keyboardEvent() override;
	virtual bool handleBackEvent(bool) override;
	virtual void removed() override;
	virtual void renderBackground() override;
	virtual bool isPauseScreen() override;
	virtual bool isErrorScreen() override;
	virtual bool isInGameScreen() override;
	virtual void confirmResult(bool, int) override;
	virtual void charInput(char) override;

	virtual void mouseClicked(int, int, int);
	virtual void mouseReleased(int, int, int);

	// ported from 0.8
	//virtual void renderMenuBackground(float f);

protected:
	std::vector<IControl *> m_controls;
	IControl *m_pFocusedControl;
};
