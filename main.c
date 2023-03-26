#include "library.h"
/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
	launch();
	return (0);
}
/**
* launch - this function starts all the procedure
*
* Return: Always 0 (Success)
*/
void launch(void)
{
	char *buffer, **cmds, *cmd0;
	size_t buffsize = 0;

	cantLoops = 1;
	signal(SIGINT, signals);
	signal(SIGQUIT, SIG_IGN);
	buffer = NULL;
	while (1)
	{
		flag = 0;
		if (isatty(STDIN_FILENO))
			_puts("> ");
		if (getline(&buffer, &buffsize, stdin) != -1)
		{
			if (buffer[0] != '\n' && buffer[0] != '#')
			{
				cmds = parse(buffer);
				if (cmds[0] == NULL)
					freeall(cmds);
				else
				{
					cmd0 = cmds[0];
					if (isbuiltin(cmds, buffer) == -1)
						flag = 1, constructor(cmds);
					if (issame(cmd0, cmds[0]) == 0)
						free(cmds);
					else
						freeall(cmds);
				}
				cantLoops++;
			}
		}
		else
		{
			free(buffer);
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			_exit(0);
		}
	}
}
/**
* isbuiltin - This function has the built-in commands
* @cmds: double pointer
* @buffer: buffer
* Return: Always 0 (Success)
*/
int isbuiltin(char **cmds, char *buffer)
{
	builtins_t builtins[] = {
		{"exit", exitF},
		{"env", envF},
		{"unsetenv", unsetF},
		{"help", helpF},
		{NULL, NULL}
	};
	int i = 0, len;

	while (builtins[i].name != NULL)
	{
		len = _strlen(cmds[0]);
		if (_strncmp(cmds[0], "exit", 4) == 0)
		{
			if (cmds[0][4] == 0)
			{
				return (builtins[0].func(cmds, buffer));
			}
		}
		if (_strncmp(cmds[0], builtins[i].name, len) == 0)
			return (builtins[i].func(cmds));

		i++;
	}
	return (-1);
}
/**
* issame - This function compares two strings
* @cmd0: first string
* @cmds0: second string
*
* Return: Always 0 (Success)
*/
int issame(char *cmd0, char *cmds0)
{
	int len;

	len = 0;
	while (cmd0[len] != '\0')
		len++;
	if (_strncmp(cmd0, cmds0, len) == 0)
		return (0);
	return (1);
}
/**
* signals - this function is to catch some keys
* @thing: integer
*/
void signals(int thing)
{
	thing = thing;
	if (flag == 0)
		_puts("\n> ");
	signal(SIGINT, signals);
}
