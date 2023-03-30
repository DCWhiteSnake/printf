#include "main.h"

int handle_backslash(const char *format, unsigned int start, char c);
int handle_percent(va_list ap, char c);

/**
 * _printf - prints formatted output to stdout
 * @format: format string containing conversion specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int count, a_count, count_2, t_count;
	va_list ap;
	char c;

	va_start(ap, format);
	c = *format;
	a_count = 0;
	count = 0;
	count_2 = 0;
	t_count = 0;

	if (!format[0])
	{
		return (0);
	}
	while (c)
	{
		if (c != '%' && c != '\\')
		{
			_putchar(c);
			c = *(format + ++count + a_count);
		}
		else if (c == '%')
		{
			count_2 = handle_percent(ap, *(format + count + a_count + 1));
			count_2 = (count_2 == 0)? (unsigned int)printstr("(null)") : count_2; 
			t_count += count_2;
			c = *(format + ++count + ++a_count);
		}
		else if (c == '\\')
		{
			count += handle_backslash(format, count, c);
		}
	}
	va_end(ap);
	return (count + t_count - a_count);
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
 * @start: where to start working from
 * @ap: a refence to the va_list instance.
 * @c: the reference to the '%' char.
 * Return: 1 always.
 */
int handle_percent(va_list ap, char c)
{
	unsigned int count;
	int number;

	count = 1;
	number = 0;
	

	switch (c)
	{
	case 'c':
		_putchar(va_arg(ap, int));
		break;
	case 's':
		count = printstr(va_arg(ap, char *));
		break;
	case 'i':
	case 'd':
		number = va_arg(ap, int);
		if (number < 0)
		{
			count += _putchar('-');
			number *= -1;
		}
		count = writenum(number, 1) + 1;
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
		++count;
		break;
	}
	return (count);
}
