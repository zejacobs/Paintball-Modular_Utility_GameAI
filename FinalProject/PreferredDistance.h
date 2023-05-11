#pragma once

#include "FloatFunctor.h"

class PreferredDistance : FloatFunctor {

public:
	
	virtual float operator()(float distToCover);

};