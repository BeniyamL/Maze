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

/**
 * display - function to display the game
 * @instance: the given sdl2 instance
 *
 * Return: nothing
 **/
void display(SDL_Instance instance)
{
	ray_cast(instance);
	draw_map(instance);
	display_player(instance);
	add_weapon(instance);
}

/**
 * init_game - function to initialize the game
 *
 * Return: nothing
 **/
void init_game(void)
{
	player.x = 150;
	player.y = 400;
	player.w = 12;
	player.h = 12;
	player.a = PI3;
	player.dx = cos(player.a) * 5;
	player.dy = sin(player.a) * 5;
}

