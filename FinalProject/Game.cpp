
#include "Game.h"

#include "Constants.h"
#include <assert.h>

Game* Singleton<Game>::s_Obj = NULL;

Game::Game()
{
	// create player
	m_Player = new Player(Vec2(PLAYER_START_X, PLAYER_START_Y));
	
	// Create cover
	for (Vec2 pos : COVER_POSITIONS)
	{
		m_Covers.push_back(new Cover(pos));
	}

	// create reload points
	for (Vec2 pos : RELOAD_POSITIONS)
	{
		m_Reloads.push_back(new ReloadPoint(pos));
	}
}

Game::~Game()
{
	delete m_Player;
}

void Game::tick(float deltaTSec)
{
	int runs = 0;
	while (runs < PHYSICS_RUN_PER_TICK) {
		// Update Player
		m_Player->tick(deltaTSec / PHYSICS_RUN_PER_TICK);

		// Update Enemies
		for (Enemy* enemy : m_Enemies)
		{
			enemy->tick(deltaTSec / PHYSICS_RUN_PER_TICK);
		}

		// Update Bullets
		for (Bullet* bullet : m_Bullets)
		{
			bullet->tick(deltaTSec / PHYSICS_RUN_PER_TICK);
		}

		// Check for bullet hits and deal damage
		processBulletHits();

		// Check for entities in reload areas and reload ammo
		processReloads();

		runs++;
	}
}

// Creates a new bullet and adds it to the Game's bullet vector
void Game::createBullet(Vec2 origin, Vec2 direction, bool fromEnemy, bool fromRifle)
{
	Bullet* bullet = new Bullet(origin, direction, fromEnemy, fromRifle);
	m_Bullets.push_back(bullet);
}

// Check if each bullet is coliding with an entity and deals damage
void Game::processBulletHits()
{
	for (Bullet* bullet : m_Bullets)
	{
		for (Cover* cover : m_Covers) // Check if bullet hit cover
		{
			if (bullet->checkCollision(cover)) {
				bullet->setDead(true);
				break;
			}
		}
		if (bullet->isFromEnemy() && !bullet->isDead() && bullet->checkCollision(m_Player)) // Bullet shot by enemy, check if hit player only (no friendly fire)
		{
			m_Player->takeDamage();
			bullet->setDead(true);
			break;
		}
		else if (!bullet->isFromEnemy() && !bullet->isDead())// Bullet shot by player, check if hit an enemy
		{
			for (Enemy* enemy : m_Enemies)
			{
				if (bullet->checkCollision(enemy)) {
					enemy->takeDamage();
					bullet->setDead(true);
					break;
				}
			}
		}
	}

	// Move dead Enemy to dead enemy vector
	size_t newIndex = 0;
	for (size_t oldIndex = 0; oldIndex < m_Enemies.size(); ++oldIndex)
	{
		Enemy* pEnemy = m_Enemies[oldIndex];
		if (!pEnemy->isDead())
		{
			Enemy* pTemp = m_Enemies[newIndex];
			m_Enemies[newIndex] = m_Enemies[oldIndex];
			m_Enemies[oldIndex] = pTemp;
			++newIndex;
		}
		else
		{
			m_DeadEnemies.push_back(m_Enemies[oldIndex]);
		}
	}

	assert(newIndex <= m_Enemies.size());
	m_Enemies.resize(newIndex);

	// Move "dead" Bullets to dead bullet vector
	newIndex = 0;
	for (size_t oldIndex = 0; oldIndex < m_Bullets.size(); ++oldIndex)
	{
		Bullet* pBullet = m_Bullets[oldIndex];
		if (!pBullet->isDead())
		{
			Bullet* pTemp = m_Bullets[newIndex];
			m_Bullets[newIndex] = m_Bullets[oldIndex];
			m_Bullets[oldIndex] = pTemp;
			++newIndex;
		}
		else
		{
			m_DeadBullets.push_back(m_Bullets[oldIndex]);
		}
	}

	assert(newIndex <= m_Bullets.size());
	m_Bullets.resize(newIndex);
}

void Game::processReloads()
{
	for (ReloadPoint* reload : m_Reloads)
	{
		// Check enemy reloads
		for (Enemy* enemy : m_Enemies)
		{
			reload->reloadEntity(enemy);
		}

		// Check player reload
		reload->reloadEntity(m_Player);
	}

}

// Resets the player position and loads the enemies for the game level
void Game::loadLevel()
{
	m_Player->setPosition(Vec2(PLAYER_START_X, PLAYER_START_Y));
	m_Player->resetHealth();

	switch (m_Level) {
		case 4:
			m_Enemies.push_back(new Enemy(ENEMY_SPAWN_POSITIONS[6], true));
			m_Enemies.push_back(new Enemy(ENEMY_SPAWN_POSITIONS[8], true));
			m_Enemies.push_back(new Enemy(ENEMY_SPAWN_POSITIONS[10], false));
			m_Enemies.push_back(new Enemy(ENEMY_SPAWN_POSITIONS[11], false));
			m_Enemies.push_back(new Enemy(ENEMY_SPAWN_POSITIONS[12], false));

		case 3:
			m_Enemies.push_back(new Enemy(ENEMY_SPAWN_POSITIONS[1], true));
			m_Enemies.push_back(new Enemy(ENEMY_SPAWN_POSITIONS[3], true));
			m_Enemies.push_back(new Enemy(ENEMY_SPAWN_POSITIONS[7], false));

		case 2:
			m_Enemies.push_back(new Enemy(ENEMY_SPAWN_POSITIONS[0], true));
			m_Enemies.push_back(new Enemy(ENEMY_SPAWN_POSITIONS[4], true));
			m_Enemies.push_back(new Enemy(ENEMY_SPAWN_POSITIONS[5], false));
			m_Enemies.push_back(new Enemy(ENEMY_SPAWN_POSITIONS[9], false));

		case 1:
			m_Enemies.push_back(new Enemy(ENEMY_SPAWN_POSITIONS[2], true));

		default:
			break;
	}
}

bool Game::isGameOver()
{
	return m_Player->getHealth() <= 0 || m_Level > 4;
}
