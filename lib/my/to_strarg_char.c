/*
** EPITECH PROJECT, 2018
** HUB
** File description:
** to_strarg_char.c
*/

#include "mylib.h"
#include <stdlib.h>
#include <stdio.h>

char *nbargnull_strarg_char(char *strarg, char *string)
{
    int j = 0;

    strarg = my_strcpy(strarg, string);
    while (strarg[j] != '\0') {
        j++;
    }
    strarg[j] = '#';
    strarg[j + 1] = '\0';
    return (strarg);
}

char *nbargsup_strarg_char(char *strarg, char *string, int lastarg)
{
    int j = 0;
    char *str = malloc(my_strlen(strarg) + my_strlen(string) + 500);

    lastarg++;
    str = my_strcpy(str, string);
    while (str[j] != '\0') {
        strarg[lastarg] = str[j];
        lastarg++;
        j++;
    }
    j = 0;
    while (strarg[j] != '\0') {
        j++;
    }
    strarg[j] = '#';
    strarg[j + 1] = '\0';
    return (strarg);
}

int nbarg_strarg_char(char *strarg, int option)
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

char *to_strarg_char(char *strarg, char *string)
{
    int nbarg = 0;
    int lastarg;

    lastarg = nbarg_strarg_char(strarg, 1);
    nbarg = nbarg_strarg_char(strarg, 2);
    if (nbarg > 0)
        strarg = nbargsup_strarg_char(strarg, string, lastarg);
    if (nbarg == 0)
        strarg = nbargnull_strarg_char(strarg, string);
    return (strarg);
}
