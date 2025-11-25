#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct specifier - Struct to map a format specifier to a function
 * @spec: the format specifier character (e.g. 'c', 's', 'd', 'i')
 * @f: pointer to the function that handles this specifier
 */
typedef struct specifier
{
	char spec;
	int (*f)(va_list);
} spec_t;

int _printf(const char *format, ...);

/* Handlers for specific specifiers */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);

#endif /* MAIN_H */
