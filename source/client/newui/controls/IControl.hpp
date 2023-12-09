/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once
#include "client/app/Minecraft.hpp"
#include "../Drawer.hpp"

class IControl : public Drawer
{
public:
	IControl() : Drawer(),
		m_bVisible(true)
	{
	}

	virtual void onTick() {}
	virtual bool onClick(Minecraft* pMinecraft, int x, int y) { return false; }
	virtual void onUnpress(Minecraft* pMinecraft, int x, int y) {}
	virtual void onDraw(Minecraft* pMinecraft, int x, int y) {}
	virtual void onKeyPressed(Minecraft* pMinecraft, int key) {}
	virtual void onCharPressed(Minecraft* pMinecraft, int chr) {}

	bool m_bVisible;
};
