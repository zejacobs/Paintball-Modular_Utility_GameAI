#include "EvaluateTakeShot.h"
#include "LineOfSight.h"
#include "TargetInRange.h"

float EvaluateTakeShot::operator()(Vec2 enemyPos, Vec2 playerPos, std::vector<Cover*> covers, float weaponRange)
{
	TargetInRange targetInRange;
	LineOfSight lineOfSight;
	float evaluation = 0.f;

	float rangeFactor = targetInRange(enemyPos, playerPos, weaponRange);
	float sightFactor = lineOfSight(enemyPos, playerPos, covers);

	evaluation = 2.f * (sightFactor * rangeFactor);

	return evaluation;
}
