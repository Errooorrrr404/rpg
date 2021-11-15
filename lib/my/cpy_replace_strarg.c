/*
** EPITECH PROJECT, 2018
** HUB
** File description:
** cpy_replace_strarg.c
*/

#include "mylib.h"

char *cpy_replace_strarg(char *strarg, char *str1, int pos)
{
    int i = find_arg_strarg(strarg, pos) + 1;
    int j = my_strlen(str1);

    while (strarg[i] != '\0') {
        str1[j] = strarg[i];
        j++;
        i++;
    }
    str1[j] = '\0';
    return (str1);
}