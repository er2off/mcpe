/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp
	
	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once

#include "GuiComponent.hpp"
#include "client/player/input/RectangleArea.hpp"
#include "client/app/Minecraft.hpp"
#include "common/Random.hpp"
#include "common/Utils.hpp"

class Minecraft; // in case we're included from Minecraft.hpp

struct GuiMessage
{
	std::string msg;
	int field_18;

	GuiMessage(const std::string& x, int a) : msg(x), field_18(a) {}
};

class Gui : public GuiComponent, public IGui
{
public:
	Gui(Minecraft* pMinecraft);

	// screens
	IScreen* screenMain() override;
	IScreen* screenDeath() override;
	IScreen* screenPause() override;
	IScreen* screenSaveWorld(bool bCopyMap, Entity *pEnt) override;
	IScreen* screenRenameMPWorld(std::string name) override;

	void addMessage(const std::string& str) override;
	void onInventoryUpdated() override;
	void onTick() override;
	void onRender(float f, bool bHaveScreen, int mouseX, int mouseY) override;

	bool isInside(int mx, int my) override;
	void handleClick(int id, int mx, int my) override;
	void handleKeyPressed(int keyCode) override;
	void renderChatMessages(bool bShowAll) override;
	int getNumSlots() override;					  // Gets the number of slots in the inventory. Includes the '...' if in touch mode.

	void renderVignette(float a2, int a3, int a4);
	void renderSlot(int slot, int x, int y, float f);
	void renderSlotOverlay(int slot, int x, int y, float f);
	int getSlotIdAt(int mouseX, int mouseY);

	std::vector<GuiMessage> m_guiMessages;
	//Minecraft* m_pMinecraft;
	Random m_random;
	RenderChunk m_renderChunk;
	float m_vignetteColor;
	// bool field_A3c; // unused

/*
public:
	float field_8;
	std::string field_C;
	int field_24;
	int field_28;
	int field_2C;
	int field_9FC;
	std::string field_A00;
	int field_A18;
	bool field_A1C;
	bool field_A3C;
*/
};

