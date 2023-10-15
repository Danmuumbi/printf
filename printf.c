#include "main.h"

void print_buffer(char buffer[], int *buff_indx);

/**
 * _print - Print function
 * @format: format
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	char buffer;
	int i, printed = 0, printed_chars = 0;
	va_list list;
	buffer[BUFF_SIZE];


	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/*Write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list)
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer, 
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer: print buffer function
 * @buffer: char array
 * @buff_ind: index
 */
void print_buffer(char buffer[], int *buff_indx)
{
	if (*buff_indx > 0)
		write(1, &buffer[0], *buff_indx);
	*buff_indx = 0;
}
