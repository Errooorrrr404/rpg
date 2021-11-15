/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** task02
*/

#include "my.h"

char *my_putstr(char *str)
{
    int p = 0;

    while (str[p] != '\0') {
        my_putchar(str[p]);
        p++;
    }
    return (str);
}
