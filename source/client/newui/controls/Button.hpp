/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once
#include "IControl.hpp"

class Button : public IControl
{
public:
	Button(int x, int y, int width = 200, int height = 24, const std::string text = "", bool enabled = true) :
		m_xPos(x),
		m_yPos(y),
		m_width(width),
		m_height(height),
		m_text(text),
		m_bEnabled(enabled)
	{
	}

	bool onClick(Minecraft* pMinecraft, int x, int y) override;
	void onUnpress(Minecraft* pMinecraft, int x, int y) override;
	void onDraw(Minecraft* pMinecraft, int x, int y) override;

private:
	int getYImage(bool bHovered);
	bool isHovered(int xPos, int yPos);

public:
	bool m_bEnabled;
	bool m_bHovered;
	int m_xPos;
	int m_yPos;
	int m_width;
	int m_height;
	std::string m_text;
};
