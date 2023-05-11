#pragma once

#include "FloatFunctor.h"
#include "Vec2.h"

class MoveIndirectlyTowards : FloatFunctor {

public:

	float operator()(Vec2 enemyPos, Vec2 enemyDestination, Vec2 playerPos);

};