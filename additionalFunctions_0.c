#include "library.h"
/**
* cantCmds - function to count commands typed
* @buff: buffer
* Return: amount of commands
*/
int cantCmds(char *buff)
{
	int cC = 0, i = 0;

	while (buff[i] != '\0')
	{
		if (buff[i] == '\n' || buff[i] == '\t' || buff[i] == ' ')
			cC++, i++;
		else
			i++;
	}
	return (cC);
}
/**
* parse - this parse strings
* @buffer: buffer
* Return: double pointer
*/
char **parse(char *buffer)
{
	char **cmds, *cmd, *delim;
	int i = 0, cC;

	delim = "\n\t \r\a";

	cC = cantCmds(buffer);
	cmds = alloc(sizeof(char *) * (cC + 1));
	cmd = _strtok(buffer, delim);
	while (cmd != NULL)
	{
		cmds[i] = cmd;
		if (cmds[i][0] == '#')
			break;
		cmd = _strtok(NULL, delim);
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}
/**
* constructor - this function calls the execute
* @cmds: double pointer
*/
void constructor(char **cmds)
{
	if (cmds[0][0] == '/')
		execute(cmds);
	else
	{
		cmds = findpath(cmds);
		if (cmds != NULL)
			execute(cmds);
	}
}
/**
* print_number - Entry point
* @n: char variable
*/
void print_number(int n)
{
	unsigned int i = n;
	char loop;

	if (i / 10)
	{
		print_number(i / 10);
	}
	loop = ('0' + (i % 10));
	write(STDERR_FILENO, &loop, 1);
}
/**
* execute - this function proceed to execute
* @cmds: double pointer
*/
void execute(char **cmds)
{
	pid_t child;
	int status = 0;

	child = fork();
	if (child == -1)
	{
		perror("Error");
		_exit(-1);
	}
	if (child == 0)
	{
		execve(cmds[0], cmds, environ);
		_puts("./hsh: ");
		print_number(cantLoops);
		_puts(": ");
		_puts(cmds[0]);
		_puts(": not found\n");
		free(cmds);
		_exit(1);
	}
	else
		wait(&status);
}
