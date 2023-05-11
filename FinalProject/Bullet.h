/*
*	A bullet represents a projectile fired by the player or enemy entiies
*/
#pragma once

#include "Vec2.h"
#include "Entity.h"
#include "Cover.h"

class Bullet
{

public:
	Bullet(const Vec2& startPos, const Vec2& direction, bool fromEnemy, bool fromRifle);
	~Bullet() {}

	void tick(float deltaTSec);

	Vec2& getPosition() { return m_Pos; }

	bool isFromEnemy() { return m_fromEnemy; }

	bool isDead() { return m_isDead; }
	void setDead(bool isDead) { m_isDead = isDead; }

	void move(float deltaTSec);

	bool checkCollision(Entity* entity);
	bool checkCollision(Cover* cover);

private:
	Vec2 m_Pos;
	Vec2 m_Direction;
	float m_Range;
	float m_Speed;
	float m_DistanceTraveled;
	bool m_fromEnemy;
	bool m_isDead;
};