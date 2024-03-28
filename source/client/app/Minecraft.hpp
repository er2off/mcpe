/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp
	
	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once

#include "App.hpp"
#include "common/CThread.hpp"
#include "common/Mth.hpp"
#include "common/Timer.hpp"
#include "client/gui/Gui.hpp"
#include "client/gui/Screen.hpp"
#include "network/RakNetInstance.hpp"
#include "client/player/LocalPlayer.hpp"
#include "client/player/input/IInputHolder.hpp"
#include "client/player/input/MouseHandler.hpp"
#include "client/player/input/BuildActionIntention.hpp"
#include "client/renderer/GameRenderer.hpp"
#include "client/renderer/LevelRenderer.hpp"
#include "client/renderer/entity/EntityRenderDispatcher.hpp"
#include "client/sound/SoundEngine.hpp"
#include "server/Server.hpp"
#include "world/level/Level.hpp"
#include "world/gamemode/GameMode.hpp"
#include "world/particle/ParticleEngine.hpp"

class Screen; // in case we're included from Screen.hpp

class Minecraft : public App, public Server
{
public:
	Minecraft();
	virtual ~Minecraft();

	int getLicenseId();
	void setScreen(Screen * pScreen);
	void releaseMouse();
	void grabMouse();
	void tick();
	void tickInput();
	void saveOptions();
	void handleMouseClick(int type);
	void handleMouseDown(int type, bool b);
	void handleBuildAction(BuildActionIntention*);
	bool isLevelGenerated();
	void selectLevel(const std::string&, const std::string&, int);
	void setLevel(Level*, const std::string&, LocalPlayer*);
	void pauseGame();
	void leaveGame(bool bCopyMap);
	void hostMultiplayer();
	void joinMultiplayer(const PingedCompatibleServer& serverInfo);
	void cancelLocateMultiplayer();
	void locateMultiplayer();
	void tickMouse();
	void handleCharInput(char chr);
	virtual void addMessage(const std::string& message) override;
	void sendMessage(const std::string& message);
	void resetPlayer(Player* player);
	void respawnPlayer(Player* player);
	std::string getVersionString();
	bool isTouchscreen();
	bool useSplitControls();

	virtual void update() override;
	virtual void init() override;
	virtual void onGraphicsReset();
	virtual void sizeUpdate(int newWidth, int newHeight) override;
	virtual int getFpsIntlCounter();

	float getBestScaleForThisScreenSize(int width, int height);
	void generateLevel(const std::string& unused, Level* pLevel);
	void prepareLevel(const std::string& unused);
	bool isOnline();
	bool isOnlineClient();
	static void* prepareLevel_tspawn(void* pMinecraft);

	const char* getProgressMessage();
	LevelStorageSource* getLevelSource();
	ItemInstance* getSelectedItem();

	static void setGuiScaleMultiplier(float f);

private:
	void _reloadInput();
	void _levelGenerated();

public:
	static float guiScaleMultiplier;
	static int width, height;
	static const char* progressMessages[];
	static const bool DEADMAU5_CAMERA_CHEATS;
	static int customDebugId;

private:
	Logger *m_Logger;

public:
	bool field_18;
	bool field_288;
	LevelRenderer* m_pLevelRenderer;
	GameRenderer* m_pGameRenderer;
	ParticleEngine* m_pParticleEngine;
	SoundEngine* m_pSoundEngine;
	Textures* m_pTextures;
	Font* m_pFont;
	int field_2B0;
	int field_2B4;
	int field_2B8;
	User* m_pUser;
	LocalPlayer* m_pLocalPlayer;
	Mob* m_pMobPersp; // why is there a duplicate?
	Gui m_gui;
	int field_D0C;
	CThread* m_pPrepThread;
	Screen* m_pScreen;
	int field_D18;
	IInputHolder* m_pInputHolder;
	MouseHandler m_mouseHandler;
	bool m_bGrabbedMouse;
	bool m_bIsTouchscreen;
	HitResult m_hitResult;
	int m_progressPercent;
	std::string m_externalStorageDir;
	bool m_bPreparingLevel;
	int field_D9C;
	int field_DA0;
	int field_DA4;
	int field_DA8;
	int field_DAC;
	bool m_bUsingScreen;
	bool m_bHasQueuedScreen;
	Screen* m_pQueuedScreen;
	int m_licenseID;
	ItemInstance m_CurrItemInstance;

	// in 0.8. Offset 3368
	double m_fDeltaTime, m_fLastUpdated;
};

