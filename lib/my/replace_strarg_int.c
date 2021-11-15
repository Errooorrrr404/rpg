/*
** EPITECH PROJECT, 2018
** HUB
** File description:
** replace_strarg_int.c
*/

#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

char *replace_strarg_int(char *strarg, int pos, int value)
{
    int i = 0;
    int sav_i = 0;
    char *str1;

    if (value >= 0)
        str1 = malloc(my_strlen(strarg) + sizeof(int) * value);
    else if (value < 0)
        str1 = malloc(my_strlen(strarg) + sizeof(int) * value * (-1));
    sav_i = find_arg_strarg(strarg, pos - 1);
    i = 0;
    while (i != sav_i + 1) {
        str1[i] = strarg[i];
        i++;
    }
    str1[sav_i + 1] = '\0';
    str1 = to_strarg_int(str1, value);
    str1 = cpy_replace_strarg(strarg, str1, pos);
    return (str1);
}
