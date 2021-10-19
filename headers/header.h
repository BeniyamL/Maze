#ifndef Demo_h
#define Demo_h

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 512
#define map_x 8
#define map_y 8
#define map_s 64
#define PI 3.14159265
#define PI2 (0.5 * PI)
#define PI3 (1.5 * PI)
#define DR 0.0174533

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

/**
 * struct SDL_Instance - structure for sdl instance
 * @win: window of sdl
 * @ren: surface to draw
 *
 * Decscription: structure to create window and surface of SDL
**/
typedef struct SDL_Instance
{
	SDL_Window *win;
	SDL_Renderer *ren;
} SDL_Instance;

/**
 * struct player_s - struburte for the player
 * @x: the x coordinate postion
 * @y: the y coordinate position
 * @w: the width of the player
 * @h: the height of the player
 * @a: angle of the player
 * @dx: delta x of the player
 * @dy: delta y of the player
 **/
typedef struct player_s
{
	float x, y, w, h, a, dx, dy;
} player_t;

extern player_t player;

/** main.c **/
void init_game(void);
void display(SDL_Instance instance);

/** window **/
int poll_events(SDL_Instance instance);
void handle_key_down(SDL_Event event, SDL_Instance instance);
int init_instance(SDL_Instance *in);
void handle_door(void);
float FixAng(float a);

/** draw **/
void display_player(SDL_Instance instance);
void draw_map(SDL_Instance ins);
void draw_scene(SDL_Instance ins, int n, float h, float ray_a, float shade,
		float rx, float ry, int m_txr);
void draw_floor(SDL_Instance ins, float ln_off, int n, float line, float ra);
void draw_roof(SDL_Instance ins, float ln_off, int n, float line, float ra);

/** cast **/
void ray_cast(SDL_Instance ins);
int hit_wall(float rx, float ry);
void horizontal_collision(float ray_a, float *d, float *hx, float *hy, int *h);
void vertical_collision(float ray_a, float *vd, float *vx, float *vy, int *v);
float find_distance(float ax, float ay, float bx, float by);

/** texture **/
float get_texture(int idx);

/** map **/
void setmap_value(int mx, int my, int val);
int getmap_value(int x, int y, int mp);

/** get_altitude **/
int _atoi(char *s);
char *_strdup(char *str);
int _length(char *str);
int **get_altitude(char **argv);
char **str_split(char *str, char *del);

/** free_mem **/
void free_grid(SDL_Point ***grid);
void free_tokens(char **tokens);
void free_cols(char ***cols);
void free_numbers(int **numbers);
#endif
