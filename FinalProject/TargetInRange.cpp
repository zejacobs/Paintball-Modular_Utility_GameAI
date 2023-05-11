#include "TargetInRange.h"
#include "Distance.h"


float TargetInRange::operator()(Vec2 enemyPos, Vec2 playerPos, float weaponRange)
{
	Distance distance;
	float distToTarget = distance(enemyPos, playerPos);

	// Target it is out of range of weapon
	if (distToTarget > weaponRange) {
		return -100.f;
	}

	float utility = 0.f;

	// Prefer to be atleast 60% of firing range away, add minor penalty to being further
	float preferredRange = weaponRange * 0.70f;

	if (distToTarget > preferredRange)
	{
		float rangeDiff = distToTarget - preferredRange;
		float maxDiff = weaponRange - preferredRange;

		utility = (rangeDiff / maxDiff);
	}
	else
	{
		utility = 1;
	}
	
	return utility;
}
