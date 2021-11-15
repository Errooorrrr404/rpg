/*
** EPITECH PROJECT, 2019
** to_strtab_int.c
** File description:
** to_strtab_int.c
*/

#include "mylib.h"
#include <stdlib.h>
#include <stdio.h>

char **to_strtab_int(char **tab, int nb)
{
    char *nb_str = malloc(sizeof(char) * 8);
    nb_str = int2char(nb_str, nb);
    tab = to_strtab_char(tab, nb_str);
    free(nb_str);
    return (tab);
}