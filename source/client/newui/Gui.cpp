/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#include "Gui.hpp"
#include "client/app/Minecraft.hpp"

Gui::Gui(Minecraft* pMinecraft) : IGui(pMinecraft)
{
}

void Gui::addMessage(const std::string& s)
{
}

void Gui::onInventoryUpdated()
{
}

void Gui::onTick()
{
}

void Gui::onRender(float f, bool bHaveScreen, int mouseX, int mouseY)
{
}

bool Gui::isInside(int mouseX, int mouseY)
{
	return false;
}

void Gui::handleClick(int clickID, int mouseX, int mouseY)
{
}

void Gui::handleKeyPressed(int keyCode)
{
}

void Gui::renderChatMessages(bool bShowAll)
{
}

int Gui::getNumSlots()
{
	return 9;
}

int Gui::getNumUsableSlots()
{
	return getNumSlots() - m_pMinecraft->isTouchscreen();
}

// screens
#include "screens/MainScreen.hpp"
IScreen* Gui::screenMain()
{
	return new MainScreen();
}
IScreen* Gui::screenDeath()
{
	return nullptr;
}
IScreen* Gui::screenPause()
{
	return nullptr;
}
IScreen* Gui::screenSaveWorld(bool bCopyMap, Entity *pEnt)
{
	return nullptr;
}
IScreen* Gui::screenRenameMPWorld(std::string name)
{
	return nullptr;
}
