/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once

#include "../Screen.hpp"

class DirectConnectScreen : public Screen
{
public:
	DirectConnectScreen();
	
	virtual void onInit() override;
	virtual void buttonClicked(Button* pButton) override;
	virtual void onRender(int x, int y, float f) override;

private:
	TextInputBox m_textAddress;
	Button m_btnQuit;
	Button m_btnJoin;
};
