
#include "Bullet.h"
#include "Constants.h"

Bullet::Bullet(const Vec2& startPos, const Vec2& direction, bool fromEnemy, bool fromRifle)
{		
	m_Pos = startPos;
	m_Direction = direction;
	m_DistanceTraveled = 0.f;
	m_fromEnemy = fromEnemy;
	m_isDead = false;

	if (fromRifle) {
		m_Speed = RIFLE_BULLET_SPEED;
		m_Range = RIFLE_BULLET_RANGE;
	}
	else {
		m_Speed = SHOTGUN_BULLET_SPEED;
		m_Range = SHOTGUN_BULLET_RANGE;
	}
}

void Bullet::tick(float deltaTSec)
{
	// Check if bullet has reached its range, if not move
	if (m_DistanceTraveled >= m_Range)
	{
		m_isDead = true;
	}
	else
	{
		move(deltaTSec);
	}
}

void Bullet::move(float deltaTSec)
{
	float moveDist = m_Speed  * deltaTSec;

	if (moveDist + m_DistanceTraveled > m_Range)
	{
		moveDist = m_Range - m_DistanceTraveled;
	}	

	m_Pos += m_Direction * moveDist;
	m_DistanceTraveled += moveDist;
}

bool Bullet::checkCollision(Entity* entity)
{
	Vec2 entityPos = entity->getPosition();

	float entityLeft = entityPos.x - ENTITY_SIZE/2.f;
	float entityRight = entityPos.x + ENTITY_SIZE/2.f;
	float entityTop = entityPos.y - ENTITY_SIZE/2.f;
	float entityBottom = entityPos.y + ENTITY_SIZE/2.f;

	float bulletLeft = m_Pos.x - BULLET_SIZE/2.f;
	float bulletRight = m_Pos.x + BULLET_SIZE/2.f;
	float bulletTop = m_Pos.y - BULLET_SIZE/2.f;
	float bulletBottom = m_Pos.y + BULLET_SIZE/2.f;

	return (entityLeft < bulletRight && entityRight > bulletLeft
		&& entityTop < bulletBottom && entityBottom > bulletTop);
}

bool Bullet::checkCollision(Cover* cover)
{
	Vec2 coverPos = cover->getPosition();

	float coverLeft = coverPos.x - COVER_SIZE / 2.f;
	float coverRight = coverPos.x + COVER_SIZE / 2.f;
	float coverTop = coverPos.y - COVER_SIZE / 2.f;
	float coverBottom = coverPos.y + COVER_SIZE / 2.f;

	float bulletLeft = m_Pos.x - BULLET_SIZE / 2.f;
	float bulletRight = m_Pos.x + BULLET_SIZE / 2.f;
	float bulletTop = m_Pos.y - BULLET_SIZE / 2.f;
	float bulletBottom = m_Pos.y + BULLET_SIZE / 2.f;

	return (coverLeft < bulletRight&& coverRight > bulletLeft
		&& coverTop < bulletBottom&& coverBottom > bulletTop);
}
