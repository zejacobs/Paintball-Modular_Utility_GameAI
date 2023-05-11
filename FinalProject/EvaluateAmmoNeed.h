/*
* Evaluates the degree to which the entity should go get to a reload point for ammo based
* on their remaining ammo and their distance from the closest reload point
*/
#pragma once

#include "FloatFunctor.h"
#include "Vec2.h"
#include "ReloadPoint.h"
#include <vector>

class EvaluateAmmoNeed : FloatFunctor {

public:

	float operator()(int ammo, Vec2 enemyPos, Vec2 playerPos, Vec2 reloadPos);

};