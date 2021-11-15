/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include "my.h"

void switch_print(char *str, int i, va_list(list), ...)
{
    if (str[i] == 's') {
        my_putstr(va_arg(list, char *));
    }
    if (str[i] == 'c') {
        my_putchar(va_arg(list, int));
    }
    if (str[i] == 'd' || str[i] == 'i') {
        my_put_nbr(va_arg(list, int));
    }
}

void print_ld(va_list(list), ...)
{
    my_put_nbr(va_arg(list, long));
}

void my_printf(char *str, ...)
{
    va_list list;
    int i = 0;
    va_start(list, str);

    while (str[i] != '\0') {
        if (str[i] == '%' && str[i + 1] == 'l' && str[i + 2] == 'd') {
            print_ld(list);
            i += 3;
        } else if (str[i] == '%') {
            i++;
            switch_print(str, i, list);
            i++;
        } else {
            my_putchar(str[i]);
            i++;
        }
        if (str[i] == '\0')
        return ;
    }
    va_end(list);
}
