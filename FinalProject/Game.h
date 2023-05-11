/*
* Contains all of the information regarding the gamestate and proccessing game entity interactions
*/
#pragma once

#include "Singleton.h"
#include "Vec2.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Cover.h"
#include "ReloadPoint.h"
#include <vector>

class Game : public Singleton<Game>
{
public:
    explicit Game();
    virtual ~Game();

    void tick(float deltaTSec);

    Player* getPlayer() { return m_Player; }
    std::vector<Enemy*> getEnemies() { return m_Enemies; }
    std::vector<Bullet*> getBullets() { return m_Bullets; }
    std::vector<Cover*> getCovers() { return m_Covers; }
    std::vector<ReloadPoint*> getReloads() { return m_Reloads; }

    void createBullet(Vec2 origin, Vec2 direction, bool fromEnemy, bool fromRifle);

    void processBulletHits();

    void processReloads();

    void loadLevel();
    void incrementLevel() { m_Level++; }

    bool  isGameOver();

    int getPlayerScore() { return m_DeadEnemies.size(); }

private:
    Player* m_Player;
    std::vector<Enemy*> m_Enemies;
    std::vector<Bullet*> m_Bullets;
    std::vector<Cover*> m_Covers;
    std::vector<ReloadPoint*> m_Reloads;

    std::vector<Enemy*> m_DeadEnemies;
    std::vector<Bullet*> m_DeadBullets;

    int m_Level = 0;
};
