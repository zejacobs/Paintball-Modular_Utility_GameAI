#include "EvaluateCoverPosition.h"
#include "MoveIndirectlyTowards.h"
#include "PreferredDistance.h"
#include "Distance.h"


float EvaluateCoverPosition::operator()(Vec2 enemyPos, Vec2 coverPos, Vec2 playerPos)
{
	float evaluation = 0.f;

	PreferredDistance preferredDistance;
	Distance distance;
	evaluation += preferredDistance(distance(enemyPos, coverPos));

	MoveIndirectlyTowards moveIndirectlyTowards;
	evaluation += moveIndirectlyTowards(enemyPos, coverPos, playerPos);

	return evaluation;
}
