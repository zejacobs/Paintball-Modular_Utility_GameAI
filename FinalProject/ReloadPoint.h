/*
* The Reload point class represents an area on the map where the player and enemies
* can reload their bullets
*/
#pragma once

#include "Vec2.h"
#include "Entity.h"

class ReloadPoint {

public:
	ReloadPoint(const Vec2& pos) { m_Pos = pos; }

	Vec2 getPosition() { return m_Pos; }

	void reloadEntity(Entity* entity);

private:
	Vec2 m_Pos;
};