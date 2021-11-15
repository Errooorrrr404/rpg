/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_game
*/

#include "rpg.h"
#include "my.h"

item_t create_item(char *name, char *nb, sfVector2f pos_item, sfVector2f pos_nb)
{
    int i = 0;
    item_t item;
    item.nb = malloc(sizeof(char) * (2));
    item.pos_item.x = pos_item.x;
    item.pos_item.y = pos_item.y;
    item.pos_nb.x = pos_nb.x;
    item.pos_nb.y = pos_nb.y;
    for (; nb[i] != '\0'; i++)
        item.nb[i] = nb[i];
    item.nb[i] = '\0';
    item.tx_name = string2text("assets/font/pkmn.ttf", name, 11);
    item.tx_nb = string2text("assets/font/pkmn.ttf", nb, 13);

    return (item);
}

void init_item(game_t *game)
{
    sfVector2f pos_potion = {275, 225};
    sfVector2f pos_total_soin = {275, 300};
    sfVector2f pos_pokeball = {275, 375};
    sfVector2f nb_potion = {390, 225};
    sfVector2f nb_soin = {390, 300};
    sfVector2f nb_poke = {390, 375};

    game->item = malloc(sizeof(item_t) * 3);
    game->item[0] = create_item("Potion", "x5", pos_potion, nb_potion);
    game->item[1] = create_item("Total Soin", "x5", pos_total_soin, nb_soin);
    game->item[2] = create_item("Pokeball", "x5", pos_pokeball, nb_poke);
}

void init_position_game(game_t *game)
{
    game->rect_player.left = 37;
    game->rect_player.top = 0;
    game->rect_player.width = 37;
    game->rect_player.height = 30;
    game->pos_player.x = 450;
    game->pos_player.y = 250;
    game->pos_bag.x = 150;
    game->pos_bag.y = 80;
    game->pos_map.x = -660;
    game->pos_map.y = -1300;
}

void init_assets_game(game_t *game)
{
    if (game->boy_girl == 1) {
        game->sp_player = init_sprite("assets/sprite/Personnage2.png",
        game->pos_player);
    } else if (game->boy_girl == 2) {
        game->sp_player = init_sprite("assets/sprite/Personnage.png",
        game->pos_player);
    }
    game->sp_bag = init_sprite("assets/sprite/bag.png", game->pos_bag);
    game->cl_move = sfClock_create();
    sfSprite_setPosition(game->sp_player, game->pos_player);
    sfSprite_setPosition(game->sp_bag, game->pos_bag);
    sfSprite_setTextureRect(game->sp_player, game->rect_player);
    game->sp_labo = init_sprite("assets/sprite/labo.png", game->pos_map);
    game->sp_map = init_sprite("assets/sprite/map.png", game->pos_map);
}

int create_game(game_t *game)
{
    init_item(game);
    init_position_game(game);
    init_assets_game(game);
    return (0);
}