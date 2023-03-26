#include "library.h"
/**
* _atoi - function to convert char to int
* @s: string to make integer
* Return: integer
*/
int _atoi(char *s)
{
	unsigned int x;
	int i, y, sig, j;

	i = 0;
	sig = 1;
	j = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i] < 48 || s[i] > 57)
			return (-1);
		i++;
	}
	i = 0;
	while (s[i] != '\0')
	{
		y = s[i];
		if (y == 45)
			sig = sig * -1;
		if (y >= 48 && y <= 57)
		{
			y = s[i] - 48;
			if (x == 0)
				x = y;
			else
				x = (x * 10) + y;
			j++;
		}
		else if (j > 0)
			break;
		i++;
	}
	x = x * sig;
	return (x);
}
/**
* alloc - function to allocate memory
* @size: size to do malloc
* Return: pointer void
*/
void *alloc(size_t size)
{
	void *pointer;

	pointer = malloc(size);
	if (pointer == NULL)
	{
		_puts("Error al separar memoria\n");
		exit(-1);
	}
	return (pointer);
}
/**
* freeall - function free all
* @av: pointer to be freed
*/
void freeall(char **av)
{
	free(av[0]);
	free(av);
}
