/*
* The Player class represents the user controlled playable game entity.
*/
#pragma once

#include "Entity.h"
#include "Vec2.h"
#include "Constants.h"

class Player : public Entity {

public:
	Player(const Vec2& pos);

	void tick(float deltaTSec);

	void move(float deltaTSec);

	void updateMoveInput(int direction, bool isMoving);

	void resetHealth() { m_Health = PLAYER_MAX_HEALTH; }

	void updateWeapon() { m_UsingRifle = !m_UsingRifle; }


private:
	// Stores the movement input from the keyboard. If element is true than that direction key is pressed
	// Order of directions in array are up, down, left, right
	bool m_MoveInput[4] = { false, false, false, false };

};
