/*
** EPITECH PROJECT, 2018
** mylib.h
** File description:
** mylib.h
*/
#include <stdarg.h>
#define MYLIB_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *my_strcpy(char *strdest, char *str);
void my_putnbr_long(long nb);
void my_putnbr_short(short nb);
void f_check1(int check, va_list va, char *spe, int i);
void f_check2(int check, va_list va, char *spe, int i);
void f_check3 (int check, va_list va, char *spe, int i);
void f_check4(int check, va_list va, char *spe, int i);
void f_check5(int check, va_list va, char *spe, int i);
void f_check6(int check, va_list va, char *spe, int i);
void f_check7(int check, va_list va, char *spe, int i);
int f_my_printfcond(char *spe, int i);
int f_dispflag_printf(char *spe, int check, int i);
void my_printf(char *spe, ...);
int f_carriage(char *spe, int i);
long my_putint(char *str);
float my_putfloat(char *str);
int f_y_bsq(int bytes, char *path);
int f_x1_bsq(int bytes, char *path);
int f_x_bsq(int bytes, char *path);
int f_lignebsq(int x, int y, int x1, int p);
char *int2char(char *str, int nb);
int f_puiss(int nb, int puiss);
int compteurdizaine(int nb);
char *to_strarg_int(char *strarg, int nb);
int nbarg_strarg_int(char *strarg, int option);
char *nbargsup_strarg_int(char *strarg, int nb, int lastarg);
char *nbargnull_strarg_int(char *strarg, int nb);
char *to_strarg_char(char *strarg, char *string);
int nbarg_strarg_char(char *strarg, int option);
char *nbargsup_strarg_char(char *strarg, char *string, int lastarg);
char *nbargnull_strarg_char(char *strarg, char *string);
int get_strarg_int(char *strarg, int nbarg);
char *recup_int_strarg(char *strarg, int k);
char *get_strarg_str(char *strarg, int nbarg);
char *recup_str_strarg(char *strarg, int k);
float f_puiss_float(float nb, int puiss);
char *float2char(char *strarg, char *op, float value);
char *to_strarg_float(char *strarg, char *op, float value);
int find_arg_strarg(char *strarg, int pos);
char *replace_strarg_int(char *strarg, int pos, int value);
char *cpy_replace_strarg(char *strarg, char *str1, int pos);
char *replace_strarg_float(char *strarg, int pos, char *op, float value);
char *replace_strarg_str(char *strarg, int pos, char *strsrc);
int match_str(char *src, char *match);
char **to_strtab_char(char **tab, char *str);
char **to_strtab_int(char **tab, int nb);
char *strconcate(char *origin, char *str);
int my_strlen_array(char **str);
void print_strtab(char **strtab, char disp_separator);
char **re_malloc_strtab(char **strtab);
char **define_strtab(int size);
void free_strtab(char **strtab);
void debug(char *balise);
char *get_next_line(int fd);
void my_putchar(char c);
int my_strlen(char const *str);
char *my_putstr(char *str);