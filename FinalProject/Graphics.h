#pragma once
/*
	Contains the SDL graphics implementation for the game.
*/

#include "SDL.h"
#include "Singleton.h"
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"
#include "ReloadPoint.h"
#include <vector>

class Graphics : public Singleton<Graphics> {

public:
	Graphics();
	virtual ~Graphics();  //SDL_DestroyRenderer(gRenderer);

	void resetFrame();

	void drawPlayer(Player* player);
	void drawEnemies(std::vector<Enemy*> enemies);
	void drawCovers(std::vector<Cover*> covers);
	void drawReloads(std::vector<ReloadPoint*> reloads);
	void drawBullets(std::vector<Bullet*> bullets);

	void drawUI(Player* player);

	void render();


private:
	void drawBG();
	void drawGrid();
	void drawSquare(float centerX, float centerY, float size);

	SDL_Renderer* gRenderer;
	SDL_Window* gWindow;
};