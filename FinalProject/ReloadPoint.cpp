#include "ReloadPoint.h"
#include "Constants.h"

void ReloadPoint::reloadEntity(Entity* entity)
{
	float reloadLeft = m_Pos.x - RELOAD_SIZE / 2.f;
	float reloadRight = m_Pos.x + RELOAD_SIZE / 2.f;
	float reloadTop = m_Pos.y - RELOAD_SIZE / 2.f;
	float reloadBottom = m_Pos.y + RELOAD_SIZE / 2.f;

	float entityLeft = entity->getPosition().x - ENTITY_SIZE / 2.f;
	float entityRight = entity->getPosition().x + ENTITY_SIZE / 2.f;
	float entityTop = entity->getPosition().y - ENTITY_SIZE / 2.f;
	float entityBottom = entity->getPosition().y + ENTITY_SIZE / 2.f;

	if (entityLeft >= reloadLeft && entityRight <= reloadRight
		&& entityTop >= reloadTop && entityBottom <= reloadBottom)
	{
		entity->reloadAmmo();
	}

}