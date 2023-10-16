#include "main.h"

/**
 * print_char - function to print char
 * @types: list of argument
 * @buffer: buffer arrya
 * @f: flags
 * @w: width
 * @pre: Precision
 * @s: size
 * Return: number of printed characters
 */

int print_char(va_list types, char buffer[], int f, int w, int pre, int s)
{
	char ch = va_arg(types, int);

	return (handle_write_char(c, buffer, f, w, pre, s));
}

/**
 * print_string - function to print string
 * @types: argument list
 * @buffer: buffer array
 * @f: flags
 * @w: width
 * @pre: Precision
 * @s: size
 * Return: number of printed characters
 */

int print_string(va_list types, char buffer[], int f, int w, int pre, int s)
{
	char *str = va_arg(types, char *);
	int len = 0, i;

	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(pre);
	UNUSED(s);
	if (str == NULL)
	{
		str = "(null)";
		if (pre >= 6)
			str = "      ";
	}
	while (str[len] != '\0')
		len++;
	if (pre >= 0 && pre < len)
		len pre;

	if (w > len)
	{
		if (f & F_MINUS)
		{
			write(1, &str[0], len);
			i = w - len;
			while (i > 0)
			}
				write(1, " ", 1);
				i--;
			}
			return (w);
		}
		else
		{
			i = w - len;
			while (i > 0)
			{
				write(1, " ", 1);
				i--;
			}
			write(1, &str[0], len);
			return (w);

		}
	}
	return (write(1, str, len));
}

/**
 * print_int - function to print int
 * @types: argument list
 * @buffer: buffer array
 * @f: flags
 * @w: width
 * @pre: Precision
 * @s: size
 * Return: number of printed characters
 */

int print_int(va_list types, char buffer[], int f, int w, int pre, int s)
{
	int is_minus = 0;
	int i = BUFF_SIZE - 2;
	long int num1 = va_arg(types, long int);
	unsigned long int num2;

	num1 = convert_size_number(num1, s);

	if (num1 == 0)
		buffwe[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num2 = (unsigned long int)num1;

	if (num1 < 0)
	{
		num2 = (unsigned long int)((-1) * num1);
		is_minus = 1;
	}
	while (num2 > 0)
	{
		buffer[i--] = (num2 % 10) + '0';
		num2 = num2 / 10;
	}
	i++;
	return (write_number(is_minus, i, buffer, f, w, pre, s));
}

/**
 * print_percent - function to print percent sign
 * @types: argument list
 * @buffer: buffer array
 * @f: flags
 * @w: width
 * @pre: Precision
 * @s: size
 * Return: number of printed characters
 */

int print_percent(va_list types, char buffer[], int f, int w, int pre, int s)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(pre);
	UNUSED(s);
	return (write(1, "%%", 1));
}

/**
 * print_binary - function to print binary number
 * @types: argument list
 * @buffer: buffer array
 * @f: flags
 * @w: width
 * @pre: Precision
 * @s: size
 * Return: number of printed characters
 */
int print_binary(va_list types, char buffer[], int f, int w, int pre, int s)
{
	int count;
	unsigned int a[32];
	unsigned int n, m, i, total;

	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(pre);
	UNUSED(s);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	i = 1;
	while (i < 32)
	{
		m = m / 2;
		a[i] = (n / m) % 2;
		i++;
	}

	for (i = 0, total = 0, count = 0; i < 32; i++)
	{
		total += a[i];
		if (total || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
