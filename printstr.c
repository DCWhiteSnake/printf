#include "main.h"

/**
printstr - prints string to the console
@c - a pointer to the first char
Return - nothing.
*/
void printstr (char *c)
{
	if (*c != '\0')
	{
		while (*c != '\0')
			_putchar(*(c++));
	}
}
