#include "main.h"

/**
 * get_spec_handler - find the handler for a format specifier
 * @c: the format specifier character
 *
 * Return: pointer to the handler function, or NULL if not found
 */
static int (*get_spec_handler(char c))(va_list)
{
	spec_t specs[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL}
	};
	int i;

	for (i = 0; specs[i].spec != '\0'; i++)
	{
		if (specs[i].spec == c)
			return (specs[i].f);
	}
	return (NULL);
}

/**
 * _printf - produces output according to a format
 * @format: a character string with optional format specifiers
 *
 * Return: the number of characters printed (excluding the null byte),
 *         or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;
	int (*handler)(va_list);

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			handler = get_spec_handler(format[i]);
			if (handler != NULL)
			{
				count += handler(args);
			}
			else
			{
				/* Unknown specifier: print '%' then the character */
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}
		}
		i++;
	}

	va_end(args);
	return (count);
}
