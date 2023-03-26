#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
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
                {
                    char *str = va_arg(args, char *);
                    while (*str)
                    {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    count++;
                    break;
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    if (num < 0)
                    {
                        num = -num;
                        putchar('-');
                        count++;
                    }
                    int rev = 0, digit;
                    do
                    {
                        digit = num % 10;
                        rev = rev * 10 + digit;
                        num = num / 10;
                    } while (num != 0);

                    do
                    {
                        digit = rev % 10;
                        putchar(digit + '0');
                        rev = rev / 10;
                        count++;
                    } while (rev != 0);
                    break;
                }
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
