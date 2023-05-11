#pragma once

#include <cmath>
#include <iostream>
#include <stdio.h>

class Vec2 {
public:
    float x;
    float y;

    Vec2() : x(-FLT_MAX), y(-FLT_MAX) {}
    Vec2(int inX, int inY) : x((float)inX), y((float)inY) {}
    Vec2(float inX, float inY) : x(inX), y(inY) {}
    Vec2(const Vec2& rhs) : x(rhs.x), y(rhs.y) {}

    bool operator==(const Vec2& rhs) const { return (x == rhs.x) && (y == rhs.y); }
    bool operator!=(const Vec2& rhs) const { return (x != rhs.x) || (y != rhs.y); }

    Vec2& operator=(const Vec2& rhs) { x = rhs.x; y = rhs.y; return *this; }

    Vec2 operator+(const Vec2& rhs) const { return Vec2(x + rhs.x, y + rhs.y); }
    Vec2& operator+=(const Vec2& rhs) { x += rhs.x; y += rhs.y; return *this; }

    Vec2 operator-(const Vec2& rhs) const { return Vec2(x - rhs.x, y - rhs.y); }
    Vec2& operator-=(const Vec2& rhs) { x -= rhs.x; y -= rhs.y; return *this; }

    Vec2 operator*(const float f) const { return Vec2(x * f, y * f); }
    Vec2& operator*=(const float f) { x *= f; y *= f; return *this; }

    Vec2 operator/(const float f) const { return Vec2(x / f, y / f); }
    Vec2& operator/=(const float f) { x /= f; y /= f; return *this; }

    float lengthSqr() const { return x * x + y * y; }
    float length() const { return sqrt(lengthSqr()); }

    float distSqr(Vec2 other) const { return (other - *this).lengthSqr(); }
    float dist(Vec2 other) const { return (other - *this).length(); }

    // Returns the previous length.  If the length is too short to normalize,
    //  sets the vector to (0,0) and returns 0.
    float normalize();

    // ADDED PROJECT 2
    float crossProduct(Vec2 segmentEnd, Vec2 point) const;

private:
    // DELIBERATELY UNDEFINED
    bool operator<(const Vec2& rhs) const;
};
