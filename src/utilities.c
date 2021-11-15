/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** check.c
*/

#include <SFML/Graphics/Font.h>
#include "rpg.h"
#include "my.h"

void destroy_text_display_stats(pkmn_player_t *pkmn_bag, int i)
{
    sfText_destroy(pkmn_bag->pokemon[i]->pv_pkmn);
    sfText_destroy(pkmn_bag->pokemon[i]->attack_pkmn);
    sfText_destroy(pkmn_bag->pokemon[i]->defense_pkmn);
    sfText_destroy(pkmn_bag->pokemon[i]->speed_pkmn);
}

int define_pkmn_id_next(char *level, char **pkmn_p, int line, pokemon_t *pkmn)
{
    if (define_basic_stats_pkmn(line + 1, level, pkmn_p, pkmn) == -1)
        return 84;
    if (add_sprite_pkmn(pkmn) == 84)
        return 84;
    if (add_pkmn_sound(pkmn) == 84)
        return (84);
    return 0;
}

int add_basic_parameter(char *str, pokemon_t *pkmn, char **pkmn_p, int line)
{
    if (!str || !pkmn->name)
        return 84;
    pkmn->evolve_level = -1;
    pkmn->next_id = -1;
    if (match_str(str, "--") == 0) {
        pkmn->evolve_level = catch_str_int(0, ':', pkmn_p[line + 4], '\0');
        pkmn->next_id = catch_str_int(0, ':', pkmn_p[line + 5], '\0');
        if (!pkmn->evolve_level || !pkmn->next_id)
            return 84;
        free(str);
    }
    return 0;
}

void display_pokemon_menu(pkmn_player_t *pkmn_bag, rpg_t *rpg, int i, int *pos)
{
    sfVector2f scale_origin = {.x = 1.25, .y = 1.25};

    set_element_bag(pkmn_bag, pos, i);
    sfRenderWindow_drawText(rpg->window,
    pkmn_bag->pokemon[i]->name_pkmn, NULL);
    sfRenderWindow_drawText(rpg->window,
    pkmn_bag->pokemon[i]->level_pkmn, NULL);
    sfRenderWindow_drawSprite(rpg->window,
    pkmn_bag->pokemon[i]->pkmn, NULL);
    sfSprite_setScale(pkmn_bag->pokemon[i]->pkmn, scale_origin);
}

void exec_stat_two(rpg_t *rpg, sfVector2f pos, sfFont *font)
{
    sfText_setCharacterSize(rpg->menu->how_to_play->name_player, 30);
    sfText_setColor(rpg->menu->how_to_play->name_player, sfBlack);
    sfText_setPosition(rpg->menu->how_to_play->name_player, pos);
    sfRenderWindow_drawText(rpg->window, rpg->menu->how_to_play->name_player,
    NULL);
    sfFont_destroy(font);
}