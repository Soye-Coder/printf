#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Prints formatted output to stdout
 * @format: Format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i, count = 0;

    va_start(args, format);

    for (i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            i++;

            switch (format[i])
            {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;

                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;

                case '%':
                    count += putchar('%');
                    break;

                default:
                    count += putchar('%');
                    count += putchar(format[i]);
                    break;
            }
        }
        else
        {
            count += putchar(format[i]);
        }
    }

    va_end(args);

    return count;
}
