#include "../headers/header.h"

player_t player;
/**
 * ray_cast - function to cast array to the wall
 * @ins: the given sdl2 instance
 *
 * Return: nothing
 **/
void ray_cast(SDL_Instance ins)
{
	float ray_a, hx, hy, hd = 1000000; 
	//vx, vy, hd = 1000000, vd = 1000000, disT;
	float ray_x, ray_y;
	int i;

	//ray_a = FixAng(player.a + 30);
	ray_a = player.a;
	for (i = 0; i < 1; i++)
	{
		horizontal_collision(ray_a, &hd, &hx, &hy);
		/**
		vertical_collision(ray_a, &vd, &vx, &vy);
		if (hd < vd)
		{
			ray_x = hx;
			ray_y = hy, disT = hd;
			SDL_SetRenderDrawColor(ins.ren, 229.5, 0, 0, 0);
		}
		else  if (vd < hd)
		{
			ray_x = vx;
			ray_y = vy, disT = vd;
			SDL_SetRenderDrawColor(ins.ren, 178.5, 0, 0, 0);
		}
		**/
		ray_x = hx, ray_y = hy;
		SDL_SetRenderDrawColor(ins.ren, 0, 255, 0, 0);

		SDL_RenderDrawLine(ins.ren, player.x, player.y, ray_x, ray_y);
		//draw_scene(ins, i, disT, ray_a);
		//ray_a = FixAng(ray_a - 1);
	}
}
/**
 * horizontal_collision - function to check the horizontal collision
 * @ray_a: the ray angle
 * @hd: reference to the horizontal distance
 * @hx: reference to the horizonatal x-coordinate
 * @hy: reference to the horizontal y-coordinate
 *
 * Return: nothing
 **/
void horizontal_collision(float ray_a, float *hd, float *hx, float *hy)
{
	float ray_x, ray_y, xo, yo, a_tan, mx, my, mp;
	int diff;

	//a_tan = 1 / tan(degToRad(ray_a));
	a_tan = -1 / tan(ray_a);
	diff = 0;
	//if (sin(degToRad(ray_a)) > 0.001)
	if (ray_a < PI && ray_a > 0)
	{
		ray_y = (((int)player.y>>6)<<6) - 0.0001;
		ray_x = ((player.y - ray_y) * a_tan) + player.x;
		yo = -64, xo = -yo * a_tan;
	}
	//else if (sin(degToRad(ray_a)) < -0.001)
	else if (ray_a > PI)
	{
		ray_y = (((int)player.y>>6)<<6) + 64;
		ray_x = ((player.y - ray_y) * a_tan) + player.x;
		yo = 64, xo = -yo * a_tan;
	}
	else if (ray_a == 0 || ray_a == PI)
		ray_x = player.x, ray_y = player.y, diff = 8;

	while (diff < 8)
	{
		if (hit_wall(ray_x, ray_y) == 1)
		{
			diff = 8;
			*hd = cos(degToRad(ray_a)) * (ray_x - player.x) - sin(degToRad(ray_a)) * (ray_y - player.x);
		}
		else
			ray_x += xo, ray_y += yo, diff += 1;
	}
	*hx = ray_x, *hy = ray_y;
	*hd = find_distance(player.x, player.y, ray_x, ray_y);
}
/**
 * vertical_collision - function to check vertical collission
 * @ray_a: the angle of the ray
 * @vd: reference to the vertical distance
 * @vx: reference to the vertical x-coordinate
 * @vy: reference to the vertical y-coordinate
 *
 * Return: nothing
 **/
void vertical_collision(float ray_a, float *vd, float *vx, float *vy)
{
	float ray_x, ray_y, xo, yo, a_tan;
	int diff;

	//a_tan = tan(degToRad(ray_a));
	a_tan = -tan(ray_a);
	diff = 0;
	//if (cos(degToRad(ray_a)) > 0.001)
	if (ray_a > PI2 && ray_a < PI3)
	{
		//ray_x = (((int)player.x >> 6) << 6) + 64;
		ray_x = (((int)player.x >> 6) << 6) -0.0001;
		ray_y = ((player.x - ray_x) * a_tan) + player.y;
		//xo = 64, yo = -xo * a_tan;
		xo = -64, yo = -xo * a_tan;
	}
	//else if (cos(degToRad(ray_a)) < - 0.001)
	if (ray_a < PI2 || ray_a > PI3)
	{
		//ray_x = (((int)player.x >> 6) << 6) - 0.0001;
		ray_x = (((int)player.x >> 6) << 6) + 64;
		ray_y = ((player.x - ray_x) * a_tan) + player.y;
		//xo = -64, yo = -xo * a_tan;
		xo = 64, yo = -xo * a_tan;
	}
	if (ray_a == 0 || ray_a == PI)
		ray_x = player.x, ray_y = player.y, diff = 8;

	while (diff < 8)
	{
		if (hit_wall(ray_x, ray_y) == 1)
		{
			*vx = ray_x, *vy = ray_y, diff = 8;
			*vd = find_distance(player.x, player.y, ray_x, ray_y);
			//*vd = cos(degToRad(ray_a)) * (ray_x - player.x) - sin(degToRad(ray_a)) * (ray_y -player.y);
		}
		else
			ray_x += xo, ray_y += yo, diff += 1;
	}
}
/**
 * hit_wall - function to check whether the ray hits the wall
 * @rx: the x positon of the ray
 * @ry: the y position of the ray
 * Return: 1 if the ray hists the wall 0 otherwise

int hit_wall(float rx, float ry)
{
	int mx, my, mp;

	if (rx < 0 || rx >= map_x * map_s || ry < 0 || ry >= map_y * map_s)
		return(1);
	mx = floor(rx / map_s);
	my = floor(ry / map_s);
	mp = my * map_x + mx;
	if (key_pressed == 1 || start == 1)
	{
		printf("rx=%f mx=%d, ry=%f my=%d\n", rx, mx, ry, my);
		key_pressed = 0; start = 0;
	}
	if (mp > 0 && mp < map_x * map_y && getmap_value(mx, my) != 0)
		return(1);
	else
		return(0);
}
**/
/**
 * find_distance - function to find the distance b/n two points
 * @ax: the x-coordinate of the first point
 * @ay: the y-coordinate of the first point
 * @bx: the x-coordinate of the second point
 * @by: the y-coordinate of the second point
 *
 * Return: the distance
 
float find_distance(float ax, float ay, float bx, float by, float a)
{
	return (cos(degToRad(a)) * (bx -ax) - sin(degToRad(a)) * (by - ay));
}
**/
float find_distance(float ax, float ay, float bx, float by)
{
        return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

