#include "ShootAtPlayer.h"

ShootAtPlayer::ShootAtPlayer(Vec2 enemyPos, Vec2 playerPos, std::vector<Cover*> covers, float weaponRange)
{
	m_Priority = 2;
	evaluate(enemyPos, playerPos, covers, weaponRange);
}

void ShootAtPlayer::evaluate(Vec2 enemyPos, Vec2 playerPos, std::vector<Cover*> covers, float weaponRange)
{
	EvaluateTakeShot evaluateTakeShot;

	m_Evaluation = evaluateTakeShot(enemyPos, playerPos, covers, weaponRange);
}
