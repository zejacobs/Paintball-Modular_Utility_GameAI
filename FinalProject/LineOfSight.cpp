#include "LineOfSight.h"
#include "Distance.h"
#include "Constants.h"

float LineOfSight::operator()(Vec2 enemyPos, Vec2 playerPos, std::vector<Cover*> covers)
{
    // Check if enemy has an unobstructed line of sight from their
    // center position to the player's center position
    Vec2 topLeft; // top left corner of cover
    float topLSide;
    Vec2 topRight; // top right corner of cover
    float topRSide;
    Vec2 bottomLeft; // bottom left corner of cover
    float bottomLSide;
    Vec2 bottomRight; // bottom right corner of cover
    float bottomRSide;
    float shift = COVER_SIZE / 2.f;; // Half the cover size

    Distance distance;

    for (Cover* cover: covers)
    {
        float maxX = std::max(enemyPos.x, playerPos.x);
        float minX = std::min(enemyPos.x, playerPos.x);
        float maxY = std::max(enemyPos.y, playerPos.y);
        float minY = std::min(enemyPos.y, playerPos.y);

        //std::cout<<"minX " << minX << "   maxX:: " << maxX << "\n";

        // Check if cover is between enemy and player
        if (cover->getPosition().x < minX || cover->getPosition().x > maxX
            || cover->getPosition().y < minY || cover->getPosition().y > maxY)
        {
            //std::cout << "SKIPPED\n";
            continue;
        }

        topLeft = cover->getPosition() + Vec2(-shift, -shift);
        topRight = cover->getPosition() + Vec2(shift, -shift);
        bottomLeft = cover->getPosition() + Vec2(-shift, shift);
        bottomRight = cover->getPosition() + Vec2(shift, shift);

        topLSide = enemyPos.crossProduct(playerPos, topLeft);
        topRSide = enemyPos.crossProduct(playerPos, topRight);
        bottomLSide = enemyPos.crossProduct(playerPos, bottomLeft);
        bottomRSide = enemyPos.crossProduct(playerPos, bottomRight);

        // Check that all vertices of the square are on the same side of the line segment
        // between the enemy and player's center positions
        if ((topLSide > 0 && topRSide > 0 && bottomLSide > 0 && bottomRSide > 0)
            || (topLSide < 0 && topRSide < 0 && bottomLSide < 0 && bottomRSide < 0))
        {
            // line of sight is not obstructed by cover
        }
        else
        {
            std::cout<< "blocked at " << cover->getPosition().x << ", " << cover->getPosition().y << "\n";
            return 0.f; // A cover was found blocking the line of sight
        }
    }

    // No cover obstruction line of sight
	return 1.f;
}
