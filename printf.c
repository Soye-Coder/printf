#include "holberton.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
        va_list arg;
        int i = 0, j = 0, count = 0;
        print_func_t funcs[] = {
                {'c', print_char},
                {'s', print_string},
                {'%', print_percent},
                {'d', print_int},
                {'i', print_int},
                {'b', print_binary},
                {'u', print_unsigned},
                {'o', print_octal},
                {'x', print_hex},
                {'X', print_hex_upper},
                {'p', print_pointer},
                {'r', print_reverse},
                {'R', print_rot13},
                {0, NULL}
        };

        va_start(arg, format);

        if (!format || (format[i] == '%' && format[i + 1] == '\0'))
                return (-1);

        while (format && format[i])
        {
                if (format[i] == '%')
                {
                        j = 0;
                        i++;
                        while (funcs[j].func)
                        {
                                if (format[i] == funcs[j].specifier)
                                {
                                        count += funcs[j].func(arg);
                                        break;
                                }
                                j++;
                        }
                        if (!funcs[j].func && format[i] != '%')
                        {
                                _putchar('%');
                                count++;
                                if (format[i] != '\0')
                                {
                                        _putchar(format[i]);
                                        count++;
                                }
                        }
                }
                else
                {
                        _putchar(format[i]);
                        count++;
                }
                i++;
        }

        va_end(arg);
        return (count);
}
