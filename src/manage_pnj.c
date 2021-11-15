/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** manage_pnj
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "rpg.h"

void free_pnj(char *id, char *or, char *nom)
{
    free(id);
    free(or);
    free(nom);
}

pnj_t *init_pnj(char **charact)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));
    char *id = catch_str(0, '=', charact[0], '\0');
    char *or = catch_str(0, '=', charact[1], '\0');
    char *nom = catch_str(0, '=', charact[2], '\0');

    if (!id || !or || !nom || !pnj)
        return NULL;
    pnj->id = my_putint(id);
    pnj->orientation = my_putint(or);
    pnj->nom = nom;
    if (pnj->id == 0)
        pnj->character = init_sprite("assets/sprite/sorbier.png",
                set_position_csfml(0, 0));
    else
        pnj->character = init_sprite("assets/sprite/gamin.png",
                set_position_csfml(-1865, -1100));
    if (!pnj->character)
        return NULL;
    free_pnj(id, or, nom);
    return pnj;
}

pnj_t **manage_pnj(void)
{
    int fd = open("assets/script/pnj", O_RDONLY);
    char **first_char = malloc(sizeof(char *) * 6);
    pnj_t **pnj = malloc(sizeof(pnj_t) * 2);

    if (fd == -1 || !pnj || !first_char)
        return NULL;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 6; i++) {
            first_char[i] = get_next_line(fd);
            if (!first_char[i])
                return NULL;
        }
        pnj[j] = init_pnj(first_char);
    }
    for (int i = 0; first_char[i]; i++)
        free(first_char[i]);
    free(first_char);
    return pnj;
}