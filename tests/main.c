#include <stdio.h>
#include "main.h"

/**
 * main - simple tests for our _printf
 *
 * Return: Always 0
 */
int main(void)
{
	int len, len2;

	len = _printf("Hello %s\n", "world");
	len2 = printf("Hello %s\n", "world");
	_printf("My length: %d\n", len);
	printf("Real length: %d\n", len2);

	_printf("Char: %c\n", 'A');
	printf("Char: %c\n", 'A');

	_printf("Percent: %%\n");
	printf("Percent: %%\n");

	_printf("Numbers: %d, %i\n", -123, 456);
	printf("Numbers: %d, %i\n", -123, 456);

	return (0);
}
