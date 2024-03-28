#include "Server.hpp"
#include "network/ServerSideNetworkHandler.hpp"
#include "world/level/storage/ExternalFileLevelStorageSource.hpp"

Server::Server(bool standalone)
{
	m_pOptions = new Options();
	m_pGameMode = nullptr;
	m_pLevel = nullptr;
	m_pLevelStorageSource = nullptr;
	m_pRakNetInstance = new RakNetInstance;

	if (standalone)
	{
		m_pLevelStorageSource = new ExternalFileLevelStorageSource("level");
		setLevel("level", "Level", 123456);
	}

	m_pNetEventCallback = new ServerSideNetworkHandler(this, m_pRakNetInstance);
	m_bRunning = true;
}

void Server::setLevel(const std::string path, const std::string name, int seed)
{
	LevelStorage* pStor = m_pLevelStorageSource->selectLevel(path, false);
	Dimension* pDim = Dimension::getNew(0);
	// don't delete pDim manually, it's deleted automatically by level

	m_pLevel = new Level(pStor, name, seed, 1, pDim);
}

Server::~Server()
{
	delete m_pGameMode;
	delete m_pLevel;
	delete m_pLevelStorageSource;
	delete m_pRakNetInstance;
	delete m_pNetEventCallback;
	delete m_pOptions;
}

Level* Server::getLevel()
{
	return m_pLevel;
}

RakNetInstance* Server::getRakNetInstance()
{
	return m_pRakNetInstance;
}

Options* Server::getOptions()
{
	return m_pOptions;
}

GameMode* Server::getGameMode()
{
	return m_pGameMode;
}

void Server::addMessage(const std::string& message)
{
	LOG_I("MSG: %s", message.c_str());
}

void Server::start(const std::string name)
{
	m_pRakNetInstance->host(name, C_DEFAULT_PORT, C_MAX_CONNECTIONS);
}

void Server::stop()
{
	m_bRunning = false;
}

void Server::generateLevel()
{
	if (!m_pLevel)
	{
		LOG_W("Level wasn't initialized!");
		setLevel("level", "Level", 123456);
	}

	LOG_I("Building terrain");

	float startTime = getTimeS();
	Level* pLevel = m_pLevel;

	if (!pLevel->field_B0C)
	{
		pLevel->setUpdateLights(0);
	}

	printf("Processing");
	for (int i = 8, i2 = 0; i != 8 + C_MAX_CHUNKS_X * 16; i += 16)
	{
		for (int j = 8; j != 8 + C_MAX_CHUNKS_Z * 16; j += 16, i2 += 100)
		{
			// this looks like some kind of progress tracking
			printf("\r\033[KProcessing %i%%", i2 / (C_MAX_CHUNKS_X * C_MAX_CHUNKS_Z));
			fflush(stdout);

			float time1 = getTimeS();

			// generating all the chunks at once
			TileID unused = m_pLevel->getTile(i, (C_MAX_Y + C_MIN_Y) / 2, j);

			if (time1 != -1.0f)
				getTimeS();

			float time2 = getTimeS();
			if (m_pLevel->field_B0C)
			{
				while (m_pLevel->updateLights());
			}

			if (time2 != -1.0f)
				getTimeS();
		}
	}
	printf("\n");

	if (startTime != -1.0f)
		getTimeS();

	m_pLevel->setUpdateLights(1);

	startTime = getTimeS();

	for (int x = 0; x < C_MAX_CHUNKS_X; x++)
	{
		for (int z = 0; z < C_MAX_CHUNKS_Z; z++)
		{
			LevelChunk* pChunk = m_pLevel->getChunk(x, z);
			if (!pChunk)
				continue;

			if (pChunk->field_237)
				continue;

			pChunk->m_bUnsaved = false;
			pChunk->clearUpdateMap();
		}
	}

	if (startTime != -1.0f)
		getTimeS();

	LOG_I("Saving chunks");

	if (m_pLevel->field_B0C)
	{
		m_pLevel->setInitialSpawn();
		m_pLevel->saveLevelData();
		m_pLevel->getChunkSource()->saveAll();
	}
	else
	{
		m_pLevel->saveLevelData();
	}

	LOG_I("Preparing");

	startTime = getTimeS();

	m_pLevel->prepare();

	m_pNetEventCallback->levelGenerated(m_pLevel, nullptr);
}

void Server::tick()
{
	m_pLevel->tickEntities();
	m_pLevel->tick();
}

void Server::host()
{
	ServerSideNetworkHandler* pSSNH = (ServerSideNetworkHandler*)m_pNetEventCallback;
	pSSNH->allowIncomingConnections(true);
	LOG_I("Server is ready!");

	while (m_bRunning)
	{
		m_pRakNetInstance->runEvents(m_pNetEventCallback);

		// tick
		m_timer.advanceTime();

		for (int i = 0; i < m_timer.m_ticks; i++)
		{
			tick();
		}

		//sleepMs(1);
	}

	LOG_I("Stopping server");
	LOG_I("Saving chunks");

	m_pLevel->saveLevelData();
}
