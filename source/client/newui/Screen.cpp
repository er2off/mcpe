/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#include "Screen.hpp"
#include "client/player/input/Mouse.hpp"

Screen::Screen() : IScreen()
{
}

Screen::~Screen()
{
}

void Screen::init(Minecraft* pMinecraft, int a3, int a4)
{
	IScreen::init(pMinecraft, a3, a4);
}

void Screen::onInit()
{
	m_pFocusedControl = nullptr;
}

void Screen::setSize(int width, int height)
{
	IScreen::setSize(width, height);
}

int Screen::getYOffset()
{
	return 0;
}

void Screen::onRender(int xPos, int yPos, float unused)
{
	renderBackground();
	for (IControl *control : m_controls)
	{
		if (control->m_bVisible)
			control->onDraw(m_pMinecraft, xPos, yPos);
	}
}

void Screen::onEvents()
{
}

void Screen::mouseClicked(int xPos, int yPos, int d) // d = clicked?
{
	if (!d) return;
	
	for (IControl *control : m_controls)
	{
		if (control->onClick(m_pMinecraft, xPos, yPos))
		{
			m_pMinecraft->m_pSoundEngine->play("random.click");
			m_pFocusedControl = control;
			break; // no other buttons should be handled?
		}
	}

#if 0
#ifndef ORIGINAL_CODE
	// if the keyboard is shown:
	if (m_pMinecraft->platform()->getKeyboardUpOffset())
	{
		// if there are none focused at the moment:
		bool areAnyFocused = false;
		for (int i = 0; i < int(m_textInputs.size()); i++)
		{
			TextInputBox* textInput = m_textInputs[i];
			if (textInput->m_bFocused)
			{
				areAnyFocused = true;
				break;
			}
		}

		if (!areAnyFocused)
			m_pMinecraft->platform()->showKeyboard(false);
	}
#endif
#endif
}

void Screen::mouseReleased(int xPos, int yPos, int d)
{
	if (!d) return;

	if (m_pFocusedControl)
	{
		m_pFocusedControl->onUnpress(m_pMinecraft, xPos, yPos);
		m_pFocusedControl = nullptr;
	}
}

void Screen::mouseEvent()
{
	MouseAction* pAction = Mouse::getEvent();
	if (pAction->isButton())
	{
		if (Mouse::getEventButtonState())
			mouseClicked (m_width * pAction->_posX / Minecraft::width, m_height * pAction->_posY / Minecraft::height - 1 + getYOffset(), Mouse::getEventButton());
		else
			mouseReleased(m_width * pAction->_posX / Minecraft::width, m_height * pAction->_posY / Minecraft::height - 1 + getYOffset(), Mouse::getEventButton());
	}
}

void Screen::keyboardEvent()
{
}

void Screen::onTick()
{
	for (IControl *control : m_controls)
		control->onTick();
}

void Screen::removed()
{
}

bool Screen::handleBackEvent(bool b)
{
	return false;
}

void Screen::renderBackground()
{
	fill(0, 0, m_width, m_height, 0xFF333333);
}

bool Screen::isPauseScreen()
{
	return true;
}

bool Screen::isErrorScreen()
{
	return false;
}

bool Screen::isInGameScreen()
{
	return true;
}

void Screen::confirmResult(bool b, int i)
{
}

void Screen::charInput(char ch)
{
}
