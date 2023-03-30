#include "main.h"

int handle_backslash(const char *format, unsigned int start, char c);
int handle_percent(const char *format, va_list ap, unsigned int start, char c);

/**
 * _printf - prints formatted output to stdout
 * @format: format string containing conversion specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int count, a_count;
	va_list ap;
	char c;

	va_start(ap, format);
	c = *format;
	a_count = 0;
	count = 0;

	if (!format)
	{
		return (-1);
	}
	if (!format[0])
	{
		return (0);
	}
	while (c != '\0')
	{
		if (c != '%' && c != '\\')
		{
			_putchar(c);
			c = *(format + ++count);
		}
		else if (c == '%')
		{
			a_count++;
			count += handle_percent(format, ap, count, c);
			c = *(format + ++count);
		}
		else if (c == '\\')
		{
			count += handle_backslash(format, count, c);
		}
	}
	va_end(ap);
	return (count - a_count);
}

/**
 * handle_backslash - self descriptive
 * @format: the string
 * @start: where to start working from
 * @c: the reference to the \ char.
 * Return: 1 always.
 */
int handle_backslash(const char *format, unsigned int start, char c)
{
	unsigned int start_c;

	start_c = start;
	c = *(format + ++start_c);
	switch (c)
	{
	default:
		_putchar(c);
		c = *(format + ++start_c);
	}
	return (1);
}

/**
 * handle_percent - self descriptive
 * @format: the string
 * @start: where to start working from
 * @ap: a refence to the va_list instance.
 * @c: the reference to the '%' char.
 * Return: 1 always.
 */
int handle_percent(const char *format, va_list ap, unsigned int start, char c)
{
	unsigned int count;
	int number;

	count = start;
	c = *(format + ++count);
	

	switch (c)
	{
	case 'c':
		_putchar(va_arg(ap, int));
		break;
	case 's':
		printstr(va_arg(ap, char *));
		break;
	case 'i':
	case 'd':
		number = va_arg(ap, int);
		if (number < 0)
		{
			_putchar('-');
			number *= -1;
		}
		writenum(number);
		break;
	case 'x':
		print_x(ap);
		break;
	case 'X':
		print_X(ap);
		break;
	case '%':
		_putchar(c);
		break;
	case 'o':
		print_o(ap);
		break;
	case 'u':
		print_u(ap);
		break;
	default:
		_putchar('%');
		_putchar(c);
		break;
	}
	c = *(format + ++count);
	return (1);
}
