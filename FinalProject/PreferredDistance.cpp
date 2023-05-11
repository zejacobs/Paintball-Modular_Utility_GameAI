#include "PreferredDistance.h"
#include "Distance.h"
#include "Constants.h"


float PreferredDistance::operator()(float distToDestination)
{
	float distDiff = abs(distToDestination - PREFERRED_COVER_DIST);

	float distRatio = distDiff / MAX_COVER_TRAVEL_DIST;

	return 1 - distRatio;
}
