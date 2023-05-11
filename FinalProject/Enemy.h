/*
* The Enemy class represents the AI controlled entities oppossing the user player
*/
#pragma once

#include "Entity.h"
#include "Vec2.h"

class Enemy : public Entity {

public:
	Enemy(const Vec2& pos, bool usingRifle);

	void tick(float deltaTSec);

	void evaluateOptions();

	void move(float deltaTSec) ;

private:

	Vec2 m_targetPos;
	float m_TimeSinceAction;
	bool m_isMoving;

};