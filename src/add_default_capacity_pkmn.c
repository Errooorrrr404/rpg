/*
** EPITECH PROJECT, 2019
** ALEXIS DESRUMAUX
** File description:
** file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "rpg.h"

int add_sprite_ct(capacity_t *capacity)
{
    capacity->name_ct = string2text("assets/font/pkmn.ttf",
    capacity->name, 12);
    if (!capacity->name_ct)
        return 84;
    return 0;
}

int get_capacity_next(capacity_t *ca, int id, file_parameters_t *files, int i)
{
    for (; files->capacity_params[id][i] != ' '; i++);
    ca->categorie = catch_str(i, ' ', files->capacity_params[id], ' ');
    i++;
    for (; files->capacity_params[id][i] != ' '; i++);
    i = get_information_stats_capacity(i, ca, files, id);
    if (i == -1 || !ca->categorie)
        return 84;
    for (; files->capacity_params[id][i] != ' '; i++);
    ca->pp = catch_str_int(i, ' ', files->capacity_params[id], ' ');
    ca->current_pp = ca->pp;
    if (!ca->pp)
        return 84;
    i++;
    for (; files->capacity_params[id][i] != ' '; i++);
    ca->cible = catch_str(i, ' ', files->capacity_params[id], '\0');
    if (!ca->cible)
        return 84;
    if (add_sprite_ct(ca) == 84)
        return 84;
    return 0;
}

capacity_t *get_capacity_by_id(int id, file_parameters_t *files)
{
    capacity_t *capacity = malloc(sizeof(capacity_t));
    int i = 0;

    if (!capacity)
        return (NULL);
    capacity->name = catch_str(i, '\0', files->capacity_params[id], ' ');
    if (!capacity->name)
        return NULL;
    for (; files->capacity_params[id][i] != ' '; i++);
    capacity->type = catch_str(i, ' ', files->capacity_params[id], ' ');
    if (!capacity->type)
        return NULL;
    i++;
    if (get_capacity_next(capacity, id, files, i) == 84)
        return NULL;
    return capacity;
}

int upper_level_by_capacity(pokemon_t *pokemon)
{
    int i = 0;
    int stop = 0;
    int level_capacity = 0;

    pokemon->moves = malloc(sizeof(capacity_t) * 4);
    while (stop != 1) {
        level_capacity = my_putint(pokemon->level_capacity[i]);
        if (pokemon->level_capacity[i + 1] == NULL || pokemon->level <
            level_capacity)
            stop = 1;
        if (stop != 1)
            i++;
    }
    return (i);
}

int add_default_capacity(pokemon_t *pokemon, file_parameters_t *files)
{
    int i = 0;
    int k = 0;
    int j = 0;

    i = upper_level_by_capacity(pokemon);
    if (i == -1)
        return 84;
    j = i;
    for (; i != 0 && k != 4; k++, i--);
    pokemon->nbmoves = k;
    k = 0;
    while (i != j) {
        pokemon->moves[k] = get_capacity_by_id(my_putint(pokemon->capacity[i]),
            files);
        if (!pokemon->moves[k])
            return 84;
        i++;
        k++;
    }
    return 0;
}