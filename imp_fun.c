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

/**
 * is_printable - function to check if char is printable
 * @c: character
 * Return: 1 if true 0 if false
 */
int is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/**
 * convert_size_number - cast number
 * @num: number input
 * @size: cast type
 * Return: casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_SHORT)
		return ((short)num);
	else if (size == S_LONG)
		return (num);
	return ((int)num);
}

/**
 * int convert_size_unsgnd - cast number
 * @num: number input
 * @size: cast type
 * Return: casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_SHORT)
		return ((unsigned short)num);
	else if (size == S_LONG)
		return (num);
	return ((unsigned int)num);
}

/**
 * append_hexa_code - hexa to buffer
 * @ascii: ascii code
 * @buffer: array
 * @i: index
 * Return: Always 3
 */
int append_hexa_code(char ascii, char buffer[], int i)
{
	char maps[] = "123456789ABCDEF";

	if (ascii < 0)
		ascii *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = maps[ascii / 16];
	buffer[i] = maps[ascii % 16];

	return (3);
}
