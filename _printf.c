#include "main.h"

/**
 * _itoa - Convert integer to ASCII string
 * @num: Integer to convert
 * @buffer: Buffer to store the result
 *
 * Return: Length of the string
 */
int _itoa(int num, char *buffer)
{
	int i = 0;

	if (num < 0)
	{
		buffer[i++] = '-';
		num = -num;
	}

	if (num == 0)
		buffer[i++] = '0';

	while (num != 0)
	{
		int digit = num % 10;

		buffer[i++] = digit + '0';
		num /= 10;
	}

	buffer[i] = '\0';

	int start = 0;
	int end = i - 1;

	while (start < end)
	{
		char temp = buffer[start];

		buffer[start] = buffer[end];
		buffer[end] = temp;
		start++;
		end--;
	}

	return (i);
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
	int count = 0, num, len;
	char c;
	const char *ptr;
	char *str, num_str[12];

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
				len = _itoa(num, num_str);
				count += write(1, num_str, len);
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
