#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _strlen(char *s);
char *itoa(int num);

#endif /* HOLBERTON_H */

#include "holberton.h"

/**
 * _printf - prints output according to a format.
 * @format: character string.
 *
 * Return: the number of characters printed (excluding the null byte used
 * to end output to strings)
 */
int _printf(const char *format, ...)
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

/**
 * _strlen - returns the length of a string.
 * @s: string.
 *
 * Return: length of a string.
 */
int _strlen(char *s)
{
        int len;

        for (len = 0; s[len] != '\0'; len++)
        {
                ;
        }

        return (len);
}

/**
 * itoa - converts an integer to a string.
 * @num: integer.
 *
 * Return: string representation of an integer.
 */
char *itoa(int num)
{
        char *str = malloc(12);
        int i = 0, neg = 0;

        if (num == 0)
        {
                str[i++] = '0';
        }
        else if (num < 0)
        {
                neg = 1;
                num = -num;
        }

        while (num != 0)
        {
                str[i++] = (num % 10) + '0';
                num /= 10;
        }

        if (neg)
        {
                str[i++] = '-';
        }

        str[i] = '\0';

        str = _strrev(str);

        return (str);
}

/**
 * _strrev - reverses a string.
 * @s: string.
 *
 * Return: reversed string.
 */
char *_strrev(char *s)
{
        int i, len = _strlen(s);
        char tmp;

        for (i = 0; i < len / 2; i++)
        {
                tmp = s[i];
                s[i] = s[len - i - 1];
                s[len - i - 1] = tmp;
        }

        return (s);
}
