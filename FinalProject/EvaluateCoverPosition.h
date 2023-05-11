/*
* Evaluates the preferrence towards a cover postion by taking into account 
* how far the cover point is relative to the enemies preferred travel distance
* between covers and the degree to which the enemy advances towards the enemy 
* but not directly towards them 
*/
#pragma once

#include "FloatFunctor.h"
#include "Vec2.h"

class EvaluateCoverPosition : FloatFunctor {

public:

	float operator()(Vec2 enemyPos, Vec2 coverPos, Vec2 playerPos);

};