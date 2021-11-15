/*
** EPITECH PROJECT, 2018
** HUB
** File description:
** to_strarg_float.c
*/

#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

char *to_strarg_float(char *strarg, char *op, float value)
{
    char *str = malloc(500);
    str = float2char(strarg, op, value);
    strarg = to_strarg_char(strarg, str);
    return (strarg);
}
