/*
*	An entity represents any player or enemy character within the game.
*/
#pragma once

#include "Vec2.h"
#include "Constants.h"

class Entity {

public:
	Entity(const Vec2& pos, bool usingRifle);
	virtual ~Entity() {}

	virtual void tick(float deltaTSec) = 0;

	virtual void move(float deltaTSec) = 0;

	virtual const Vec2& getPosition() const { return m_Pos; }
	virtual const void setPosition(const Vec2& pos) { m_Pos = pos; }

	virtual const int getHealth() const { return m_Health;  }

	virtual const int isUsingRifle() const { return m_UsingRifle; }

	virtual const int getAmmo() const { return m_Ammo; }

	virtual const void reloadAmmo() { m_Ammo = ENTITY_MAX_AMMO; }

	virtual const bool isDead() const { return m_isDead; }

	virtual const void shoot(Vec2& target);

	virtual const void takeDamage();

	

protected:
	Vec2 m_Pos;
	int m_Health;
	int m_Ammo;
	bool m_isEnemy;
	bool m_isDead;
	bool m_UsingRifle;
	float m_TimeSinceShot;

};