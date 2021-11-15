/*
** EPITECH PROJECT, 2019
** Tek1
** File description:
** minishell
*/

#include "rpg.h"
#include "my.h"

int main(int ac, __attribute__((unused)) char **argv)
{
    if (ac != 1)
        return 84;
    return rpg();
}
