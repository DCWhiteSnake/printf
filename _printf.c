#include "main.h"
/**
 * _prinf() - prints formatted output to stdout
 * @format: format string containing conversion specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count, a_count, number;
	va_list ap;
	char c;

	va_start(ap, format);
	c = *format;
	a_count = 0;
	count = 0;
	_putchar('\n');
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
			a_count++;
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
			case 'i':
			case 'd':
				number = va_arg(ap, int);
				if (number < 0)
				{
					_putchar('-');
					number *= -1;
				}
				writenum(number);
				c = *(format + ++count);
				continue;
			case '%':
				_putchar(c);
				c = *(format + ++count);
				continue;
			default:
				_putchar('%');
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
	return (count - a_count);
}
