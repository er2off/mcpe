/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp
	
	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once

#include "client/app/IGui.hpp"
#include "client/player/input/Mouse.hpp"
#include "client/player/input/Keyboard.hpp"
#include "components/Button.hpp"
#include "components/TextInputBox.hpp"

class Button;
class TextInputBox;

class Screen : public GuiComponent, public IScreen
{
public:
	Screen();
	virtual ~Screen();

	void init(Minecraft*, int, int);
	void updateTabButtonSelection();
	void setSize(int width, int height);
	void onRender(int mouseX, int mouseY, float f);
	int getYOffset();

	virtual void render(int, int, float);
	virtual void init();
	virtual void onEvents();
	virtual void mouseEvent();
	virtual void keyboardEvent();
	virtual void tick();
	virtual void renderBackground(int);
	virtual void renderBackground();
	virtual void renderDirtBackground(int);
	virtual void buttonClicked(Button*);
	virtual void mouseClicked(int, int, int);
	virtual void mouseReleased(int, int, int);
	virtual void keyPressed(int);
	virtual void charInput(char);

	// ported from 0.8
	virtual void renderMenuBackground(float f);

public:
	std::vector<Button*> m_buttons;
	std::vector<Button*> m_buttonTabList; 
	int m_tabButtonIndex;
	Font* m_pFont;
	Button* m_pClickedButton;

#ifndef ORIGINAL_CODE
	std::vector<TextInputBox*> m_textInputs;
	int m_yOffset;
#endif
};

