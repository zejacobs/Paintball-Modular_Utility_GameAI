
#include "Entity.h"

#include "Bullet.h"
#include "Game.h"
#include "Constants.h"

Entity::Entity(const Vec2& pos, bool usingRifle)
{
	m_Pos = pos;
	m_Ammo = ENTITY_MAX_AMMO;
	m_UsingRifle = usingRifle;
	m_isDead = false;
	m_TimeSinceShot = FLT_MAX;
}

const void Entity::shoot(Vec2& target)
{
	// Still reloading, don't shoot
	if ((m_UsingRifle && m_TimeSinceShot < RIFLE_RELOAD_TIME)
		|| (!m_UsingRifle && m_TimeSinceShot < SHOTGUN_RELOAD_TIME))
	{
		return;
	}

	// Calculate bullet direction
	Vec2 bulletDirection = target - m_Pos;
	bulletDirection.normalize();

	Vec2 bulletPos = m_Pos;

	// Add bullet to the game bullet vector
	Game& game = Game::get();
	
	// Rifle shot
	if (m_UsingRifle && m_Ammo > 0) 
	{
		game.createBullet(bulletPos, bulletDirection, m_isEnemy, m_UsingRifle);
		
		m_Ammo -= 1;
		m_TimeSinceShot = 0;
	}
	else if (m_Ammo >= 3) // Shotgun shot
	{
		// Direct shot
		game.createBullet(bulletPos, bulletDirection, m_isEnemy, m_UsingRifle);

		// Clockwise shift
		float degRadians = SHOTGUN_BULLET_ANGLE * (PI / 180);
		float xPos = cos(degRadians) * bulletDirection.x - sin(degRadians) * bulletDirection.y;
		float yPos = sin(degRadians) * bulletDirection.x + cos(degRadians) * bulletDirection.y;
		
		game.createBullet(bulletPos, Vec2(xPos, yPos), m_isEnemy, m_UsingRifle);

		// Counter Clockwise shift
		xPos = cos(-degRadians) * bulletDirection.x - sin(-degRadians) * bulletDirection.y;
		yPos = sin(-degRadians) * bulletDirection.x + cos(-degRadians) * bulletDirection.y;

		game.createBullet(bulletPos, Vec2(xPos, yPos), m_isEnemy, m_UsingRifle);

		m_Ammo -= 3;
		m_TimeSinceShot = 0;
	}
}

// Deal damage and check if Entity is dead
const void Entity::takeDamage()
{
	m_Health -= 1;
	if (!(m_Health > 0))
	{
		m_isDead = true;
	}
}
