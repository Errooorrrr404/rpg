/*
** EPITECH PROJECT, 2018
** HUB
** File description:
** replace_strarg_str.c
*/

#include "mylib.h"
#include <stdlib.h>
#include <stdio.h>

char *replace_strarg_str(char *strarg, int pos, char *strsrc)
{
    int i = 0;
    int sav_i = 0;
    char *str1 = malloc(my_strlen(strarg) + my_strlen(strsrc) * 4);

    sav_i = find_arg_strarg(strarg, pos - 1);
    i = 0;
    while (i != sav_i + 1) {
        str1[i] = strarg[i];
        i++;
    }
    str1 = to_strarg_char(str1, strsrc);
    str1 = cpy_replace_strarg(strarg, str1, pos);
    return (str1);
}
