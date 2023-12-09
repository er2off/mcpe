/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once
#include <string>

class Font;

class Drawer
{
public:
	Drawer();
	virtual ~Drawer() {}

	void blit(int dstX, int dstY, int srcX, int srcY, int dstWidth, int dstHeight, int srcWidth, int srcHeight);
	void fill(int left, int top, int right, int bottom, int color);
	void fillGradient(int left, int top, int right, int bottom, int colorUp, int colorDown);
	void drawCenteredText(Font* pFont, const std::string text, int cx, int cy, int color);
	void drawText(Font* pFont, const std::string text, int cx, int cy, int color);
};
