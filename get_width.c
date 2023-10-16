#include "main.h"

/**
 * get_width - find width need to be printed
 * @format: the formated string
 * @ip: argument list to be printed
 * @arg: list of argument
 *
 * Return: width
 */

int get_width(const char *format, int *ip, va_list arg)
{
	int w = 0;
	int cip;

	cip = *ip + 1;
	while (format[cip] != '\0')
	{
		if (is_digit(format[cip]))
		{
			w *= 10;
			w += format[cip] - '0';
		}
		else if (format[cip] == '*')
		{
			cip++;
			w = va_arg(arg, int);
			break;
		}
		else
			break;
		cip++;
	}
	*ip = cip - 1;
	return (w);
}
