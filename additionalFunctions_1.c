#include "library.h"
/**
* findpath - finds the path
* @cmds: double pointer
* Return: double pointer
*/
char **findpath(char **cmds)
{
	char *pathcito, *delim, *path, *pathP;

	delim = ":";
	path = path_copy("PATH");
	if (path == NULL)
	{
		_puts("PATH not found\n");
		_exit(-1);
	}
	pathP = strtok(path, delim);
	while (pathP != NULL)
	{
		pathcito = path_concat(pathP, cmds[0]);
		if ((access(pathcito, F_OK)) == 0)
		{
			cmds[0] = pathcito;
			free(path);
			return (cmds);
		}
		pathP = strtok(NULL, delim);
		free(pathcito);
	}
	free(path);
	return (cmds);
}
/**
* path_concat - concatenates the path
* @s1: first string
* @s2: second string
* Return: pointer
*/
char *path_concat(char *s1, char *s2)
{
	char *s, *p;
	int s1len, s2len;

	s1len = s2len = 0;
	s1len = _strlen(s1);
	s2len = _strlen(s2);
	s = alloc(sizeof(char) * (s1len + s2len + 2));
	p = s;
	while (*s1 != '\0')
	{
		*s = *s1;
		s++;
		s1++;
	}
	*s = '/';
	s++;
	while (*s2 != '\0')
	{
		*s = *s2;
		s++;
		s2++;
	}
	*s = '\0';
	return (p);
}
/**
* path_copy - copies the path
* @name: path to copy
* Return: pointer
*/
char *path_copy(char *name)
{
	char **envp, *path;
	int len, i;

	i = 0;
	envp = environ;
	len = _strlen(name);
	while (envp[i] != NULL)
	{
		if (_strncmp(envp[i], name, len) == 0)
		{
			path = _strdup(&envp[i][len + 1]);
			return (path);
		}
		i++;
	}
	return (NULL);
}
/**
* help_me - this function prints help
*/
void help_me(void)
{
	_puts("help [exit]\n");
	_puts("help [env]\n");
	_puts("help [unsetenv]\n");
	_puts("help [help]\n");
}
