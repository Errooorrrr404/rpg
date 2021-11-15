/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** Task03 Day04
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i;
    int counter = 0;

    for (i = 0; str[i]; i++) {
        counter++;
    }
    return (counter);
}
