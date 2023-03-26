#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _strlen(char *s);
char *itoa(int num);

int _printf(const char *format, ...);
int _putchar(char c);

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);

#endif /* MAIN_H */
