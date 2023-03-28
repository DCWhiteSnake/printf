#include "main.h"

/**
 * writenum - write a number to the console recursively
 * @n: the number
 * Return: nothing;
*/
void writenum(int n)
{
	if (n > 9)
	{
		writenum(n / 10);
	}
	_putchar('0' + n % 10);
}
