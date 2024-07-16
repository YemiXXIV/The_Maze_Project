#include "../headers/header.h"

/**
 * SDL_KEYDOWN_FUNC - To process input when a key is pressed or clicked down
 * @event: The structures for the different event types
*/

void SDL_KEYDOWN_FUNC(SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_ESCAPE)
		GameRunning = false;
	if (event.key.keysym.sym == SDLK_UP)
		player.walkDirection = +1;
	if (event.key.keysym.sym == SDLK_DOWN)
		player.walkDirection = -1;
	if (event.key.keysym.sym == SDLK_RIGHT)
		player.turnDirection = +1;
	if (event.key.keysym.sym == SDLK_LEFT)
		player.turnDirection = -1;
	if (event.key.keysym.sym == SDLK_w)
		player.walkDirection = +1;
	if (event.key.keysym.sym == SDLK_s)
		player.walkDirection = -1;
	if (event.key.keysym.sym == SDLK_a)
		player.turnDirection = -1;
	if (event.key.keysym.sym == SDLK_d)
		player.turnDirection = +1;
}

/**
 * SDL_KEYUP_FUNC - To process input when a key is not pressed or clicked
 * @event: The structures for the different event types
*/

void SDL_KEYUP_FUNC(SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
		player.walkDirection = 0;
	if (event.key.keysym.sym == SDLK_DOWN)
		player.walkDirection = 0;
	if (event.key.keysym.sym == SDLK_RIGHT)
		player.turnDirection = 0;
	if (event.key.keysym.sym == SDLK_LEFT)
		player.turnDirection = 0;
	if (event.key.keysym.sym == SDLK_w)
		player.walkDirection = 0;
	if (event.key.keysym.sym == SDLK_s)
		player.walkDirection = 0;
	if (event.key.keysym.sym == SDLK_a)
		player.turnDirection = 0;
	if (event.key.keysym.sym == SDLK_d)
		player.turnDirection = 0;
}

/**
 * handleInput - To process input from your keyboard
 *
*/
void handleInput(void)
{
	SDL_Event event;

	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT)
		GameRunning = false;
	else if (event.type == SDL_KEYDOWN)
		SDL_KEYDOWN_FUNC(event);
	else if (event.type == SDL_KEYUP)
		SDL_KEYUP_FUNC(event);
}
