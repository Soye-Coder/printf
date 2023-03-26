#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(va_list arg);
int print_integer(va_list arg);

/**
 * struct format - Struct format
 *
 * @fmt: The format
 * @f: The function associated
 */
typedef struct format
{
	char *fmt;
	int (*f)(va_list);
} format_t;

#endif /* MAIN_H */
