/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include <SFML/Graphics/Font.h>
#include "rpg.h"
#include "my.h"

int create_htp1(menu_t *menu)
{
    sfVector2f pos = {0, 0};

    menu->sp_menu = init_sprite("assets/sprite/menu.png", pos);
    menu->how_to_play->h1_1 = init_sprite2("assets/sprite/how_to_play1.png");
    menu->how_to_play->h1_2 = init_sprite2("assets/sprite/how_to_play1_2.png");
    menu->how_to_play->h2_1 = init_sprite2("assets/sprite/how_to_play2_1.png");
    menu->how_to_play->h2_2 = init_sprite2("assets/sprite/how_to_play2_2.png");
    if (!menu->sp_menu || !menu->how_to_play->h1_1 || !menu->how_to_play->h1_2
    || !menu->how_to_play->h2_1 || !menu->how_to_play->h2_2)
        return 84;
    menu->how_to_play->h2_3 = init_sprite2("assets/sprite/how_to_play2_3.png");
    menu->how_to_play->h3_1 = init_sprite2("assets/sprite/how_to_play3_1.png");
    menu->how_to_play->h3_2 = init_sprite2("assets/sprite/how_to_play3_2.png");
    menu->how_to_play->h4_1 = init_sprite2("assets/sprite/how_to_play4_1.png");
    if (!menu->how_to_play->h2_3 || !menu->how_to_play->h3_1
    || !menu->how_to_play->h3_2 || !menu->how_to_play->h4_1)
        return 84;
    return 0;
}

int create_htp2(menu_t *menu)
{
    menu->how_to_play->h4_2 = init_sprite2("assets/sprite/how_to_play4_2.png");
    menu->how_to_play->h5_1 = init_sprite2("assets/sprite/how_to_play5_1.png");
    menu->how_to_play->h5_2 = init_sprite2("assets/sprite/how_to_play5_2.png");
    menu->how_to_play->h5_3 = init_sprite2("assets/sprite/how_to_play5_3.png");
    if (!menu->how_to_play->h4_2 || !menu->how_to_play->h5_1
        || !menu->how_to_play->h5_2 || !menu->how_to_play->h5_3)
        return 84;
    menu->how_to_play->h6_1 = init_sprite2("assets/sprite/how_to_play6_1.png");
    menu->how_to_play->h6_2 = init_sprite2("assets/sprite/how_to_play6_2.png");
    menu->how_to_play->h6_3 = init_sprite2("assets/sprite/how_to_play6_3.png");
    menu->how_to_play->boy = init_sprite2("assets/sprite/select_boy.png");
    if (!menu->how_to_play->h6_1 || !menu->how_to_play->h6_2
        || !menu->how_to_play->h6_3 || !menu->how_to_play->boy)
        return 84;
    return 0;
}

int init_player(menu_t *menu)
{
    menu->how_to_play->girl = init_sprite2("assets/sprite/select_girl.png");
    menu->how_to_play->select = init_sprite2("assets/sprite/select_perso.png");
    menu->how_to_play->before_playing =
    init_sprite2("assets/sprite/before_playing.png");
    menu->how_to_play->cl_move = sfClock_create();
    menu->how_to_play->name_player = sfText_create();
    if (!menu->how_to_play->girl || !menu->how_to_play->select
        || !menu->how_to_play->before_playing || !menu->how_to_play->cl_move
        || !menu->how_to_play->name_player)
        return 84;
    return 0;
}

void boutton_menu(menu_t *menu)
{
    menu->play = sfText_create();
    menu->quit = sfText_create();
    menu->pos_play = set_position_csfml(420, 280);
    menu->pos_quit = set_position_csfml(420, 370);
    sfFont* font = sfFont_createFromFile("assets/font/pkmn.ttf");

    sfText_setFont(menu->play, font);
    sfText_setFont(menu->quit, font);
    sfText_setString(menu->play, "PLAY");
    sfText_setString(menu->quit, "QUIT");
    sfText_setColor(menu->play, sfWhite);
    sfText_setColor(menu->quit, sfWhite);
    sfText_setPosition(menu->play, menu->pos_play);
    sfText_setPosition(menu->quit, menu->pos_quit);
}

int create_menu(menu_t *menu)
{
    menu->music = sfMusic_createFromFile("assets/audio/menu_music.ogg");
    if (!menu->music)
        return 84;
    sfMusic_setLoop(menu->music, sfTrue);
    if (create_htp1(menu) == 84 || create_htp2(menu) == 84)
        return 84;
    if (init_player(menu) == 84)
        return 84;
    menu->how_to_play->state = -1;
    menu->how_to_play->name = malloc(sizeof(char) * 16);
    for (int i = 0; i != 16; i++)
        menu->how_to_play->name[i] = ' ';
    menu->how_to_play->name[16] = '\0';
    boutton_menu(menu);
    return 0;
}