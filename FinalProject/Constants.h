/*
	Contains the constant values used in the game setup and gameplay
*/
#pragma once

#include "Vec2.h"
#include <vector>

// Window/Screen dimensions
const int PIXELS_PER_METER = 30;

const int GAME_GRID_WIDTH = 36;
const int GAME_GRID_HEIGHT = 26;

const int UI_WIDTH = GAME_GRID_WIDTH;
const int UI_HEIGHT = 2;

const int SCREEN_WIDTH_PIXELS = PIXELS_PER_METER * GAME_GRID_WIDTH;
const int SCREEN_HEIGHT_PIXELS = PIXELS_PER_METER * (GAME_GRID_HEIGHT + UI_HEIGHT);

// Tick limitations
const float TICK_MIN = .0333333f;
const float TICK_MAX = 0.2f;

// Game move/collision calculations performed per tick
const int PHYSICS_RUN_PER_TICK = 2;

// Entity Constants
const float ENTITY_SIZE = .5f;
const float ENTITY_MAX_AMMO = 20.f;
const float ENTITY_RELOAD_TIME = 1.f;

// Player Constants
const float PLAYER_START_X = GAME_GRID_WIDTH / 2;
const float PLAYER_START_Y = GAME_GRID_HEIGHT - 1;

const int PLAYER_MAX_HEALTH = 5;
const float PLAYER_SPEED = 3.f;

// Enemy Constants
const int ENEMY_MAX_HEALTH = 1;
const float ENEMY_SPEED = 2.5f;
const float ENEMY_SIGHT_DIST = 18.f;

const Vec2 ENEMY_SPAWN_POSITIONS[] = { Vec2(1, 1), Vec2(10, 1), Vec2(18, 1), Vec2(27, 1), Vec2(35, 1),
									   Vec2(1, 7), Vec2(7, 5),  Vec2(18, 7), Vec2(19, 5), Vec2(35, 7),
									   Vec2(12, 11), Vec2(18, 11), Vec2(24, 11)};

// Cover constants
const float COVER_SIZE = 1.f;

const Vec2 TEST_COVER_POSITIONS[] = { Vec2(12, 4), Vec2(18, 4), Vec2(24, 4),
									  Vec2(12, 8), Vec2(18, 8), Vec2(24, 8),
									  Vec2(12, 12), Vec2(18, 12), Vec2(24, 12),
									  Vec2(12, 16), Vec2(18, 16), Vec2(24, 16),
									  Vec2(12, 20), Vec2(18, 20), Vec2(24, 20), };

const Vec2 COVER_POSITIONS[] = { Vec2(3, 2),  Vec2(10, 3),  Vec2(14, 2),  Vec2(18, 3),  Vec2(22, 2),  Vec2(26, 3),  Vec2(34, 2),
								 Vec2(2, 9),  Vec2(4, 6),   Vec2(14, 6),  Vec2(22, 6),  Vec2(32, 6),  Vec2(34, 9),
								 Vec2(6, 11), Vec2(9, 8),   Vec2(18, 9),  Vec2(27, 8),  Vec2(30, 11),
								 Vec2(2, 13), Vec2(6, 15),  Vec2(12, 13), Vec2(18,13),  Vec2(24, 13), Vec2(30, 15), Vec2(34, 13),
								 Vec2(4, 20), Vec2(9, 18),  Vec2(14, 18), Vec2(18, 17), Vec2(22, 18), Vec2(27, 18), Vec2(32, 20),
								 Vec2(2, 34), Vec2(7, 24),  Vec2(14, 24), Vec2(18, 23), Vec2(22, 24), Vec2(29, 24), Vec2(24, 34) };

// Bullet Constants
const float BULLET_SIZE = 0.25f;
const float BULLET_SPEED = 22.f;

// ReloadPoint Constants
const float RELOAD_SIZE = 2;

const Vec2 RELOAD_POSITIONS[] = { Vec2(18, 1), Vec2(18, 25) };


// Weapon Stats
const float RIFLE_BULLET_SPEED = 18.f;
const float RIFLE_BULLET_RANGE = 15.f;
const float RIFLE_RELOAD_TIME = .25f;

const float SHOTGUN_BULLET_SPEED = 12.f;
const float SHOTGUN_BULLET_RANGE = 7.5f;
const float SHOTGUN_BULLET_ANGLE = 10.f;
const float SHOTGUN_RELOAD_TIME = 1.f;

// Modular AI Constants
const float PREFERRED_COVER_DIST = 5.f;
const float MAX_COVER_TRAVEL_DIST = 10.f;

const float PREFERRED_APPROACH_ANGLE = 45.f;
const float MAX_APPROACH_ANGLE_DIFF = 45.f;
const float PI = 3.1416;

const float MAX_RELOAD_TRAVEL_DIST = 24.f;