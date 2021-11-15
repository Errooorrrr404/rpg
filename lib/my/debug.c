/*
** EPITECH PROJECT, 2019
** debug.c
** File description:
** debug.c
*/

#include "mylib.h"
#include "stdlib.h"
#include "stdio.h"

void debug(char *balise)
{
    my_putstr(balise);
    get_next_line(0);
}