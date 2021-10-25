#include "../headers/header.h"


enemy_t enemy;
/**
 * main - Entry point for execution
 * @argc: the number of argument
 * @argv: vector for the given argument
 *
 * Return: always success
 **/
int main(int argc, char **argv)
{
	SDL_Instance instance;

	if (init_instance(&instance) != 0)
		return (1);
	init_game();
	if (argc > 1)
		make_map(argv);
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
	int j;

	ray_cast(instance);
	draw_map(instance);
	display_player(instance);
	add_weapon(instance);

	for (j = 1; j <= 1; j++)
		add_enemy(instance, j);
}

/**
 * init_game - function to initialize the game
 *
 * Return: nothing
 **/
void init_game(void)
{
	/**
	*float rx, ry;
	*int ex, ey;
	**/

	player.x = 150;
	player.y = 400;
	player.w = 12;
	player.h = 12;
	player.a = PI3;
	player.dx = cos(player.a) * 5;
	player.dy = sin(player.a) * 5;

	enemy.x = 500;
	enemy.y = 500;
	/**
	*srand(time(NULL));
	*rx = ((SCREEN_WIDTH - 0) * ((float)rand() / RAND_MAX)) + 0;
	*ex = floor(rx / map_s);
	*ry = ((SCREEN_HEIGHT - 0) * ((float)rand() / RAND_MAX)) + 0;
	*ey = floor(ry / map_s);
	*if (getmap_value(ex, ey, 0) == 0)
	*	enemy.x = rx, enemy.y = ry;
	*else
	*	enemy.x = 200, enemy.y = 200;
	**/
}
