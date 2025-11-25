#include "main.h"

/**
 * print_char - handles the %c specifier
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - handles the %s specifier
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int i = 0;

	if (s == NULL)
		s = "(null)";

	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}

	return (i);
}

/**
 * print_percent - handles the %% specifier
 * @args: list of arguments (unused)
 *
 * Return: number of characters printed
 */
int print_percent(va_list args)
{
	char c = '%';

	(void)args;

	write(1, &c, 1);
	return (1);
}
