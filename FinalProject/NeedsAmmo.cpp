#include "NeedsAmmo.h"
#include "Constants.h"

float NeedsAmmo::operator()(int ammo)
{
	// If over half ammo don't consider a reload
	if (ammo > 10)
	{
		return -100.f;
	}
	
	float ammoFraction = ammo / ENTITY_MAX_AMMO;

	return 1 - pow(ammoFraction, 0.5f);
}
