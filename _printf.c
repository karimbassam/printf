#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 *
 * Return: Number of characters printed (excluding the null byte)
 * or -1 on error
 */
int _printf(const char *format, ...)
{
	char c;
	char *str;
	int n = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		switch (*format)
		{
		case '%':
			switch (*++format)
			{
			case 's':
				str = va_arg(args, char *);
				n += write(1, str, strlen(str));
				break;
			case 'c':
				c = (char)va_arg(args, int);
				n += write(1, &c, 1);
				break;
			case '%':
				c = '%';
				n += write(1, &c, 1);
				break;
			case 'n':
				*va_arg(args, int *) = n;
				break;
			default:
				write(1, format - 1, 1);
				break;
			}
			break;
		default:
			n += write(1, format, 1);
			break;
		}
		format++;
	}
	va_end(args);
	return (n);
}
