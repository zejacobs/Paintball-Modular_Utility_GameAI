#pragma once

#include "Singleton.h"
#include "Entity.h"
#include "Player.h"

#include <SDL.h>

class Controller_UI : public Singleton<Controller_UI>
{
public:
    Controller_UI();
    virtual ~Controller_UI() {};

    void setPlayer(Player* player) { m_Player = player; };
    void handleEvent(SDL_Event event, float deltaTSec);

private:
    Player* m_Player;

};