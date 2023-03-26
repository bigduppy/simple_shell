#include "library.h"
/**
* exitF - Entry point
* @cmds: double pointer
* @buffer: buffer
* Return: Always 1 (Success)
*/
int exitF(char **cmds, char *buffer)
{
	int status;

	if (cmds[1] == NULL)
	{
		free(buffer);
		free(cmds);
		_exit(0);
	}
	else
	{
		status = _atoi(cmds[1]);
		if (status == -1)
		{
			_puts("./hsh: ");
			print_number(cantLoops);
			_puts(": exit: Illegal number: ");
			_puts(cmds[1]);
			_puts("\n");
			return (1);
		}
		free(buffer);
		free(cmds);
		_exit(status);
	}
	return (1);
}
/**
* envF - Entry point
* @cmds: double pointer
* Return: Always 1 (Success)
*/
int envF(char **cmds)
{
	char **envp;
	int i = 0;

	cmds = cmds;
	envp = environ;
	while (envp[i] != NULL)
	{
		_puts(envp[i]);
		_puts("\n");
		i++;
	}
	return (1);
}
/**
* unsetF - Entry point
* @cmds: double pointer
* Return: Always 0 (Success)
*/
int unsetF(char **cmds)
{
	char **envp, *name;
	int len;

	if (cmds[1] == NULL)
		return (-1);
	name = cmds[1];
	if (name[0] == '\0' || name == NULL || _strchr(name, '=') != NULL)
		return (-1);
	len = _strlen(name);
	envp = environ;
	while (*envp != NULL)
	{
		if ((*envp)[len] == '=' && _strncmp(*envp, name, len) == 0)
			while (*envp != NULL)
			{
				*envp = *(envp + 1);
				envp++;
			}
		else
			envp++;
	}
	return (0);
}
/**
* helpF - Entry point
* @cmds: double pointer
* Return: Always 1 (Success)
*/
int helpF(char **cmds)
{
	help_t opts[] = {
		{"exit", exitH},
		{"env", envH},
		{"unsetenv", unsetenvH},
		{"help", helpH},
		{NULL, NULL}
	};
	int i = 1, j, len, b = 0;

	if (cmds[1] == NULL)
	{
		help_me();
		return (0);
	}

	while (cmds[i] != NULL)
	{
		j = 0;
		while (opts[j].name != NULL)
		{
			len = _strlen(cmds[i]);
			if (_strncmp(opts[j].name, cmds[i], len) == 0)
			{
				b = 1;
				opts[j].func();
				break;
			}
			j++;
		}
		i++;
	}
	if (b == 1)
		return (0);
	_puts("Built-in not found can't help\n");
	return (1);
}
