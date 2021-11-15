/*
** EPITECH PROJECT, 2018
** HUB
** File description:
** get_strarg_str.c
*/

#include "mylib.h"
#include <stdlib.h>
#include <stdio.h>

int find_symbol_getstr(char *strarg, int k)
{
    int i = 0;

    while (strarg[k] != '#') {
        k++;
        i++;
    }
    return (i + 3);
}

char *recup_str_strarg(char *strarg, int k)
{
    char *str;
    int i = 0;

    str = malloc(find_symbol_getstr(strarg, k));
    while (strarg[k] != '#') {
        str[i] = strarg[k];
        k++;
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *get_strarg_str(char *strarg, int nbarg)
{
    int i = 0;
    int j = 0;
    int lastarg = 0;

    if (nbarg == 1)
    strarg = recup_str_strarg(strarg, 0);
    else if (nbarg > 1) {
        while (strarg[i] != '\0' && j != nbarg - 1) {
            if (strarg[i] == '#') {
                j++;
                lastarg = i;
            }
            i++;
        }
        strarg = recup_str_strarg(strarg, lastarg + 1);
    }
    return (strarg);
}
