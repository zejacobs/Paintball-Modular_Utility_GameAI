
#include "Vec2.h"
#include "Constants.h"

float Vec2::normalize()
{
    const float mag = length();
    if (mag <= 0.00001f)
    {
        x = y = 0.f;
        return 0.f;
    }

    *this /= mag;
    return mag;
}

// ADDED PROJECT 2
// Determines if the passed position vector point is left or right of the line segement created from
// making a vector from this vector to the segementEnd vector using the cross product.
float Vec2::crossProduct(Vec2 segmentEnd, Vec2 point) const
{
    return ((segmentEnd.x - x) * (point.y - y) - (segmentEnd.y - y) * (point.x - x));
}