#include "main.h"

/**
 * print_char - print character
 * @c: charater to be printed
 * Return: num of printed bytes
 */
int print_char(int c)
{
	char ch;

	ch = c;
	return (write(1, &ch, 1));
}
/**
 * print_digit - print number
 * @n: number to be printed
 * Return: num of printed bytes
 */

int print_digit(int n)
{
	int count;
	char *symbol;

	symbol = "0123456789";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n) + 1);
	}
	else if (n < 10)
		return (print_char(symbol[n]));

	count = print_digit(n / 10);
	return (count + print_digit(n % 10));
}

/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, num;
	char c;
	const char *ptr;
	char *str;

	va_start(args, format);
	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr != '%')
			count += write(1, ptr, 1);
		else
		{
			switch (*(++ptr))
			{
			case 'i':
			case 'd':
				num = va_arg(args, int);
				count += print_digit(num);
				break;
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
			default:
				count += write(1, "%", 1);
				count += write(1, ptr, 1);
			}
		}
	}
	va_end(args);
	return (count);
}
