#include "../headers/header.h"

player_t player;
int map[map_y][map_x] = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	};

/**
 * getmap_value - find the value of the map at agiven coordinate
 * @x: x-coordinate
 * @y: y-coordinate
 *
 * Return: the value at x,y
 **/
int getmap_value(int x, int y)
{
	return (map[y][x]);
}
/**
 * display - function to display the game
 * @instance: the given sdl2 instance
 *
 * Return: nothing
 **/
void display(SDL_Instance instance)
{
	draw_map(instance);
	ray_cast(instance);
	display_player(instance);
}

/**
 * display_player - function to display the player
 * @instance: the given sdl2 instance
 *
 * Return: nothing
 **/
void display_player(SDL_Instance instance)
{
	SDL_Rect rect;
	float x0, y0, x1, y1;

	rect.x = player.x, rect.y = player.y;
	rect.w = player.w, rect.h = player.w;
	SDL_SetRenderDrawColor(instance.ren, 255, 255, 0, 0);
	SDL_RenderFillRect(instance.ren, &rect);

	x0 = player.x;
	y0 = player.y;
	x1 = player.x + player.dx * 20;
	y1 = player.y + player.dy * 20;
	SDL_RenderDrawLine(instance.ren, x0, y0, x1, y1);
}

/**
 * draw_map - function to draw a map
 * @ins: the given SDL instance
 *
 * Return: nothing
 **/
void draw_map(SDL_Instance ins)
{
	int x, y;
	SDL_Rect rect;

	for (x = 0; x < map_x; x++)
	{
		for (y = 0; y < map_y; y++)
		{
			if (map[x][y] == 1)
				SDL_SetRenderDrawColor(ins.ren, 255, 255, 255, 0);
			else
				SDL_SetRenderDrawColor(ins.ren, 0, 0, 0, 0);
			rect.x = (y * map_s) + 1, rect.y = (x * map_s) + 1;
			rect.w = map_s - 1, rect.h = map_s - 1;
			SDL_RenderFillRect(ins.ren, &rect);
		}
	}
}

/**
 * draw_scene - function to draw the scene
 * @ins: the given instance
 * @n: the ray number
 * @h: the height
 * @ray_a: the angle of the ray
 *
 * Return: nothing
 **/
void draw_scene(SDL_Instance ins, int n, float h, float ray_a)
{
	float line, a, of;
	int j;

	a = FixAng(player.a - ray_a);
	h = h * cos(a);
	line = (map_s * 320) / h;
	of = 160 - (line / 2);
	if (line > 320)
		line = 320;
	for (j = n * 8; j < (n * 8) + 8; j++)
		SDL_RenderDrawLine(ins.ren, j + 530, of, j + 530, line + of);
}
