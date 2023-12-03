/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once

#include "Model.hpp"

class PigModel : public Model
{
public:
	PigModel(float a, float b);
	void _logGraphics();
	// @TODO - No xrefs: void render(PigModel* a, float f);

	void onGraphicsReset() override;
	void render(float, float, float, float, float, float) override;
	void setupAnim(float, float, float, float, float, float) override;
	void setBrightness(float) override;

public:
	Cube m_head, m_body, m_armL, m_armR, m_legL, m_legR, m_snout;
	bool field_10BC;
	bool field_10BD;
	bool field_10BE;
};

