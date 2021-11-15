/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** .h
*/

#ifndef MY_H_
#define MY_H_
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>
#include <stddef.h>
#include "mylib.h"

int my_getnbr(char const *str);
int my_put_nbr(long nb);
void my_putchar(char c);
char *my_putstr(char *str);
char *my_revstr(char *str);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strupcase(char *str);
char choose_letter(int i, char *str, int nb);
int conv_hexa_low(int nb);
char choose_letter_up(int i, char *str, int nb);
int conv_hexa_up(int nb);
int conv_octal(int nb);
int conv_bin(int nb);
void my_printf(char *str, ...);
#endif
