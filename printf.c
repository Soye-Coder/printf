#include "main.h"
#include <stdarg.h> /* va_list, va_start, va_arg, va_end */
#include <unistd.h> /* write */

/**
 * _printf - prints output according to a format.
 * @format: character string containing zero or more directives.
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, len = 0;
	char *str;

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
		{
			len += write(1, &format[i], 1);
			continue;
		}
		i++;
		switch (format[i])
		{
			case 'c':
				len += write(1, (char) va_arg(args, int), 1);
				break;
			case 's':
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				while (*str)
					len += write(1, str++, 1);
				break;
			case '%':
				len += write(1, "%", 1);
				break;
			case 'd':
			case 'i':
				len += print_number(va_arg(args, int));
				break;
			default:
				len += write(1, &format[i - 1], 2);
				break;
		}
	}

	va_end(args);

	return (len);
}

/**
 * print_number - prints an integer.
 * @n: integer to print.
 *
 * Return: the number of characters printed.
 */
int print_number(int n)
{
	unsigned int abs_n = n;
	int len = 0;

	if (n < 0)
	{
		len += write(1, "-", 1);
		abs_n = -n;
	}

	if (abs_n / 10)
		len += print_number(abs_n / 10);

	len += write(1, &"0123456789"[abs_n % 10], 1);

	return (len);
}
