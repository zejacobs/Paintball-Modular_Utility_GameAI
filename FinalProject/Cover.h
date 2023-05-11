/*
* The Cover class represents an obstacle on the game map that an Entity can stand behind to
* gain cover from Bullets. A Bullet will not pass through a Cover and hit an Entity.
*/
#pragma once

#include "Vec2.h"

class Cover {

public:
	Cover(const Vec2& pos) { m_Pos = pos; }

	Vec2 getPosition() { return m_Pos; }
private:
	Vec2 m_Pos;
};