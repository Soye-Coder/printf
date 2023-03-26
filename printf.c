#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int count = 0;
    while (*format) {
        if (*format == '%') {
            switch (*(format+1)) {
                case 'c': {
                    char c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    while (*str) {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    break;
                }
                default: {
                    putchar('%');
                    putchar(*(format+1));
                    count += 2;
                    break;
                }
            }
            format += 2;
        } else {
            putchar(*format);
            format++;
            count++;
        }
    }
    va_end(args);
    return count;
}
