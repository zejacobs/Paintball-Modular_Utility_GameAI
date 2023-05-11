/*
* Checks if target is in range of the equipped enemy weapon. Preference made to being within
* 70% of weapon range with slight penalty if greater than that until weapon max range
*/
#pragma once

#include "FloatFunctor.h"
#include "Vec2.h"

class TargetInRange : FloatFunctor {

public:

	float operator()(Vec2 enemyPos, Vec2 playerPos, float weaponRange);

};