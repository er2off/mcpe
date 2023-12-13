/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp
	
	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#include "ChatScreen.hpp"

// @NOTE: This is unused.

ChatScreen::ChatScreen(bool slash) :
	m_textChat(this, 1, 0, 0),
	m_btnSend(2, 0, 0, "Send"),
	m_btnBack(3, 0, 0, "Back")
{
	if (slash)
		m_textChat.m_text = "/";
}

void ChatScreen::buttonClicked(Button* pButton)
{
	if (pButton->m_buttonId == m_btnSend.m_buttonId)
		sendMessageAndExit();
	if (pButton->m_buttonId == m_btnBack.m_buttonId)
		m_pMinecraft->setScreen(nullptr);
}

void ChatScreen::onInit()
{
	m_btnBack.m_height = m_btnSend.m_height = 20;
	m_btnBack.m_width = m_btnSend.m_width = 40;
	m_textChat.m_xPos = 0;
	m_textChat.m_yPos = m_height - 20;
	m_textChat.m_width = m_width - m_btnSend.m_width;
	m_textChat.m_height = 20;
	m_btnSend.m_yPos = m_height - 20;
	m_btnSend.m_xPos = m_textChat.m_xPos + m_textChat.m_width;
	m_btnBack.m_yPos = 10;
	m_btnBack.m_xPos = m_width - m_btnBack.m_width - 10;
	
	// set focus directly on the chat text box
	m_textChat.onInit(m_pFont);
	m_textChat.setFocused(true);

	m_buttons.push_back(&m_btnSend);
	m_buttons.push_back(&m_btnBack);
	m_textInputs.push_back(&m_textChat);
}

void ChatScreen::removed()
{
	// Now let them be rendered.
	m_pMinecraft->m_pGui->m_bRenderChatMessages = true;
}

void ChatScreen::onRender(int mouseX, int mouseY, float f)
{
	renderBackground();

	// override the default behavior of rendering chat messages
	m_pMinecraft->m_pGui->m_bRenderChatMessages = true;

	m_btnBack.m_yPos = 10 + getYOffset();

	Screen::onRender(mouseX, mouseY, f);
}

void ChatScreen::keyPressed(int keyCode)
{
	if (m_pMinecraft->getOptions()->isKey(KM_MENU_OK, keyCode))
		sendMessageAndExit();

	Screen::keyPressed(keyCode);
}

void ChatScreen::sendMessageAndExit()
{
	m_pMinecraft->sendMessage(m_textChat.m_text);
	
	m_pMinecraft->setScreen(nullptr);
}
