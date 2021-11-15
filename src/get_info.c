/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** get_info
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "rpg.h"

int get_info_next(int i, capacity_t *capacity,
    file_parameters_t *files, int id)
{
    char *str = NULL;

    for (i++; files->capacity_params[id][i] != ' '; i++);
    str = catch_str(i, ' ', files->capacity_params[id], ' ');
    if (!str)
        return -1;
    if (match_str(str, "--") == 1)
        capacity->precision = -1;
    else {
        capacity->precision = catch_str_int(i, ' ', files->capacity_params[id],
        ' ');
        if (!capacity->puissance)
            return -1;
    }
    free(str);
    return 0;
}

int get_information_stats_capacity(int i, capacity_t *capacity,
    file_parameters_t *files, int id)
{
    char *str = catch_str(i, ' ', files->capacity_params[id], ' ');

    if (!str)
        return -1;
    if (match_str(str, "--") == 1)
        capacity->puissance = -1;
    else {
        capacity->puissance = catch_str_int(i, ' ', files->capacity_params[id],
        ' ');
        if (!capacity->puissance)
            return -1;
    }
    free(str);
    i = get_info_next(i, capacity, files, id);
    return i + 1;
}