/*
** EPITECH PROJECT, 2019
** to_strtab_char.c
** File description:
** to_strtab_char.c
*/

#include "mylib.h"
#include <stdlib.h>
#include <stdio.h>

char **tab_strsup(char **tab, char *str)
{
    int i = 0;
    int j = 0;

    while (tab[i] != NULL) {
        i++;
    }
    tab[i] = malloc(my_strlen(str) + 3);
    if (!tab[i])
        return NULL;
    while (str[j] != '\0') {
        tab[i][j] = str[j];
        j++;
    }
    tab[i][j] = '\0';
    tab[i + 1] = NULL;
    return (tab);
}

char **tab_strnull(char **tab, char *str)
{
    int i = 0;

    tab[0] = malloc(my_strlen(str) + 3);
    if (!tab[0])
        return NULL;
    while (str[i] != '\0') {
        tab[0][i] = str[i];
        i++;
    }
    tab[0][i] = '\0';
    tab[i + 1] = NULL;
    return (tab);
}

char **to_strtab_char(char **tab, char *str)
{
    if (tab[0] != NULL) {
        tab = tab_strsup(tab, str);
        if (!tab)
            return NULL;
    } else {
        tab = tab_strnull(tab, str);
        if (!tab)
            return NULL;
    }
    return (tab);
}