#include "main.h"

/**
 * print_unsigned - fuction to print unsigned number
 * @types: argument list
 * @buffer: array
 * @f: flags
 * @w: width
 * @pre: Precision
 * @s: size
 * Return: number of printed chars
 */

int print_unsigned(va_list types, char buffer[], int f, int w, int pre, int s)
{
	unsigned long int n = va_arg(types, unsigned long int);
	int i = BUFF_SIZE - 2;

	n = convert_size_unsgnd(n, s);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, f, w, pre, s));
}

/**
 * print_octal - fuction to print octal number
 * @types: argument list
 * @buffer: array
 * @f: flags
 * @w: width
 * @pre: Precision
 * @s: size
 * Return: number of printed chars
 */
int print_octal(va_list types, char buffer[], int f, int w, int pre, int s)
{
	unsigned long int n = va_arg(types, unsigned long int);
	unsigned long int init_n = n;
	int i = BUFF_SIZE - 2;

	UNUSED(w);

	n = convert_size_unsgnd(n, s);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer[i--] = (n % 8) + '0';
		n /= 8;
	}

	if (f & F_HASH && init_n != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, f, w, pre, s));
}

/**
 * print_hexadecimal - fuction to print hexadecimal number
 * @types: argument list
 * @buffer: array
 * @f: flags
 * @w: width
 * @pre: Precision
 * @s: size
 * Return: number of printed chars
 */
int print_hexadecimal(va_list types, char buffer[], int f,
		int w, int pre, int s)
{
	return (print_hexa(types, "0123456789abcdef", buffer, f,
				'x', w, pre, s));
}

/**
 * print_hexa_upper - fuction to print hexadecimal number in upper case
 * @types: argument list
 * @buffer: array
 * @f: flags
 * @w: width
 * @pre: Precision
 * @s: size
 * Return: number of printed chars
 */

int print_hexa_upper(va_list types, char buffer[], int f,
		int w, int pre, int s)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, f,
				'X', w, pre, s));
}

/**
 * print_hexa - print hexadecimal number in upper or lower case
 * @types: argument list
 * @maps: array to map the numbers
 * @buffer: array
 * @f: flags
 * @fch: flag char
 * @w: width
 * @pre: Precision
 * @s: size
 * Return: number of printed chars
 */

int print_hexa(va_list types, char maps[], char buffer[], int f, char fch,
		int w, int pre, int s)
{
	unsigned long int n = va_arg(types, unsigned long int);
	unsigned long int init_n = n;
	int i = BUFF_SIZE - 2;

	UNUSED(w);

	n = convert_size_unsgnd(n, s);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer[i--] = maps[n % 16];
		n /= 16;
	}
	if (f & F_HASH && init_n != 0)
	{
		buffer[i--] = fch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, f, w, pre, s));
}
