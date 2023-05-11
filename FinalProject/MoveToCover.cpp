#include "MoveToCover.h"

MoveToCover::MoveToCover(Vec2 enemyPos, Vec2 playerPos, std::vector<Cover*> covers)
{
	m_Priority = 1;
	evaluate(enemyPos, playerPos, covers);
}

void MoveToCover::evaluate(Vec2 enemyPos, Vec2 playerPos, std::vector<Cover*> covers)
{
	GenerateAllCover generateAllCover;
	EvaluateCoverPosition evaluateCoverPosition;

	float maxEval = 0.f;
	for (Vec2 coverPos : generateAllCover(covers, playerPos))
	{
		float currentEval = evaluateCoverPosition(enemyPos, coverPos, playerPos);

		if (currentEval > maxEval)
		{
			m_CoverPos = coverPos;
			maxEval = currentEval;
		}
	}

	m_Evaluation = maxEval;
}
