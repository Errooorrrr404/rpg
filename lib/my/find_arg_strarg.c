/*
** EPITECH PROJECT, 2018
** HUB
** File description:
** find_arg_strarg.c
*/

#include "mylib.h"
#include <stdlib.h>

int find_arg_strarg(char *strarg, int pos)
{
    int nbarg = 0;
    int i = 0;
    int sav_i = 0;

    while (strarg[i] != '\0' && nbarg != pos) {
        if (strarg[i] == '#') {
            sav_i = i;
            nbarg++;
        }
        i++;
    }
    return (sav_i);
}
