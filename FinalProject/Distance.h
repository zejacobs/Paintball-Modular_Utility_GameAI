#pragma once

#include "FloatFunctor.h"
#include "Vec2.h"

class Distance : FloatFunctor {

public:

	float operator()(Vec2 pos1, Vec2 pos2) { return pos1.dist(pos2); }

};