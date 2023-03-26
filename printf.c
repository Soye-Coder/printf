#include "main.h"

/**
 * _printf - Prints a formatted string
 * @format: the format string
 * @...: the optional arguments
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
  int i, count = 0;
  va_list args;
  print_handler handlers[] = {
      {'c', print_char},
      {'s', print_string},
      {'%', print_percent},
      {'d', print_integer},
      {'i', print_integer},
      {0, NULL}};

  va_start(args, format);

  for (i = 0; format[i]; i++)
  {
    if (format[i] == '%')
    {
      i++;
      while (format[i] == ' ')
        i++;
      if (format[i] == '\0')
        break;
      if (format[i] == '%')
      {
        _putchar('%');
        count++;
      }
      else
        count += call_handler(handlers, format[i], args);
    }
    else
    {
      _putchar(format[i]);
      count++;
    }
  }

  va_end(args);

  return (count);
}

/**
 * call_handler - Calls the correct print handler function
 * @handlers: the array of print handler structs
 * @specifier: the specifier character
 * @args
