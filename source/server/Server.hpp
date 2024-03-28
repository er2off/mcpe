#pragma once

#include "Options.hpp"
#include "common/Timer.hpp"
#include "network/RakNetInstance.hpp"
#include "world/level/Level.hpp"
#include "world/gamemode/GameMode.hpp"

class ServerSideNetworkHandler;

class Server
{
public:
	Server(bool standalone);
	~Server();

	void setLevel(const std::string path, const std::string name, int seed);
	Level* getLevel();
	RakNetInstance* getRakNetInstance();
	Options* getOptions();
	GameMode* getGameMode();

	void start(const std::string name);
	void stop();
	void generateLevel();
	void tick();
	void host();

	virtual void addMessage(const std::string& message);
public:
	Level* m_pLevel;
	RakNetInstance* m_pRakNetInstance;
	GameMode* m_pGameMode;
	LevelStorageSource* m_pLevelStorageSource;
	NetEventCallback* m_pNetEventCallback;
protected:
	Options* m_pOptions;
	Timer m_timer;
private:
	bool m_bRunning;
};
