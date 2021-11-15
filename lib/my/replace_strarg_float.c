/*
** EPITECH PROJECT, 2018
** HUB
** File description:
** replace_strarg_float.c
*/

#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

char *replace_strarg_float(char *strarg, int pos, char *op, float value)
{
    int i = 0;
    int sav_i = 0;
    char *str1 = malloc(my_strlen(strarg) + sizeof(float) * value);

    sav_i = find_arg_strarg(strarg, pos - 1);
    i = 0;
    while (i != sav_i + 1) {
        str1[i] = strarg[i];
        i++;
    }
    str1 = to_strarg_float(str1, op, value);
    str1 = cpy_replace_strarg(strarg, str1, pos);
    return (str1);
}
