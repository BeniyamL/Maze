#include "../headers/header.h"

static SDL_Texture *texture;
/**
 * add_weapon - function to draw a weapon
 * @ins: the given instance
 *
 * Return: nothing
 **/
void add_weapon(SDL_Instance ins)
{
	texture = NULL;
	SDL_Rect gun;

	gun.x = player.x * (1 / MAP_SCALE);
	gun.y = player.y * (1 / MAP_SCALE);
	gun.w = 200;
	gun.h =  200;

	SDL_Surface *surf = IMG_Load("images/gun1.jpg");
	if (surf)
	{
		texture = SDL_CreateTextureFromSurface(ins.ren, surf);
		if (texture)
			SDL_RenderCopy(ins.ren, texture, NULL, &gun);
		else
			printf("unable to create texture\n");
		
		SDL_FreeSurface(surf);
		SDL_DestroyTexture(texture);
	}
	else
		printf("unable to crate a surface\n");
}
