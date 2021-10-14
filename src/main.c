#include "../headers/header.h"


/**
 * main - Entry point for execution
 *
 * Return: always success
 **/
int main(void)
{
	SDL_Instance instance;

	if (init_instance(&instance) != 0)
		return (1);
	init_game();
	while ("C is awesome")
	{
		SDL_SetRenderDrawColor(instance.ren, 76, 76, 76, 0);
		SDL_RenderClear(instance.ren);

		if (poll_events(instance) == 1)
			break;

		display(instance);
		SDL_RenderPresent(instance.ren);
	}
	SDL_DestroyRenderer(instance.ren);
	SDL_DestroyWindow(instance.win);
	SDL_Quit();
	return (0);
}

