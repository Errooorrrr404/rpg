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

void free_capacity_struct(capacity_t **moves, int nbmoves)
{
    int i = 0;

    while (i != nbmoves) {
        free(moves[i]->name);
        sfText_destroy(moves[i]->name_ct);
        free(moves[i]->type);
        free(moves[i]->categorie);
        free(moves[i]->cible);
        free(moves[i]);
        i++;
    }
}

void free_pkmn_struct(pokemon_t *pokemon)
{
    sfSprite_destroy(pokemon->pkmn);
    sfSprite_destroy(pokemon->pkmn_battle);
    sfText_destroy(pokemon->name_pkmn);
    sfText_destroy(pokemon->level_pkmn);
    sfText_destroy(pokemon->type1_pkmn);
    sfText_destroy(pokemon->type2_pkmn);
    if (pokemon->type3_pkmn != NULL)
        sfText_destroy(pokemon->type3_pkmn);
    sfMusic_destroy(pokemon->sound);
    free(pokemon->name);
    free_strtab(pokemon->type);
    free_strtab(pokemon->level_capacity);
    free_capacity_struct(pokemon->moves, pokemon->nbmoves);
    free(pokemon);
}