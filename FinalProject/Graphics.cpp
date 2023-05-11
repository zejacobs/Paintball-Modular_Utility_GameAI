#include "Graphics.h"

#include "Game.h"
#include "Constants.h"
#include "Vec2.h"
#include <algorithm>

Graphics* Singleton<Graphics>::s_Obj = NULL;

Graphics::Graphics() {
    gWindow = SDL_CreateWindow("Final Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH_PIXELS, SCREEN_HEIGHT_PIXELS, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
        gRenderer = NULL;
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
    }
    else {
        //Create renderer for window
        gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
        if (gRenderer == NULL) {
            printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        }
        else {
            //Initialize renderer color
            SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        }
    }
}

Graphics::~Graphics() {
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
}

void Graphics::render() {
    SDL_RenderPresent(gRenderer);
}

void Graphics::drawPlayer(Player* player)
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255); // blue

    float playerPosX = player->getPosition().x * PIXELS_PER_METER;
    float playerPosY = player->getPosition().y * PIXELS_PER_METER;
    float playerSize = ENTITY_SIZE * PIXELS_PER_METER;
    drawSquare(playerPosX, playerPosY, playerSize);
}

void Graphics::drawEnemies(std::vector<Enemy*> enemies)
{
    for (Entity* enemy : enemies)
    {
        if (enemy->isUsingRifle()) // Riflemen drawn red
        {
            SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255); // red
        }
        else // Shotgunners drawn orange
        {
            SDL_SetRenderDrawColor(gRenderer, 255, 165, 0, 255); // orange
        }

        float enemyPosX = enemy->getPosition().x * PIXELS_PER_METER;
        float enemyPosY = enemy->getPosition().y * PIXELS_PER_METER;
        float enemySize = ENTITY_SIZE * PIXELS_PER_METER;
        drawSquare(enemyPosX, enemyPosY, enemySize);
    }
}

void Graphics::drawCovers(std::vector<Cover*> covers)
{
    SDL_SetRenderDrawColor(gRenderer, 150, 75, 0, 255); // brown

    for (Cover* cover : covers)
    {
        float coverPosX = cover->getPosition().x * PIXELS_PER_METER;
        float coverPosY = cover->getPosition().y * PIXELS_PER_METER;
        float coverSize = COVER_SIZE * PIXELS_PER_METER;
        drawSquare(coverPosX, coverPosY, coverSize);
    }
}

void Graphics::drawReloads(std::vector<ReloadPoint*> reloads)
{
    SDL_SetRenderDrawColor(gRenderer, 1, 80, 32, 255); // brown

    for (ReloadPoint* reload : reloads)
    {
        float reloadPosX = reload->getPosition().x * PIXELS_PER_METER;
        float reloadPosY = reload->getPosition().y * PIXELS_PER_METER;
        float reloadSize = RELOAD_SIZE * PIXELS_PER_METER;
        drawSquare(reloadPosX, reloadPosY, reloadSize);
    }
}

void Graphics::drawBullets(std::vector<Bullet*> bullets)
{
    // Set bullet color
    SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255); // green

    // Draw each bullet
    for (Bullet* bullet : bullets)
    {
        float bulletPosX = bullet->getPosition().x * PIXELS_PER_METER;
        float bulletPosY = bullet->getPosition().y * PIXELS_PER_METER;
        float bulletSize = BULLET_SIZE * PIXELS_PER_METER;
        drawSquare(bulletPosX, bulletPosY, bulletSize);
    }
}

void Graphics::drawBG()
{
    SDL_Rect bg = { 0, 0, SCREEN_WIDTH_PIXELS, GAME_GRID_HEIGHT * PIXELS_PER_METER };
    SDL_SetRenderDrawColor(gRenderer, 128, 128, 128, 255); // white
    SDL_RenderFillRect(gRenderer, &bg);
}

void Graphics::drawGrid() {
    SDL_SetRenderDrawColor(gRenderer, 100, 100, 100, 0xFF);
    // Draw Vert lines
    for (int xIndex = 0; xIndex < GAME_GRID_WIDTH + 1; xIndex++) {
        int xIndexPix = xIndex * PIXELS_PER_METER;
        SDL_RenderDrawLine(gRenderer,
            xIndexPix, 0,
            xIndexPix, GAME_GRID_HEIGHT * PIXELS_PER_METER);
    }

    // Draw Horiz lines
    for (int yIndex = 0; yIndex < GAME_GRID_HEIGHT; yIndex++) {
        int yIndexPix = yIndex * PIXELS_PER_METER;
        SDL_RenderDrawLine(gRenderer,
            0, yIndexPix,
            GAME_GRID_WIDTH * PIXELS_PER_METER, yIndexPix);
    }
}

void Graphics::drawUI(Player* player)
{
    SDL_Rect bg = { 0, GAME_GRID_HEIGHT * PIXELS_PER_METER, SCREEN_WIDTH_PIXELS, UI_HEIGHT * PIXELS_PER_METER };
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255); // black
    SDL_RenderFillRect(gRenderer, &bg);

    // Draw health
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255); // blue
    for (int i = 0; i < player->getHealth(); i++)
    {
        float healthSize = ENTITY_SIZE * PIXELS_PER_METER;
        drawSquare((9.f + i) * PIXELS_PER_METER, (GAME_GRID_HEIGHT + UI_HEIGHT/2.f) * PIXELS_PER_METER, healthSize);
    }
    
    // Draw Weapon type
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255); // white
    drawSquare(15 * PIXELS_PER_METER, (GAME_GRID_HEIGHT + UI_HEIGHT / 2.f) * PIXELS_PER_METER, 1.25f * PIXELS_PER_METER);
    
    SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255); // green
    if (player->isUsingRifle())
    {
        drawSquare(15 * PIXELS_PER_METER, (GAME_GRID_HEIGHT + UI_HEIGHT / 2.f) * PIXELS_PER_METER, .5f * PIXELS_PER_METER);
    }
    else
    {
        drawSquare(15 * PIXELS_PER_METER, (GAME_GRID_HEIGHT - .25f + UI_HEIGHT / 2.f) * PIXELS_PER_METER, .3f * PIXELS_PER_METER);
        drawSquare(15.25 * PIXELS_PER_METER, (GAME_GRID_HEIGHT + .25f + UI_HEIGHT / 2.f) * PIXELS_PER_METER, .3f * PIXELS_PER_METER);
        drawSquare(14.75 * PIXELS_PER_METER, (GAME_GRID_HEIGHT + .25f + UI_HEIGHT / 2.f) * PIXELS_PER_METER, .3f * PIXELS_PER_METER);
    }

    // Draw ammo
    SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255); // green
   
    float ammoSize = BULLET_SIZE * PIXELS_PER_METER;
    int ammo = player->getAmmo();
    for (int i = 0; i < ammo; i++)
    {       
        drawSquare((17 + i/2.f) * PIXELS_PER_METER, ((GAME_GRID_HEIGHT + 1) * PIXELS_PER_METER), ammoSize);
    }

}

void Graphics::resetFrame() {
    drawBG();
    drawGrid();
}

void Graphics::drawSquare(float centerX, float centerY, float size) {
    // Draws a square at the given pixel coorinate
    SDL_Rect rect = {
        (int)(centerX - (size / 2.f)),
        (int)(centerY - (size / 2.f)),
        (int)(size),
        (int)(size)
    };
    SDL_RenderFillRect(gRenderer, &rect);
}
