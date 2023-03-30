#include "main.h"

/**
 * writenum - write a number to the console recursively
 * @n: the number
 * Return: nothing;
*/
int writenum(int n, int start)
{
	int x  = start+1;

	if (n > 9)
	{
		writenum(n / 10, ++x);
	}
	_putchar('0' + n % 10);
	start += 1;
	return start+1;
}
