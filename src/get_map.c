#include "../headers/header.h"

/**
 * _atoi - convert string to integer
 * @s: the string to be converted
 *
 * Return: the equivalent integer value
 */
int _atoi(char *s)
{
	int j, sign;
	unsigned int n;

	j = 0;
	sign = 1;
	n = 0;
	while (s[j] != '\0')
	{
		if (s[j] >= '0' && s[j] <= '9')
		{
			n = (n * 10) + (s[j] - '0');
		}
		if (n != 0 && !(s[j] >= '0' && s[j] <= '9'))
		{
			break;
		}
		if (s[j] == '-')
		{
			sign = sign * -1;
		}
		j++;
	}
	return (sign * n);
}

/**
 * _strdup - function to duplicate a string
 * @str: the given string
 *
 * Return: the duplicated string
 **/
char *_strdup(char *str)
{
	char *dup;
	int i = 0;
	int strlength = 0;

	if (str == NULL)
		return (NULL);
	strlength = _length(str);
	dup = malloc(sizeof(char) * (strlength + 1));
	if (dup == NULL)
	{
		free(dup);
		return (NULL);
	}
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/**
 * _length - function that finds the length of a string
 * @str: the given string
 *
 * Return: the length of a string
 **/
int _length(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
/**
 * get_altitude - read altitude from the text file
 * @argv: argument of commands
 *
 * Return: the altitue
 **/
int **get_altitude(char **argv)
{
	int **altitude;
	int fd, i, j;
	char buf[1024];
	char **rows, ***cols;

	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		fprintf(stderr, "Error in opening a file");
		return (NULL);
	}
	read(fd, buf, 1023);
	close(fd);
	altitude = malloc(sizeof(int *) * map_x);
	if (altitude == NULL)
		return (NULL);
	for (i = 0; i < map_x; i++)
		altitude[i] = malloc(sizeof(int) * map_y);
	rows = str_split(buf, "\n");
	cols = malloc(sizeof(char **) * map_x);
	for (i = 0; rows[i]; i++)
		cols[i] = str_split(rows[i], " ");
	for (i = 0; i < map_x; i++)
	{
		for (j = 0; j < map_y; j++)
			altitude[i][j] = _atoi(cols[i][j]);
	}
	free_tokens(rows);
	free_cols(cols);
	return (altitude);
}
/**
 * str_split - split a string
 * @str: the given string
 * @del: the delimeter
 *
 * Return: array of a string
 **/
char **str_split(char *str, char *del)
{
	char **tokens;
	char *token, *str2;
	int i = 0;
	int tokens_size = 2;

	tokens = malloc(sizeof(char *) * (tokens_size + 1));
	if (tokens == NULL)
		return (NULL);
	str2 = _strdup(str);
	token = strtok(str2, del);
	tokens_size++;
	while (token)
	{
		tokens[i] = _strdup(token);
		tokens = realloc(tokens, sizeof(char *) * tokens_size);
		token = strtok(NULL, del);
		i++;
		tokens_size++;
	}
	tokens[i] = '\0';
	if (token)
		free(token);
	if (str2)
		free(str2);
	return (tokens);
}
