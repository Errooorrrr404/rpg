/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** init.c
*/

#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Font.h>
#include <sys/wait.h>
#include <time.h>
#include "rpg.h"
#include "my.h"

int init_struct_then(rpg_t *rpg)
{
    rpg->menu->how_to_play = malloc(sizeof(htp_t));
    if (!rpg->game->pkmn_bag->pokemon[0] || !rpg->game->pkmn_bag->pokemon[1]
        || !rpg->game->pkmn_bag->pokemon[2] || !rpg->menu->how_to_play)
        return 84;
    rpg->game_state = 0;
    rpg->game->pkmn_bag->display_stats = 0;
    if (create_window(rpg) == 84 || create_menu(rpg->menu) == 84)
        return 84;
    rpg->game->music = sfMusic_createFromFile("assets/audio/game_music.ogg");
    rpg->menu->music_intro = sfMusic_createFromFile("assets/audio/intro.ogg");
    if (!rpg->game->music)
        return 84;
    sfMusic_setLoop(rpg->game->music, sfTrue);
    sfMusic_play(rpg->menu->music);
    rpg->game->clock_cb.clock_type = sfClock_create();
    return 0;
}

int init_struct_next(rpg_t *rpg)
{
    srand(time(NULL));
    rpg->game->pkmn_bag = malloc(sizeof(pkmn_player_t));
    if (!rpg->game->pkmn_bag)
        return 84;
    rpg->game->pkmn_bag->pokemon = malloc(sizeof(pokemon_t) * 4);
    if (!rpg->game->pkmn_bag->pokemon)
        return 84;
    rpg->game->pkmn_bag->nb_pokemon = 0;
    rpg->game->pkmn_bag->stats_menu =
    image2sprite("./assets/sprite/stats.png");
    if (!rpg->game->pkmn_bag->stats_menu)
        return 84;
    rpg->game->pkmn_bag->pokemon[0] = add_pkmn("random", "10", rpg->game->files);
    //rpg->game->pkmn_bag->pokemon[1] =
    //add_pkmn("random", "10", rpg->game->files);
    //rpg->game->pkmn_bag->pokemon[2] = add_pkmn("8", "30", rpg->game->files);
    rpg->game->pkmn_bag->nb_pokemon = 1;
    return init_struct_then(rpg);
}

int init_struct(rpg_t *rpg)
{
    rpg->menu = malloc(sizeof(menu_t));
    rpg->game = malloc(sizeof(game_t));
    if (!rpg->menu || !rpg->game)
        return 84;
    rpg->game->files = malloc(sizeof(file_parameters_t));
    if (!rpg->game->files)
        return 84;
    rpg->game->files->pokemon_params =
    file_to_tab("./assets/script/pkmn_parameters");
    rpg->game->files->capacity_params =
    file_to_tab("./assets/script/pkmn_capacity");
    rpg->game->pnj = manage_pnj();
    return init_struct_next(rpg);
}

sfSprite *init_sprite(char *filepath, sfVector2f vector)
{
    sfSprite *sprite = sfSprite_create();

    if (!sprite)
        return NULL;
    sfSprite_setTexture(sprite, sfTexture_createFromFile(filepath, NULL),
    sfTrue);
    sfSprite_setPosition(sprite, vector);
    return sprite;
}

sfSprite *init_sprite2(char *filepath)
{
    sfSprite *sprite = sfSprite_create();

    if (!sprite)
        return NULL;
    sfSprite_setTexture(sprite, sfTexture_createFromFile(filepath, NULL),
    sfTrue);
    return sprite;
}