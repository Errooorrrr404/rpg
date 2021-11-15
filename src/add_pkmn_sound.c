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

int add_pkmn_sound(pokemon_t *pokemon)
{
    char *id = malloc(sizeof(char) * sizeof(int) * 2);
    char *ogg = malloc(sizeof(char) * 10);
    char *path;

    if (id == NULL || ogg == NULL)
        return (84);
    id = int2char(id, pokemon->id);
    path = malloc(sizeof(char) * (100 + my_strlen(id)));
    if (path == NULL)
        return (84);
    path = my_strcpy(path, "./assets/audio/pokemon/");
    path = strconcate(path, id);
    ogg = my_strcpy(ogg, ".ogg");
    path = strconcate(path, ogg);
    pokemon->sound = sfMusic_createFromFile(path);
    if (pokemon->sound == NULL)
        return (84);
    free(id);
    free(ogg);
    free(path);
}