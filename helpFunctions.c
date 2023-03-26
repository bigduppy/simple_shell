#include "library.h"
/**
* exitH - function to print message of help to exit
*
*/
void exitH(void)
{
	_puts("exit is used to quit the hsh you can also exit ");
	_puts("exit with a status number -- usage: exit 98\n");
}
/**
* envH - function to print message of help to env
*
*/
void envH(void)
{
	_puts("env is used to print the environment list -- usage: env\n");
}
/**
* unsetenvH - function to print message of help to unsetenv
*
*/
void unsetenvH(void)
{
	_puts("unsetenv is used to remove variables form the environment list ");
	_puts("-- usage: unsetenv 'variable'\n");
}
/**
* helpH - function to print message of help to help
*
*/
void helpH(void)
{
	_puts("help is used to let you know what is the bult-in for and the usage ");
	_puts("of it -- usage: help 'builtin name'\n");
}
