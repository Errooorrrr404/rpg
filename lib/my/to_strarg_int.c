/*
** EPITECH PROJECT, 2018
** HUB
** File description:
** Tostrarg_int.c
*/

#include <stdlib.h>
#include "mylib.h"
#include <stdio.h>

char *nbargnull_strarg_int(char *strarg, int nb)
{
    int j = 0;

    strarg = int2char(strarg, nb);
    while (strarg[j] != '\0') {
        j++;
    }
    strarg[j] = '#';
    strarg[j + 1] = '\0';
    return (strarg);
}

char *nbargsup_strarg_int(char *strarg, int nb, int lastarg)
{
    int j = 0;
    char *str = malloc(my_strlen(strarg) + 50);

    lastarg++;
    str = int2char(str, nb);
    while (str[j] != '\0') {
        strarg[lastarg] = str[j];
        lastarg++;
        j++;
    }
    strarg[lastarg] = '\0';
    j = 0;
    while (strarg[j] != '\0') {
        j++;
    }
    strarg[j] = '#';
    strarg[j + 1] = '\0';
    return (strarg);
}

int nbarg_strarg_int(char *strarg, int option)
{
    int i = 0;
    int nbarg = 0;
    int lastarg = 0;

    while (strarg[i] != '\0') {
        if (strarg[i] == '#') {
            nbarg++;
            lastarg = i;
        }
        i++;
    }
    if (option == 1)
        return (lastarg);
    if (option == 2)
        return (nbarg);
    return (0);
}

char *to_strarg_int(char *strarg, int nb)
{
    int nbarg = 0;
    int lastarg;

    lastarg = nbarg_strarg_int(strarg, 1);
    nbarg = nbarg_strarg_int(strarg, 2);
    if (nbarg > 0)
        strarg = nbargsup_strarg_int(strarg, nb, lastarg);
    if (nbarg == 0)
        strarg = nbargnull_strarg_int(strarg, nb);
    return (strarg);
}
