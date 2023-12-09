/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#include "MainScreen.hpp"
#include "../controls/Button.hpp"

// TODO: Read splashes from splashes.json

MainScreen::MainScreen() : Screen()
{
	m_controls.push_back(new Button(1, 1, 100, 24, "Hello, world!"));
}
