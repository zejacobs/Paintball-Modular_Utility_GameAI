#include "GenerateAllCover.h"
#include "GenerateCoverPosition.h"

std::vector<Vec2> GenerateAllCover::operator()(std::vector<Cover*> covers, Vec2 playerPos)
{
	std::vector<Vec2> coverPositions;

	GenerateCoverPosition generateCoverPosition;

	for (Cover* cover : covers)
	{
		coverPositions.push_back(generateCoverPosition(cover, playerPos));
	}

	return coverPositions;
}
