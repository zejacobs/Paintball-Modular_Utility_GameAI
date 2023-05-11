#pragma once

#include "ActionOption.h"
#include "GenerateAllCover.h"
#include "EvaluateCoverPosition.h"
#include "Vec2.h"


class MoveToCover : public ActionOption {

public:

	MoveToCover(Vec2 enemyPos, Vec2 playerPos, std::vector<Cover*> covers);

	Vec2 getCoverPos() { return m_CoverPos; }

private:

	void evaluate(Vec2 enemyPos, Vec2 playerPos, std::vector<Cover*> covers);

	Vec2 m_CoverPos;

};