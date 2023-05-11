#include "Controller_UI.h"
#include "Constants.h"

Controller_UI* Singleton<Controller_UI>::s_Obj = NULL;

Controller_UI::Controller_UI()
{
	m_Player = NULL;
}

void Controller_UI::handleEvent(SDL_Event event, float deltaTSec)
{
	// Shoot
	if (event.type == SDL_MOUSEBUTTONDOWN && (event.button.button == SDL_BUTTON_LEFT))
	{
		int pixelX = -1;
		int pixelY = -1;
		SDL_GetMouseState(&pixelX, &pixelY);
		Vec2 mousePos = Vec2((float)pixelX / PIXELS_PER_METER, (float)pixelY / PIXELS_PER_METER);
		m_Player->shoot(mousePos);
	}

	// Check for keyboard movement input and weapon change
	if (event.type == SDL_KEYDOWN)
	{
		const Uint8* state = SDL_GetKeyboardState(NULL);

		// Change weapon
		if (state[SDL_SCANCODE_E]) {
			m_Player->updateWeapon();
		}
		
		// Move up
		if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP]) {
			m_Player->updateMoveInput(0, true);
		}
		// Move down
		if (state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN]) {
			m_Player->updateMoveInput(1, true);
		}
		// Move left
		if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT]) {
			m_Player->updateMoveInput(2, true);
		}
		// Move right
		if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT]) {
			m_Player->updateMoveInput(3, true);
		}
	}
	if (event.type == SDL_KEYUP)
	{
		const Uint8* state = SDL_GetKeyboardState(NULL);

		// Move up
		if (!(state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP])) {
			m_Player->updateMoveInput(0, false);
		}
		// Move down
		if (!(state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN])) {
			m_Player->updateMoveInput(1, false);
		}
		// Move left
		if (!(state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT])) {
			m_Player->updateMoveInput(2, false);
		}
		// Move right
		if (!(state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT])) {
			m_Player->updateMoveInput(3, false);
		}
	}

}