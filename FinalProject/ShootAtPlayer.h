#pragma once

#include "ActionOption.h"
#include "EvaluateTakeShot.h"
#include "Vec2.h"

class ShootAtPlayer : public ActionOption {

public:

	ShootAtPlayer(Vec2 enemyPos, Vec2 playerPos, std::vector<Cover*> covers, float weaponRange);

private:

	void evaluate(Vec2 enemyPos, Vec2 playerPos, std::vector<Cover*> covers, float weaponRange);

};