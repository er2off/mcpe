/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#include "Button.hpp"

bool Button::onClick(Minecraft* pMinecraft, int x, int y)
{
	return true;
}

void Button::onUnpress(Minecraft* pMinecraft, int x, int y)
{
}

int Button::getYImage(bool bHovered)
{
	if (!m_bEnabled) return 0;
	if (bHovered) return 2;
	return 1;
}

bool Button::isHovered(int xPos, int yPos)
{
	if (!m_bEnabled) return false;
	if (xPos < m_xPos) return false;
	if (yPos < m_yPos) return false;
	if (xPos >= m_xPos + m_width) return false;
	if (yPos >= m_yPos + m_height) return false;

	return true;
}

//#define NEWGUI
void Button::onDraw(Minecraft* pMinecraft, int x, int y)
{
#ifdef ENH_HIGHLIGHT_BY_HOVER
	m_bHovered = isHovered(x, y);
#endif

	Font* pFont = pMinecraft->m_pFont;

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
#ifdef NEWGUI
	// FIXME
	pMinecraft->m_pTextures->loadAndBindTexture("gui/newgui/buttonNew.png");
	//pMinecraft->m_pTextures->loadAndBindTexture("gui/newgui/play_screen/HoverButtonThinNewBevel.png");

	blit(m_xPos, m_yPos, 0, 0, 2, 2, 2, 2);
	blit(m_xPos + m_width - 2, m_yPos, 2, 0, 2, 2, 2, 2);
	blit(m_xPos, m_yPos + m_height - 2, 0, 2, 2, 2, 2, 2);
	blit(m_xPos + m_width - 2, m_yPos + m_height - 2, 2, 2, 2, 2, 2, 2);
	blit(m_xPos + 2, m_yPos, 2, 2, m_width - 4, m_height, 1, 4);
#else
	pMinecraft->m_pTextures->loadAndBindTexture("gui/gui.png");

	int iYPos = 20 * getYImage(m_bHovered) + 46;

	blit(m_xPos, m_yPos, 0, iYPos, m_width / 2, m_height, 0, 20);
	blit(m_xPos + m_width / 2, m_yPos, 200 - m_width / 2, iYPos, m_width / 2, m_height, 0, 20);
#endif

	//renderBg(pMinecraft, x, y);

	int textColor;
	if (!m_bEnabled)
		textColor = int(0xFFA0A0A0U);
	else if (m_bHovered)
		textColor = int(0xFFFFA0U);
	else
		textColor = int(0xE0E0E0U);

	drawCenteredText(pFont, m_text, m_xPos + m_width / 2, m_yPos + (m_height - 8) / 2, textColor);
}
