#include "main.h"

/**
 * get_precision - function to find number precision
 * @format: formated string
 * @ip: list of argument to be printed
 * @arg: argument input
 *
 * Return: precision
 */

int get_precision(const char *format, int *ip, va_list arg)
{
	int pre = -1;
	int cip = *ip + 1;

	if (format[cip] != '.')
		return (pre);

	pre = 0;
	cip += 1;

	while (format[cip] != '\0')
	{
		if (is_digit(format[cip]))
		{
			pre *= 10;
			pre += format[cip] - '0';
		}
		else if (format[cip] == '*')
		{
			cip++;
			pre = va_arg(arg, int);
			break;
		}
		else
			break;
		cip++;
	}
	*ip = cip - 1;
	return (pre);
}
