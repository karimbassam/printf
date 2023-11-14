#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	const char *ptr;
	char *str;

	va_start(args, format);
	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr != '%')
			count += write(1, ptr, 1);
		else
		{
			switch (*(++ptr))
			{
				case 'c':
					c = (char)va_arg(args, int);
					count += write(1, &c, 1);
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					count += write(1, str, strlen(str));
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				case 'n':
					*va_arg(args, int *) = count;
					break;
			}
		}
	}
	va_end(args);
	return (count);
}
