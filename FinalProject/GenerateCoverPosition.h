/*
* Generates a cover position given a Cover and the player's position to find cover from.
*/
#pragma once

#include "Cover.h"
#include "Vec2.h"
#include "Constants.h"

class GenerateCoverPosition {

public:

	Vec2 operator()(Cover* cover, Vec2 playerPos);

};