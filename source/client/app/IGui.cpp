/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#include "IGui.hpp"
#include "Minecraft.hpp"

IGui::IGui(Minecraft* pMinecraft)
{
#ifdef ENH_USE_GUI_SCALE_2
	scale = 1.0f / 2.0f;
#else
	scale = 1.0f / 3.0f;
#endif

	m_bRenderChatMessages = true;
	m_pMinecraft = pMinecraft;
}

void IGui::addMessage(const std::string& s)
{
}

void IGui::onInventoryUpdated()
{
}

void IGui::tick()
{
}

void IGui::render(float f, bool bHaveScreen, int mouseX, int mouseY)
{
}

bool IGui::isInside(int mouseX, int mouseY)
{
	return false;
}

void IGui::handleClick(int clickID, int mouseX, int mouseY)
{
}

void IGui::handleKeyPressed(int keyCode)
{
}

void IGui::renderChatMessages(bool bShowAll)
{
}

int IGui::getNumSlots()
{
	return 0;
}

int IGui::getNumUsableSlots()
{
	return getNumSlots() - m_pMinecraft->isTouchscreen();
}

// screens
IScreen* IGui::screenMain()
{
	return nullptr;
}
IScreen* IGui::screenDeath()
{
	return nullptr;
}
IScreen* IGui::screenPause()
{
	return nullptr;
}
IScreen* IGui::screenSaveWorld(bool bCopyMap, Entity *pEnt)
{
	return nullptr;
}
IScreen* IGui::screenRenameMPWorld(std::string name)
{
	return nullptr;
}
