#include "main.h"

/**
 * print_char - Prints a character
 * @args: the character to print
 *
 * Return: the number of characters printed
 */
int print_char(va_list args)
{
  return (_putchar(va_arg(args, int)));
}

/**
 * print_string - Prints a string
 * @args: the string to print
 *
 * Return: the number of characters printed
 */
int print_string(va_list args)
{
  int i;
  char *str = va_arg(args, char *);

  if (str == NULL)
    str = "(null)";

  for (i = 0; str[i]; i++)
    _putchar(str[i]);

  return (i);
}

/**
 * print_percent - Prints a percent symbol
 * @args: unused argument
 *
 * Return: the number of characters printed
 */
int print_percent(va_list args __attribute__((unused)))
{
  _putchar('%');
  return (1);
}

/**
 * print_integer - Prints an integer
 * @args: the integer to print
 *
 * Return: the number of characters printed
 */
int print_integer(va_list args)
{
  int n = va_arg(args, int);
  int i, k = 1000000000, digit, count = 0;
  unsigned int num;

  if (n < 0)
  {
    _putchar('-');
    count++;
    num = -n;
  }
  else
    num = n;

  while (k > 1)
  {
    if (num >= k)
    {
      digit = num / k;
      num %= k;
      _putchar(digit + '0');
      count++;
    }
    k /= 10;
  }

  _putchar(num + '0');
  count++;

  return (count);
}
