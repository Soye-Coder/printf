#include <stdio.h>
#include <stdarg.h>

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
                    break;

                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;

                case '%':
                    putchar('%');
                    break;

                case 'd':
                case 'i':
                    count += printf("%d", va_arg(args, int));
                    break;

                default:
                    putchar('%');
                    putchar(*format);
                    break;
            }
        }
        else
        {
            putchar(*format);
        }

        format++;
        count++;
    }

    va_end(args);
    return count;
}
