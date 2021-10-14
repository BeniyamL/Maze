#include "../headers/header.h"

player_t player;
static int key_pressed = 0;
static int start = 1;
/**
 * init_instance - intialize all instance
 * @in: the given instance
 *
 * Return: 0 on success 1 otherwise
 **/

int init_instance(SDL_Instance *in)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
	}

	in->win = SDL_CreateWindow("The Maze project", 0, 0, SCREEN_WIDTH,
	SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
	if (in->win == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	in->ren = SDL_CreateRenderer(in->win, -1, SDL_RENDERER_ACCELERATED
	| SDL_RENDERER_PRESENTVSYNC);
	if (in->ren == NULL)
	{
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	return (0);
}

/**
 * poll_events - function to handle events
 * @ins: the istance of SDL
 *
 * Return: 0 on suceesss 1 otherwise
 **/
int poll_events(SDL_Instance ins)
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev))
	{
		if (ev.type == SDL_QUIT)
			return (1);
		else if (ev.type == SDL_KEYDOWN)
		{
			if (ev.key.keysym.sym == SDLK_ESCAPE)
				return (1);
			else if (ev.key.keysym.sym == SDLK_RIGHT ||
			ev.key.keysym.sym == SDLK_d ||
			ev.key.keysym.sym == SDLK_LEFT ||
			ev.key.keysym.sym == SDLK_a ||
			ev.key.keysym.sym == SDLK_UP ||
			ev.key.keysym.sym == SDLK_w ||
			ev.key.keysym.sym == SDLK_DOWN ||
			ev.key.keysym.sym == SDLK_s)
				handle_key_down(ev, ins);
		}
	}
	return (0);
}

/**
 * handle_key_down - handle when the key pressed down
 * @ev: the given event
 * @ins: the given instance
 *
 * Return: nothing
 **/
void handle_key_down(SDL_Event ev, SDL_Instance ins)
{
	if (ev.key.keysym.sym == SDLK_LEFT ||
                ev.key.keysym.sym == SDLK_a)
	{
		/**
		player.a -= 5;
		player.a = FixAng(player.a);
		player.dx = cos(degToRad(player.a));
		player.dy = -sin(degToRad(player.a));
		**/
		player.a -= 0.1;
                player.a = FixAng(player.a);
                player.dx = cos(player.a) * 5;
                player.dy = sin(player.a) * 5;

		printf("a=%f dx=%f dy=%f\n", player.a, player.dx, player.dy);
		key_pressed = 1;
	}
	else if (ev.key.keysym.sym == SDLK_RIGHT ||
		ev.key.keysym.sym == SDLK_d)
	{
		/**
		player.a += 5;
		player.a = FixAng(player.a);
		player.dx = cos(degToRad(player.a));
		player.dy = -sin(degToRad(player.a));
		**/
		player.a += 0.1;
                player.a = FixAng(player.a);
                player.dx = cos(player.a) * 5;
                player.dy = sin(player.a) *5 ;

		printf("a=%f dx=%f dy=%f\n", player.a, player.dx, player.dy);
		key_pressed = 1;
	}
	else if (ev.key.keysym.sym == SDLK_UP ||
		ev.key.keysym.sym == SDLK_w)
	{
		player.x += player.dx * 5;
		player.y += player.dy * 5;
		printf("a=%f x=%f y=%f\n", player.a, player.x, player.y);
		key_pressed = 1;
	}
	else if (ev.key.keysym.sym == SDLK_DOWN ||
		ev.key.keysym.sym == SDLK_s)
	{
		player.x -= player.dx * 5;
		player.y -= player.dy * 5;
		printf("a=%f x=%f y=%f\n", player.a, player.x, player.y);
		key_pressed = 1;
	}
	SDL_SetRenderDrawColor(ins.ren, 76, 76, 76, 0);
	SDL_RenderClear(ins.ren);
	display(ins);
	SDL_RenderPresent(ins.ren);
}
/**
 * init_game - function to initialize the game
 *
 * Return: nothing
 **/
void init_game(void)
{
	/**
	player.x = 150;
	player.y = 400;
	player.w = 12;
	player.h = 12;
	player.a = 90;
	player.dx = cos(degToRad(player.a));
	player.dy = -sin(degToRad(player.a));
	**/
	player.x = 300;
        player.y = 300;
        player.w = 12;
        player.h = 12;
        player.a = 0;
        player.dx = cos(player.a) * 5;
        player.dy = sin(player.a) * 5;

}
float degToRad(int a)
{
	return (a * PI) / 180.0;
}
//int FixAng(int a)
float FixAng(float a)
{
	/**
	if(a > 359)
		a -=360;
	if (a < 0)
		a += 360;
	return a;
	**/
	if(a > 2 * PI)
                a -= 2 * PI;
        if (a < 0)
                a += 2 * PI;
        return a;
}
int hit_wall(float rx, float ry)
{
        int mx, my, mp;
        if (rx < 0 || rx >= map_x * map_s || ry < 0 || ry >= map_y * map_s)
        {
		start = 0;
		key_pressed = 0;
	        return(1);
	}
        mx = (int)(player.x)>>6;
        my = (int)(player.y)>>6;
        mp = my * map_x + mx;
        if (key_pressed == 1 || start == 1)
        {
                printf("a=%f rx=%f mx=%d, ry=%f my=%d\n", player.a, rx, mx, ry, my);
        }
        if (mp > 0 && mp < map_x * map_y && getmap_value(mx, my) != 0)
        {
		start = 0;
		key_pressed = 0;
		return(1);
	}
        else
                return(0);
}

