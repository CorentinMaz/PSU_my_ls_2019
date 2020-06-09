/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** all prototypes
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <linux/types.h>

void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_strlen(char const *);
int my_putstr(char const *);
int my_getnbr(char const *);
int my_get_nbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
char *my_strncat(char *, char const *, int);
int my_show_word_array(char * const *);
int my_get_nb(char c);
int my_octal(va_list ap);
int my_binary(va_list ap);
int my_hexa(va_list ap);
int my_hexa_capital(va_list ap);
void specific(const char *std, int i);
int my_put_pos(int);
int no_printable(char const *std);
int my_printf(const char *std, ...);

#endif