#include "GenerateCoverPosition.h"

Vec2 GenerateCoverPosition::operator()(Cover* cover, Vec2 playerPos)
{
	Vec2 coverDir = cover->getPosition() - playerPos;
	coverDir.normalize();

	float coverOffset = (ENTITY_SIZE + COVER_SIZE) / 2.f;

	Vec2 coverPos = cover->getPosition() + (coverDir * coverOffset);

	return coverPos;
}
