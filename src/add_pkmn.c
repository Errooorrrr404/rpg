/*
** EPITECH PROJECT, 2019
** ALEXIS DESRUMAUX
** File description:
** file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include "my.h"
#include "rpg.h"

char *find_line(char **pokemon_params, int *row)
{
    char *str = malloc(sizeof(char) * my_strlen(pokemon_params[row[0]]));

    if (!str)
        return NULL;
    for (; pokemon_params[row[0]][row[1]] != '\0'; row[2]++, row[1]++)
        str[row[2]] = pokemon_params[row[0]][row[1]];
    str[row[2]] = '\0';
    return str;
}

int find_line_id(int id_pkmn, char **pokemon_params)
{
    int row[3] = {0, 2, 0};
    int stop = 0;
    char *str;

    while (stop != 1) {
        if (pokemon_params[row[0]][0] == '/' &&
        pokemon_params[row[0]][1] == '/') {
            str = find_line(pokemon_params, row);
            if (!str)
                return 84;
            if (id_pkmn == my_putint(str))
                stop = 1;
            free(str);
            row[1] = 2;
            row[2] = 0;
        }
        (stop == 0) ? (row[0]++) : (row[0] = row[0]);
    }
    return (row[0]);
}

pokemon_t *define_pokemon_by_id(int id_pkmn, char *level, char **pokemon_params)
{
    pokemon_t *pokemon = malloc(sizeof(pokemon_t));
    int line = find_line_id(id_pkmn, pokemon_params);

    pokemon->case_pos_x = 0;
    pokemon->case_pos_y = 0;
    if (add_basic_parameters(pokemon, line, pokemon_params, id_pkmn) == 84)
        return NULL;
    line = move_by_level(line + 9, pokemon_params, pokemon);
    if (line == -1)
        return NULL;
    if (define_pkmn_id_next(level, pokemon_params, line, pokemon) == 84)
        return NULL;
    return (pokemon);
}

int nb_pkmn_game(char **pokemon_params)
{
    int id_max = -1;
    int i = 0;

    while (pokemon_params[i] != NULL) {
        if (pokemon_params[i][0] == '/' &&
        pokemon_params[i][1] == '/')
            id_max++;
        i++;
    }
    return (id_max);
}

pokemon_t *add_pkmn(char *id, char *level, file_parameters_t *files)
{
    int id_max = 0;
    int *random_id = NULL;
    int id_pkmn = 0;
    char **pokemon_params = files->pokemon_params;
    pokemon_t *pokemon;

    id_max = nb_pkmn_game(pokemon_params);
    if (match_str(id, "random") == 1) {
        random_id = binare_tab(0, id_max, 100);
        if (!random_id)
            return NULL;
        id_pkmn = random_value(0, id_max, 100, random_id);
    } else
        id_pkmn = my_putint(id);
    pokemon = define_pokemon_by_id(id_pkmn, level, pokemon_params);
    if (!pokemon)
        return NULL;
    if (add_default_capacity(pokemon, files) == 84)
        return NULL;
    return (pokemon);
}