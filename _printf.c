#include "main.h"
/**
 * Function prinf() - prints formatted output to stdout
 * @format: format string containing conversion specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count;
	va_list ap;
	char c;

	va_start(ap, format);

	c = *format;
	while (c != '\0')
	{
		if (c != '%' && c != '\\')
		{
			_putchar(c);
			c = *(format + ++count);
			continue;
		}
		else if (c == '%')
		{
			c = *(format + ++count);
			switch (c)
			{
			case 'c':
				_putchar(va_arg(ap, int));
				c = *(format + ++count);
				continue;
			case 's':
				printstr(va_arg(ap, char *));
				c = *(format + ++count);
				continue;
			default:
				_putchar(c);
				c = *(format + ++count);
				continue;

			}
		}
		else if (c == '\\')
		{
			c = *(format + ++count);
			switch (c)
			{
			default:
				_putchar(c);
				c = *(format + ++count);
				continue;
			}
		}
	}
	va_end(ap);
	_putchar('\n');
	return count;
}
