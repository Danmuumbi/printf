#include "main.h"

/**
 * get_size - function to get the size 
 * @format: formated string
 * @ip: pointer to list argument to be printed
 *
 * Return: size
 */

int get_size(const char *format, int *ip)
{
	int s = 0;
	int cip = *ip + 1;

	if (format[cip] == 'h')
		s = S_SHORT;
	else if (format[cip] == 'l')
		s = S_LONG;

	if (s == 0)
		*ip = cip - 1;
	else
		*ip = cip;
	return (s);
}
