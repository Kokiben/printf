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

int printf_pointer(va_list val);
int printf_hex_aux(unsigned long int num);
int printf_HEX_aux(unsigned int num);
int printf_exclusive_string(va_list val);
int printf_HEX(va_list val);
int printf_hex(va_list val);
int printf_oct(va_list val);
int printf_unsigned(va_list args);
int printf_bin(va_list val);
int printf_srev(va_list args);
int printf_rot13(va_list args);
int printf_int(va_list args);
int printf_dec(va_list args);
int _strlen(char *s);
int *_strcpy(char *dest, char *src);
int _strlenc(const char *s);
int rev_string(char *s);
int _strlenc(const char *s);
int printf_37(void);
int printf_char(va_list val);
int printf_string(va_list val);
int _putchar(char c);
int _printf(const char *format, ...);

#endif
