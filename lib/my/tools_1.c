/*
** EPITECH PROJECT, 2019
** tools.c
** File description:
** tools.c
*/

#include "mylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

char *strconcate(char *origin, char *str)
{
    int i = my_strlen(origin);
    int k = 0;

    while (str[k] != '\0') {
        origin[i] = str[k];
        i++;
        k++;
    }
    origin[i] = '\0';
    return (origin);
}

int my_strlen_array(char **str)
{
    int i = 0;

    while (str[i] != NULL)
        i++;
    return i;
}

void print_strtab(char **strtab, char disp_separator)
{
    int i = 0;

    while (strtab[i] != NULL) {
        my_putstr(strtab[i]);
        if (strtab[i + 1] != NULL)
            my_putchar(disp_separator);
        i++;
    }
}