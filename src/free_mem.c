#include "../headers/header.h"

/**
 * free_grid - free allocated memory of grid
 * @grid: the given grid
 *
 * Return: nothing
 **/
void free_grid(SDL_Point ***grid)
{
	int i, j;

	for (j = 0; j < map_x; j++)
		free(grid[0][j]);
	free(grid[0]);
	for (i = 0; i < map_y; i++)
		free(grid[1][i]);
	free(grid[1]);
	free(grid);
}

/**
 * free_tokens - free the memory assigned for tokens
 * @tokens: the given tokens
 *
 * Return: Nothing
 **/
void free_tokens(char **tokens)
{
	char **tmp = tokens;

	if (tokens)
	{
		while (*tokens)
			free(*tokens++);
		free(tmp);
	}
}
/**
 * free_cols - free allocated memory of columns
 * @cols: the given columns
 *
 * Return: nothing
 **/
void free_cols(char ***cols)
{
	int i, j;

	for (i = 0; i < map_x; i++)
	{
		for (j = 0; j < map_y; j++)
			free(cols[i][j]);
		free(cols[i]);
	}
	free(cols);
}

/**
 * free_numbers - free the memory assigned for numbers
 * @numbers: the given numbers
 *
 * Return: Nothing
 **/
void free_numbers(int **numbers)
{
	int i;

	for (i = 0; i < map_x; i++)
		free(numbers[i]);
	free(numbers);
}

