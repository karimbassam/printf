#include "main.h"

/**
 * _printf - custom print function
 * @format: format string
 *
 * Return: Number of printed characters without NULL
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	char *str;

	va_start(args, format);

	for (; *format; format++)
	{
		if (*format != '%')
		{
			count += write(1, format, 1);
		}
		else
		{
			switch (*(++format))
			{
				case 'c':
					c = (char)(va_arg(args, int));
					count += write(1, &c, 1);
					break;
				case 's':
					str = va_arg(args, char *);
					count += write(1, str, strlen(str));
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				case 'n':
					*va_arg(args, int*) = count;
					break;
			}
		}
	}


	va_end(args);
	return (count);
}
