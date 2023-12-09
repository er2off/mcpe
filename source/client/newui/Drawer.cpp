/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#include "Drawer.hpp"
#include "client/renderer/Font.hpp"
#include "client/renderer/Tesselator.hpp"

Drawer::Drawer()
{
}

void Drawer::blit(int dstX, int dstY, int srcX, int srcY, int dstWidth, int dstHeight, int srcWidth, int srcHeight)
{
	Tesselator& t = Tesselator::instance;

	if (!srcHeight)
		srcHeight = dstHeight;
	if (!srcWidth)
		srcWidth = dstWidth;

	t.begin();
	t.vertexUV(dstX,            dstY + dstHeight, 0, float(srcX)            / 256.0f, float(srcY + srcHeight) / 256.0f);
	t.vertexUV(dstX + dstWidth, dstY + dstHeight, 0, float(srcX + srcWidth) / 256.0f, float(srcY + srcHeight) / 256.0f);
	t.vertexUV(dstX + dstWidth, dstY,             0, float(srcX + srcWidth) / 256.0f, float(srcY)             / 256.0f);
	t.vertexUV(dstX,            dstY,             0, float(srcX)            / 256.0f, float(srcY)             / 256.0f);
	t.draw();
}

void Drawer::fill(int left, int top, int right, int bottom, int color)
{
	glEnable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(float(GET_RED(color)) / 255.0f, float(GET_GREEN(color)) / 255.0f, float(GET_BLUE(color)) / 255.0f, float(GET_ALPHA(color)) / 255.0f);

	Tesselator& t = Tesselator::instance;
	t.begin();

	t.vertex(left, bottom, 0.0f);
	t.vertex(right, bottom, 0.0f);
	t.vertex(right, top, 0.0f);
	t.vertex(left, top, 0.0f);

	t.draw();

	glEnable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void Drawer::fillGradient(int left, int top, int right, int bottom, int colorUp, int colorDown)
{
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);

	Tesselator& t = Tesselator::instance;
	t.begin();

	// note: for some stupid reason OG uses the float overload.
	t.color(float(GET_RED(colorUp)) / 255.0f, float(GET_GREEN(colorUp)) / 255.0f, float(GET_BLUE(colorUp)) / 255.0f, float(GET_ALPHA(colorUp)) / 255.0f);
	t.vertex(left, bottom, 0.0f);
	t.vertex(right, bottom, 0.0f);
	t.color(float(GET_RED(colorDown)) / 255.0f, float(GET_GREEN(colorDown)) / 255.0f, float(GET_BLUE(colorDown)) / 255.0f, float(GET_ALPHA(colorDown)) / 255.0f);
	t.vertex(right, top, 0.0f);
	t.vertex(left, top, 0.0f);

	t.draw();

	glShadeModel(GL_FLAT);
	glDisable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_TEXTURE_2D);
}

void Drawer::drawCenteredText(Font* pFont, const std::string text, int cx, int cy, int color)
{
	int width = pFont->width(text);
	int height = pFont->height(text);
	pFont->drawShadow(text, cx - width / 2, cy - height / 2, color);
}

void Drawer::drawText(Font* pFont, const std::string text, int cx, int cy, int color)
{
	pFont->drawShadow(text, cx, cy, color);
}
