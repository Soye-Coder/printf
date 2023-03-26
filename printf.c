#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format.
 * @format: character string
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i, len = 0;
    char *str;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    len += _putchar(va_arg(args, int));
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (str == NULL)
                        str = "(null)";
                    len += _puts(str);
                    break;
                case '%':
                    len += _putchar('%');
                    break;
                case 'd':
                case 'i':
                    len += print_number(va_arg(args, int));
                    break;
                default:
                    len += _putchar('%');
                    len += _putchar(format[i]);
            }
        }
        else
        {
            len += _putchar(format[i]);
        }
    }

    va_end(args);

    return (len);
}
