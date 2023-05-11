/*
* Checks the need for ammo based on the current ammo of the enemy. A rotated quadratic
* curve is used to put more emphasis on needing ammo when ammo is very low
*/
#pragma once

#include "FloatFunctor.h"

class NeedsAmmo : FloatFunctor {

public:

	float operator()(int ammo);

};