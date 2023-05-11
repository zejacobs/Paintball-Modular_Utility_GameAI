#include "MoveIndirectlyTowards.h"
#include "Constants.h"


float MoveIndirectlyTowards::operator()(Vec2 enemyPos, Vec2 enemyDestination, Vec2 playerPos)
{
	Vec2 enemyToPlayer = playerPos - enemyPos;
	enemyToPlayer.normalize();

	Vec2 enemyToDestination = enemyDestination - enemyPos;
	enemyToDestination.normalize();

	float dotProduct = (enemyToPlayer.x * enemyToDestination.x) + (enemyToPlayer.y * enemyToDestination.y);

	// Angle between enemy move vector to destination and enemy move vector to player
	float angleBetweenDirections = acos(dotProduct) * (180.f / PI);
	
	// Difference between preffered angle between player/cover directions and actual angle
	float diffFromPreferred = abs(angleBetweenDirections - PREFERRED_APPROACH_ANGLE);

	float angleRatio = diffFromPreferred / MAX_APPROACH_ANGLE_DIFF;
	
	return 1 - angleRatio;
}
