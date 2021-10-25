#include "../headers/header.h"

enemy_t enemy;
/**
 * add_weapon - function to draw a weapon
 * @ins: the given instance
 *
 * Return: nothing
 **/
void add_weapon(SDL_Instance ins)
{
	SDL_Texture *texture = NULL;
	SDL_Rect gun;
	int w, h;
	SDL_Surface *surf = IMG_Load("images/gn11.png");

	if (surf)
	{
		SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 255, 255, 255));
		texture = SDL_CreateTextureFromSurface(ins.ren, surf);
		SDL_QueryTexture(texture, NULL, NULL, &w, &h);
		gun.w = w * gun_scale, gun.h =  h * gun_scale;
		gun.x = (SCREEN_WIDTH - gun.w) / 2;
		gun.y = (SCREEN_HEIGHT - gun.h) + 20;

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
/**
 * add_enemy - function to draw an enemy
 * @ins: the given instance
 * @j: nth number of enemy
 *
 * Return: nothing
 **/
void add_enemy(SDL_Instance ins, int j)
{
	SDL_Texture *texture = NULL;
	SDL_Rect en;
	int w, h;
	float dx, dy, ds, e_a, e_d, e_swidth, vw_d, x;
	SDL_Surface *surf = IMG_Load("images/enm.png");

	enemy.x = enemy.x * j + map_s;
	enemy.y = enemy.y * j + map_s;

	if (surf)
	{
		SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 255, 255, 255));
		texture = SDL_CreateTextureFromSurface(ins.ren, surf);
		SDL_QueryTexture(texture, NULL, NULL, &w, &h);

		dx = enemy.x - player.x;
		dy = enemy.y - player.y;
		ds = sqrt(dx * dx + dy * dy);
		e_a = atan2(dy, dx) + player.a;
		e_d = cos(e_a) * ds;
		vw_d = find_viewdistance();
		e_swidth = (map_s * vw_d) / e_d;

		x = tan(e_a) * vw_d;
		en.x = (SCREEN_WIDTH / 2) + x - (e_swidth / 2);
		en.y = (SCREEN_HEIGHT - e_swidth) / 2.0;
		en.w = e_swidth;
		en.h = e_swidth;

		if (texture)
			SDL_RenderCopy(ins.ren, texture, NULL, &en);
		else
			printf("unable to create texture\n");

		SDL_FreeSurface(surf);
		SDL_DestroyTexture(texture);
	}
	else
		printf("unable to crate a surface\n");
}
/**
 * find_viewdistance - fucntion to find the view point distance
 *
 * Return: the view point distance
 **/
float find_viewdistance(void)
{
	float swdth = SCREEN_WIDTH / 2, a = FOV / 2;

	return (swdth / tan(a));
}
