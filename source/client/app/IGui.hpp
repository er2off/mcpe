/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once
#include "App.hpp"

class Minecraft;
class Entity;
class IScreen;

class IGui
{
public:
	IGui(Minecraft* pMinecraft);

	virtual void addMessage(const std::string& str);
	virtual void onInventoryUpdated();
	virtual void tick();
	virtual void render(float f, bool bHaveScreen, int mouseX, int mouseY);

	virtual bool isInside(int mx, int my);
	virtual void handleClick(int id, int mx, int my);
	virtual void handleKeyPressed(int keyCode);
	virtual void renderChatMessages(bool bShowAll);
	virtual int getNumSlots();					  // Gets the number of slots in the inventory. Includes the '...' if in touch mode.
	virtual int getNumUsableSlots();			  // Gets the number of usable slots in the inventory. Does not include the '...' if in touch mode.

	virtual IScreen* screenMain();
	virtual IScreen* screenDeath();
	virtual IScreen* screenPause();
	virtual IScreen* screenSaveWorld(bool bCopyMap, Entity *pEnt);
	virtual IScreen* screenRenameMPWorld(std::string name);

	float scale;
	bool m_bRenderChatMessages;
	Minecraft* m_pMinecraft;
};
