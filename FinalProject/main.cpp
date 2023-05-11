/*
*   Project runs from this file
*/

#include <iostream>
#include <SDL.h>
#include "Constants.h"
#include "Graphics.h"
#include "Game.h"
#include "Controller_UI.h"

#include <chrono>

int main(int argc, char* args[])
{
    Game& game = Game::get();
    Graphics& graphics = Graphics::get();
    Controller_UI& player = Controller_UI::get();

    //Set player controlled entity
    player.setPlayer(game.getPlayer());

    using namespace std::chrono;
    high_resolution_clock::time_point prevTime = high_resolution_clock::now();

    // Game Loop
    bool gameIsRunning = true;
    while (gameIsRunning)
    {
        // Get the elapsed time, and ensure it's at between TICK_MIN and TICK_MAX
        high_resolution_clock::time_point now = high_resolution_clock::now();
        double deltaTSec = (float)duration_cast<milliseconds>(now - prevTime).count() / 1000;
        if (deltaTSec > TICK_MAX)
        {
            std::cout << "Tick duration over budget: " << deltaTSec << std::endl;
            deltaTSec = TICK_MAX;
        }

        if (deltaTSec < TICK_MIN)
            continue;

        prevTime = now;

        // Load levels if needed
        if (game.getEnemies().size() <= 0)
        {
            game.incrementLevel();
            game.loadLevel();
        }

        graphics.resetFrame();

        // Handle user input
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT) {
                gameIsRunning = false;
            }
            
            if (Controller_UI::exists()) {
                Controller_UI::get().handleEvent(event, deltaTSec);
            }
        }

        // Load levels if needed
        if (game.getEnemies().size() <= 0)
        {
            game.loadLevel();
            game.incrementLevel();
        }

        // Update game state
        game.tick((float)deltaTSec);

        // Draw Entities and Bullets
        graphics.drawCovers(game.getCovers());
        graphics.drawReloads(game.getReloads());
        graphics.drawEnemies(game.getEnemies());
        graphics.drawPlayer(game.getPlayer());
        graphics.drawBullets(game.getBullets());
        
        graphics.drawUI(game.getPlayer());

        graphics.render();

        // Check if Game Over
        if (game.isGameOver())
        {
            SDL_Delay(3000);
            gameIsRunning = false;
        }
    }

    std::cout << "\n\n*** Game Over! ***\nYour Score: " << game.getPlayerScore() << "\n\n";

    SDL_Quit();

    return 0;
}
