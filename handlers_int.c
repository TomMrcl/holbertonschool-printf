#include "main.h"

/**
 * print_number_recursive - prints a positive number using recursion
 * @n: the positive number to print
 *
 * Return: number of digits printed
 */
static int print_number_recursive(long int n)
{
	char digit;
	int count = 0;

	if (n / 10 != 0)
		count += print_number_recursive(n / 10);

	digit = (char)('0' + (n % 10));
	write(1, &digit, 1);
	count++;

	return (count);
}

/**
 * print_int - handles the %d and %i specifiers
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	long int num = n;
	int count = 0;
	char minus = '-';

	if (num == 0)
	{
		char zero = '0';

		write(1, &zero, 1);
		return (1);
	}

	if (num < 0)
	{
		write(1, &minus, 1);
		count++;
		num = -num; /* make it positive */
	}

	count += print_number_recursive(num);

	return (count);
}
