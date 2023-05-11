#include "MoveTowardPlayer.h"
#include "Distance.h"

float MoveTowardPlayer::operator()(Vec2 enemyPos, Vec2 destPos, Vec2 playerPos)
{
	Distance distance;

	float currDistToPlayer = distance(enemyPos, playerPos);
	float destDistToPlayer = distance(destPos, playerPos);

	// Moving away from player
	if (destDistToPlayer > currDistToPlayer)
	{
		return 1.f;
	}
	else // Moving towards player, exponentially penalize the closer enemy gets
	{
		float distRatio = destDistToPlayer / currDistToPlayer;
		return pow(distRatio, 2);
	}
}
