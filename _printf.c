#include "main.h"

int handle_backslash(const char *format, int start, char c);
int handle_percent(const char *format, va_list ap, int start, char c);
/**
 * _prinf() - prints formatted output to stdout
 * @format: format string containing conversion specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count, a_count;
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

int handle_backslash(const char *format, int start, char c)
{	
	int start_c;

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

int handle_percent(const char *format, va_list ap, int start, char c)
{
	int count;
	int number;

	count = start;
	c = *(format + ++count);
	if (c == 'c')
	{
		_putchar(va_arg(ap, int));
		c = *(format + ++count);
	}
	else if (c == 's')
	{
		printstr(va_arg(ap, char *));
		c = *(format + ++count);
	}
	else if (c == 'i' || c == 'd')
	{
		number = va_arg(ap, int);
		if (number < 0)
		{
			_putchar('-');
			number *= -1;
		}
		writenum(number);
		c = *(format + ++count);
	}
	else if (c == '%')
	{
		_putchar(c);
		c = *(format + ++count);
	}
	else
	{
		_putchar('%');
		_putchar(c);
		c = *(format + ++count);
	}
	return(1);
}