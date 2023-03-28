#include "main.h"

/**
 * printstr - prints string to the console
 * @c: a pointer to the first char
 * Return: the number of characters that were printed.
*/
int printstr(char *c)
{
	int count = 0;

	while (*c != '\0')
	{
		_putchar(*(c++));
		count++;
	}
	return (count);
}
