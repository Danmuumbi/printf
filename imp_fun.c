#include "main.h"

/**
 * is_digit - check if char is digit
 * @c: input char
 *
 * Return: 1 if digit and 0 if not
 */

int is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
