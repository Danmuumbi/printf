#include "main.c"

/**
 * handle_print - function print arguments
 * @format: input string format
 * @indx: index
 * @list_arg: argument list
 * @buffer: array
 * @f: flags
 * @w: width
 * @pre: Precision
 * @s: size
 *
 * Return: 1 or 2
 */

int handle_print(const char *format, int *indx, va_list list_arg,
		char buffer[], int f, int w, int pre, int s)
{
	int len = 0, pch = -1, i;
	fmt_T fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	i = 0;
	while (fmt_types[i].fmt != '\0')
	{
		if (fmt[*indx] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list_arg, buffer, f, w, pre, s));
		i++;
	}
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*indx] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			len += write(1, " ", 1);
		else if (w)
		{
			--(*indx);
			while (fmt[*indx] != ' ' && fmt[*indx] != '%')
			{
				--(*indx);
			}
			if (fmt[*indx] == ' ')
				--(*indx);
			return (1);
		}
		len += write(1, &fmt[*indx], 1);
		return (len);
	}
	return (pch);
}
