#pragma once

#include "ActionOption.h"
#include "EvaluateAmmoNeed.h"

class MoveToReload : public ActionOption {

public:

	MoveToReload(int ammo, Vec2 enemyPos, Vec2 playerPos, std::vector<ReloadPoint*> reloads);

	void evaluate(int ammo, Vec2 enemyPos, Vec2 playerPos, std::vector<ReloadPoint*> reloads);

	Vec2 getReloadPos() { return m_ReloadPos; }

private:

	Vec2 m_ReloadPos;

};