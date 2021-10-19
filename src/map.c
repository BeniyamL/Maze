#include "../headers/header.h"

int map[map_y][map_x] = {
	{1, 1, 1, 1, 1, 3, 1, 1},
	{1, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 4, 0, 2, 0, 1},
	{1, 1, 4, 1, 0, 0, 0, 1},
	{2, 0, 0, 0, 0, 0, 0, 1},
	{2, 0, 0, 0, 0, 1, 0, 1},
	{2, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 3, 1, 3, 1, 3, 1},
	};

int map_floor[map_y][map_x] = {
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 2, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 2, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	};


/**
 * getmap_value - find the value of the map at agiven coordinate
 * @x: x-coordinate
 * @y: y-coordinate
 * @mp: the required map type
 *
 * Return: the value at x,y
 **/
int getmap_value(int x, int y, int mp)
{
	if (mp == 1)
		return (map_floor[y][x]);
	else
		return (map[y][x]);
}

/**
 * setmap_value - set the value of map at a given coordinate
 * @x: x-coordinate
 * @y: y-coordinate
 * @val: the value to set
 *
 * Return: nothing
 **/
void setmap_value(int x, int y, int val)
{
	map[y][x] = val;
}
