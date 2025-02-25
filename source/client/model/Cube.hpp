/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp
	
	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once

#include "PolygonQuad.hpp"

class Cube
{
public:
	Cube(int, int);

	void addBox(float x, float y, float z, int displayX, int displayY, int displayZ, float scale = 0);
	// @TODO: void addTexBox(float a, float b, float c, int d, int e, int f, int g); -- No xrefs
	void compile(float scale);
	void draw();
	void drawSlow(float scale);
	void render(float scale);
	void setPos(float x, float y, float z);
	void setTexOffs(int a, int b);
	void translateTo(float scale);
	void setBrightness(float brightness);

private:
	bool hasDefaultPos() { return m_posX == 0 && m_posY == 0 && m_posZ == 0; }
	bool hasDefaultRot() { return m_rotX == 0 && m_rotY == 0 && m_rotZ == 0; }
	void translatePosTo(float scale);
	void translateRotTo(float scale);

public:
	float m_posX;
	float m_posY;
	float m_posZ;
	float m_rotX;
	float m_rotY;
	float m_rotZ;
	bool m_swapX;
	bool m_bIgnore;
	VertexPT m_verts[8];
	PolygonQuad m_faces[6];
	int m_texOffsetX;
	int m_texOffsetY;
	bool m_bCompiled;
	GLuint m_buffer;
	float m_brightness;

	static const float c;
};

