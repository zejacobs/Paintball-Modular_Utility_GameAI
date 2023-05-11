#include "EvaluateAmmoNeed.h"
#include "NeedsAmmo.h"
#include "MoveTowardPlayer.h"
#include "Distance.h"

float EvaluateAmmoNeed::operator()(int ammo, Vec2 enemyPos, Vec2 playerPos, Vec2 reloadPos)
{
	NeedsAmmo needsAmmo;
	MoveTowardPlayer moveTowardPlayer;
	Distance distance;

	// Check remaining ammo factor
	float ammoFactor = needsAmmo(ammo);

	// Penalize for moving towards player
	float towardPlayerFactor = moveTowardPlayer(enemyPos, reloadPos, playerPos);

	float distanceFactor = distance(enemyPos, reloadPos) / MAX_RELOAD_TRAVEL_DIST;

	return (distanceFactor/2.f + ammoFactor*2.f) * towardPlayerFactor;

}
