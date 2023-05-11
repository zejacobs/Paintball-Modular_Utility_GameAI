#include "Enemy.h"
#include "Game.h"
#include "Constants.h"

// ModularAI includes
#include "ActionOption.h"
#include "MoveToCover.h"
#include "ShootAtPlayer.h"
#include "MoveToReload.h"

Enemy::Enemy(const Vec2& pos, bool usingRifle) : Entity(pos, usingRifle)
{
	m_Health = ENEMY_MAX_HEALTH;
	m_isEnemy = true;
	m_targetPos = Vec2(20, 20);
	m_TimeSinceAction = FLT_MAX;

	m_isMoving = false;
}

void Enemy::tick(float deltaTSec)
{
	m_TimeSinceShot += deltaTSec;
	m_TimeSinceAction += deltaTSec;

	if (m_TimeSinceAction > 1.f)
	{
		evaluateOptions();
		m_TimeSinceAction = 0.f;
	}
	move(deltaTSec);
}

// Evaluates and decides best action to perform using Modular AI implementation
void Enemy::evaluateOptions()
{
	Game& game = Game::get();
	std::vector<Cover*> covers = game.getCovers();
	std::vector<ReloadPoint*> reloads = game.getReloads();
	Vec2 playerPos = game.getPlayer()->getPosition();

	// Move to cover Action
	MoveToCover moveToCover = MoveToCover(m_Pos, playerPos, covers);
	float coverEval = moveToCover.getEvaluation();
	// "Turn off" further cover evaluations if moving towards one
	if (m_isMoving)
	{
		coverEval = -1;
	}

	// Shoot at Player Action
	float weaponRange = m_UsingRifle ? RIFLE_BULLET_RANGE : SHOTGUN_BULLET_RANGE;
	ShootAtPlayer shootAtPlayer = ShootAtPlayer(m_Pos, playerPos, covers, weaponRange);
	float shootEval = shootAtPlayer.getEvaluation();
	// "Turn off" shoot at player action if not reloaded
	if (m_TimeSinceShot < (m_UsingRifle ? RIFLE_RELOAD_TIME : SHOTGUN_RELOAD_TIME))
	{
		shootEval = -1.f;
	}

	// Move to Reload Action
	MoveToReload moveToReload = MoveToReload(m_Ammo, m_Pos, playerPos, reloads);
	float reloadEval = moveToReload.getEvaluation();

	// DEBUG UTILITY SCORES
	std::cout << "cover: " << coverEval << "  shoot: " << shootEval << "  reload: " << reloadEval << "\n";

	if (coverEval > 0 && coverEval > shootEval && coverEval > reloadEval)
	{
		m_targetPos = moveToCover.getCoverPos();

		m_isMoving = true;
	}
	else if (reloadEval > 0 && reloadEval > coverEval && reloadEval > shootEval)
	{
		m_targetPos = moveToReload.getReloadPos();

		m_isMoving = true;
	}
	else if (shootEval > 0 && shootEval > coverEval && shootEval > reloadEval)
	{
		// ranomly offset shot slighty
		srand(time(NULL));
		float xShift = ((rand() % 100 + 1) - 50) / 100.f;
		float yShift = ((rand() % 100 + 1) - 50) / 100.f;
		Vec2 shotPos = playerPos + Vec2(xShift, yShift);
		shoot(shotPos);
	}

}

void Enemy::move(float deltaTSec)
{
	Vec2 moveDirection = m_targetPos - m_Pos;
	float distToTarget = moveDirection.normalize();
	float moveDist = ENEMY_SPEED * deltaTSec;
	
	if (moveDist > distToTarget) {
		moveDist = distToTarget;

		m_isMoving = false;
	}

	m_Pos += moveDirection * moveDist;

	// Check that enemy is on screen and adjust if needed
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
