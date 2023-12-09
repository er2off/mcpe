/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once
#include "client/app/IGui.hpp"

class Gui : public IGui
{
public:
	Gui(Minecraft* pMinecraft);

	void addMessage(const std::string& str) override;

	void onInventoryUpdated() override;
	void onTick() override;
	void onRender(float f, bool bHaveScreen, int mouseX, int mouseY) override;

	bool isInside(int mx, int my) override;
	void handleClick(int id, int mx, int my) override;
	void handleKeyPressed(int keyCode) override;
	void renderChatMessages(bool bShowAll) override;
	int getNumSlots() override;					  // Gets the number of slots in the inventory. Includes the '...' if in touch mode.
	int getNumUsableSlots() override;			  // Gets the number of usable slots in the inventory. Does not include the '...' if in touch mode.

	IScreen* screenMain() override;
	IScreen* screenDeath() override;
	IScreen* screenPause() override;
	IScreen* screenSaveWorld(bool bCopyMap, Entity *pEnt) override;
	IScreen* screenRenameMPWorld(std::string name) override;
};
