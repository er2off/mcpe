/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp

	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#include "PigModel.hpp"
#include "client/app/Minecraft.hpp"

PigModel::PigModel(float a, float b):
	Model("mob/pig.png"),
	m_head(0,  0),
	m_body(28, 16),
	m_armL(0,  16),
	m_armR(0,  16),
	m_legL(0,  16),
	m_legR(0,  16),
	m_snout(16, 16)
{
	// @NOTE: Why 25 (19+6) is lowest Y coordinate? I have many questions to Mojang

	m_head.addBox(-2, 9, -9, 8, 8, 8, a);
	m_head.setPos(0, b, 0);
	m_snout.addBox(0, 12, -10, 4, 3, 1);
	m_snout.setPos(0, b, 0);

	m_body.addBox(-3, 11, -3, 10, 8, 16, a);
	m_body.setPos(0, b, 0);

	m_armL.addBox(-3, 19, -2, 4, 6, 4, a);
	m_armL.setPos(0, b, 0);
	m_armR.addBox(3,  19, -2, 4, 6, 4, a);
	m_armR.setPos(0, b, 0);
	m_legL.addBox(-3, 19, 9, 4, 6, 4, a);
	m_legL.setPos(0, b, 0);
	m_legR.addBox(3,  19, 9, 4, 6, 4, a);
	m_legR.setPos(0, b, 0);
}

void PigModel::_logGraphics()
{
	Matrix m;

	if (Minecraft::customDebugId == 1)
	{
		// @NOTE: I think most of this function was ifdef'd/commented out
		m.fetchGL(GL_MODELVIEW_MATRIX);
	}
}

void PigModel::onGraphicsReset()
{
	m_head.m_bCompiled = false;
	m_body.m_bCompiled = false;
	m_armL.m_bCompiled = false;
	m_armR.m_bCompiled = false;
	m_legL.m_bCompiled = false;
	m_legR.m_bCompiled = false;
	m_snout.m_bCompiled = false;
}

void PigModel::render(float a, float b, float c, float d, float e, float f)
{
	setupAnim(a, b, c, d, e, f);
	m_head.render(f);
	m_snout.render(f);
	m_body.render(f);
	m_armL.render(f);
	m_armR.render(f);
	m_legL.render(f);
	m_legR.render(f);
	_logGraphics();
}

void PigModel::setupAnim(float a2, float a3, float a4, float yaw, float pitch, float a7)
{
	m_snout.m_rotY = m_head.m_rotY = std::clamp(yaw * 0.017453f, -0.5f, 0.5f);
	m_snout.m_rotX = m_head.m_rotX = std::clamp(pitch * 0.017453f, -0.5f, 0.5f);

	float v12 = (a2 * 0.6662f) + 3.1416f;
	m_armL.m_rotX = m_legL.m_rotX = Mth::cos(a2 * 0.6662f) * 0.2f * a3;
	m_armR.m_rotX = m_legR.m_rotX = Mth::cos(v12) * 0.2f * a3;
	m_armL.m_rotY = m_legL.m_rotY = 0.0f;
	m_armR.m_rotY = m_legR.m_rotY = 0.0f;

	if (field_8)
	{
		float v16 = (3.1416f * -0.5f) * 0.8f;
		m_armL.m_rotX = m_legL.m_rotX = v16;
		m_armR.m_rotX = m_legR.m_rotX = v16;
		m_armL.m_rotY = m_legL.m_rotY = (3.1416f * 0.5f) * 0.2f;
		m_armR.m_rotY = m_legR.m_rotY = (3.1416f * -0.5f) * 0.2f;
	}
}

void PigModel::setBrightness(float f)
{
	m_head.setBrightness(f);
	m_snout.setBrightness(f);
	m_body.setBrightness(f);
	m_armL.setBrightness(f);
	m_armR.setBrightness(f);
	m_legL.setBrightness(f);
	m_legR.setBrightness(f);
}
