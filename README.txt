Zachary Jacobs
CS 5150 Final Project
Modular AI

*****Game Summary*****

This game is a project showing off a simple Modular AI decision making system in the context
of a 2D top-down shooter. The enemies use the Modular AI system to pick cover points to move
between, if they should shoot at the player, and which scenarios they should go to a reload
point to reload

The player plays as the blue square and is controlled using WSAD keys or arrow keys. To shoot
the players click on the game screen where they want to aim. The player can use a rifle or 
shotgun when shooting. Press the E key to switch between weapons. Player health, current
weapon and ammo is shown on the bottom UI bar.

The enemies are two colors denoting which weapon they use. Red enemies are riflemen and
orange enemies are shotgunners.

The brown squares are cover points which bullets can not passed through and the 2 green squares
are reload points. Traveling over a reload point fully fills ammo.

The game consists of 4 levels of increasing difficulty. Upon defeating all enemies in a level
the player's position and health are reset and the next wave of enemies are spawned. Upon running
out of health or beating all available levels, the game will briefly pause and then quit showing
the player their score (# enemies killed).
