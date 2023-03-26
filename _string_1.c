#include "library.h"
/**
* _strchr - function to search for match in a word
* @str: string
* @c: character to find in the string
* Return: pointer after the match
*/
char *_strchr(char *str, char c)
{
	int i = 0;

	while (str[i] != 0)
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (str[i] == c)
		return (str + i);
	return (NULL);
}
