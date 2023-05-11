
#include "Player.h"

#include "Constants.h"
#include <assert.h>

Player::Player(const Vec2& pos) : Entity(pos, true)
{
	m_Health = PLAYER_MAX_HEALTH;
	m_isEnemy = false;
}

void Player::tick(float deltaTSec)
{
	m_TimeSinceShot += deltaTSec;
	move(deltaTSec);
}

void Player::move(float deltaTSec)
{
	float moveDist = PLAYER_SPEED * deltaTSec;
	Vec2 moveDirection = Vec2(0.f, 0.f);
	
	if (m_MoveInput[0]) {
		moveDirection += Vec2(0.f, -1.f); // up
	}
	if (m_MoveInput[1]) {
		moveDirection += Vec2(0.f, 1.f); // down
	}
	if (m_MoveInput[2]) {
		moveDirection += Vec2(-1.f, 0.f); // left
	}
	if (m_MoveInput[3]) {
		moveDirection += Vec2(1.f, 0.f); // right
	}

	moveDirection.normalize();
	m_Pos += moveDirection * moveDist;

	// Check that player is on screen and adjust if needed
	if (m_Pos.x - ENTITY_SIZE / 2 < 0) {
		m_Pos.x = ENTITY_SIZE / 2;
	}
	if (m_Pos.x + ENTITY_SIZE / 2 >= GAME_GRID_WIDTH) {
		m_Pos.x = GAME_GRID_WIDTH - ENTITY_SIZE / 2;
	}
	if (m_Pos.y - ENTITY_SIZE / 2 < 0) {
		m_Pos.y = ENTITY_SIZE / 2;
	}
	if (m_Pos.y + ENTITY_SIZE / 2 >= GAME_GRID_HEIGHT) {
		m_Pos.y = GAME_GRID_HEIGHT - ENTITY_SIZE / 2;
	}

}

void Player::updateMoveInput(int direction, bool isMoving)
{
	// Check within array bounds
	assert(direction >= 0 && direction <= 3);

	m_MoveInput[direction] = isMoving;
}
