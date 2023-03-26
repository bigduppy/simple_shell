#include "library.h"
/**
* _puts - function to print strings
* @str: string
*/
void _puts(char *str)
{
	int i = 0;

	while (*(str + i) != '\0')
	{
		_putchar(*(str + i));
		i++;
	}
}
/**
* _putchar - function to print char by char
* @c: char to print
* Return: the amount of characters printed
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
