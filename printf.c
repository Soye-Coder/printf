#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - prints output according to a format
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}


/**
 * _custom_printf - custom printf function that handles integers and strings
 * @format: character string.
 *
 * Return: the number of characters printed (excluding the null byte used
 * to end output to strings)
 */
int _custom_printf(const char *format, ...)
{
        va_list ap;
        int i, len = 0;
        char *str;

        va_start(ap, format);

        for (i = 0; format[i] != '\0'; i++)
        {
                if (format[i] == '%' && format[i + 1] == 'd')
                {
                        int num = va_arg(ap, int);
                        str = itoa(num);
                        len += write(1, str, _strlen(str));
                        i++;
                        free(str);
                }
                else if (format[i] == '%' && format[i + 1] == 'i')
                {
                        int num = va_arg(ap, int);
                        str = itoa(num);
                        len += write(1, str, _strlen(str));
                        i++;
                        free(str);
                }
                else if (format[i] == '%' && format[i + 1] == 's')
                {
                        char *s = va_arg(ap, char *);
                        len += write(1, s, _strlen(s));
                        i++;
                }
                else if (format[i] == '%' && format[i + 1] == '%')
                {
                        len += write(1, "%", 1);
                        i++;
                }
                else
                {
                        len += write(1, &format[i], 1);
                }
        }

        va_end(ap);

        return (len);
}

