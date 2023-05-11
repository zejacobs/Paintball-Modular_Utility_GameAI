#include "MoveToReload.h"

MoveToReload::MoveToReload(int ammo, Vec2 enemyPos, Vec2 playerPos, std::vector<ReloadPoint*> reloads)
{
	m_Priority = 2;
	evaluate(ammo, enemyPos, playerPos, reloads);
}

void MoveToReload::evaluate(int ammo, Vec2 enemyPos, Vec2 playerPos, std::vector<ReloadPoint*> reloads)
{
	EvaluateAmmoNeed evaluateAmmoNeed;

	float maxEval = 0.f;
	for (ReloadPoint* reload : reloads)
	{
		float currEval = evaluateAmmoNeed(ammo, enemyPos, playerPos, reload->getPosition());
		if (currEval > maxEval)
		{
			maxEval = currEval;
			m_ReloadPos = reload->getPosition();
		}
	}
	
	m_Evaluation = maxEval;
}
