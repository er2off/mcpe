/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#include "IScreen.hpp"

// TODO: This should be inside of an initialized "Minecraft" instance rather than the global namespace
bool g_bIsMenuBackgroundAvailable = false;

IScreen::IScreen()
{
	m_width = 1;
	m_height = 1;
	m_bIgnore = false;
}

void IScreen::init(Minecraft* pMinecraft, int a3, int a4)
{
	m_width  = a3;
	m_height = a4;
	m_pMinecraft = pMinecraft;
	onInit();
}

void IScreen::onInit()
{
}

void IScreen::setSize(int width, int height)
{
	m_width = width;
	m_height = height;
}

void IScreen::onRender(int mouseX, int mouseY, float f)
{
}

int IScreen::getYOffset()
{
	return 0;
}

void IScreen::onEvents()
{
}

void IScreen::mouseEvent()
{
}

void IScreen::keyboardEvent()
{
}

void IScreen::onTick()
{
}

void IScreen::removed()
{
}

bool IScreen::handleBackEvent(bool b)
{
	return false;
}

void IScreen::renderBackground()
{
}

bool IScreen::isPauseScreen()
{
	return true;
}

bool IScreen::isErrorScreen()
{
	return false;
}

bool IScreen::isInGameScreen()
{
	return true;
}

void IScreen::charInput(char ch)
{
}
