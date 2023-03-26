#include "library.h"
/**
 * _strtok - breaks string buff into a series of tokens
 * using the delimiter delim.
 *
 * @str: string to break
 * @delim: delimiter
 *
 * Return: pointer to the first token
*/
char *_strtok(char *str, const char *delim)
{
	int j, b, cantR = 0;
	char *ret;
	char *res;

	if (str != NULL)
		res = str;
	ret = res;
	while (res[0] != '\0')
	{
		j = 0, b = 0;
		while (delim[j] != '\0')
		{
			if (res[0] == delim[j])
			{
				if (cantR == 0)
					ret++, cantR--;
				else
				{
					res[0] = '\0';
					res++;
					b = 1;
					return (ret);
				}
			}
			j++;
		}
		res++;
		cantR++;
	}
	if (res[0] == '\0' && b == 0)
	{
		b = 2;
		if (cantR == 0)
			return (NULL);
		else
			return (ret);
	}
	if (res[0] == '\0' && b == 2)
		return (NULL);
	return (NULL);
}
/**
* _strcat - function to concatenate
* @dest: pointer where the string is save
* @src: string to concatenate to dest
* Return: the string concatenate
*/
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i])
		i++;

	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	return (dest);
}
/**
* _strncmp - This function compare two strings
* @s1: pointer where the string is save
* @s2: string to concatenate to dest
* @sz: int
* Return: 0 if match
*/
int _strncmp(char *s1, char *s2, int sz)
{
	char cs1, cs2;

	while (sz > 0)
	{
		cs1 = *s1++;
		cs2 = *s2++;
		if (cs1 == '\0' || cs1 != cs2)
			return (cs1 - cs2);
		sz--;
	}
	return (cs1 - cs2);
}
/**
* _strlen - this function counts the letters in a string
* @s: string
* Return: the amount of letters
*/
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/**
* _strdup - function to duplicate a string
* @str: string to duplicate
* Return: the string duplicated
*/
char *_strdup(char *str)
{
	char *a;
	int i, size;


	if (str == NULL)
		return (NULL);
	size = _strlen(str);
	a = alloc(sizeof(char) * (size + 1));
	if (a == NULL)
		return (NULL);

	i = 0;
	while (i < size)
	{
		a[i] = str[i];
		i++;
	}
	a[i] = str[i];
	return (a);
}
