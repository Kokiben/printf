#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
* struct parameters - parameters struct
*
* @unsign: flag if insigned value
*
* @plus_flag: on if puls_flag specified
* @space_flag: ..
* @hashtag_flag: ..
* @zero_flag: ..
* @minus_flag: ..
*
* @width: ..
* @precision: ..
*
* @h_modifier: ..
* @l_modifier: ..
*/

typedef struct parameters
{
unsigned int unsign: 1;
unsigned int plus_flag:  1;
unsigned int space_flag: 1;
unsigned int hashtag_flag: 1;
unsigned int zero_flag: 1;
unsigned int minus_flag: 1;

unsigned int width;
unsigned int precision;

unsigned int h_modifier: 1;
unsigned int l_modifier: 1;
} params_t;

/**
* struct specifier - struct token
*
* @specifier: format token
* @f: The funcion associated
*/
typedef struct specifier
{
char *specifier;
int (*f)(va_list, params_t *);
} specifier_t;

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c module */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_precent(va_list ap, params_t *params);
int print_s(va_list ap, params_t *params);

/* number.c module */
char *convert(long int num, int base, int flags, params_t, *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* specifier.c module */
int (*get_specifier(char *s)(va_list ap, params_t *params);
int get_print(va_list ap, params_t *params);
int get_flag(va_list ap, params_t *params);
int get_modifier(va_list ap, params_t *params);
char *get_width(va_list ap, params_t *params);

/* convert_number.c module */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* print_number.c module */
int _isdigit(char c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* params.c module */
void init_params(params_t *params, va_list ap);

/* string_fields.c module */
char *get_precision(char *p, params_t *params, va_list ap);

/* printf.c module */
int _printf(const char *format, ...);

#endif
