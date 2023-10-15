#define MAIN_H
#ifndef MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int get_width(const char *format, int *ip, va_list arg);
int is_digit(char c);

#endif /* MAIN_H */
