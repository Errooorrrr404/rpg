/*
** EPITECH PROJECT, 2019
** include
** File description:
** struct
*/

#include <SFML/Audio/Music.h>
#include <SFML/Config.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Shape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Export.h>
#include <SFML/Graphics/Shape.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>

typedef struct csfml_obj_s
{
    sfSprite * sprite;
    sfIntRect sprite_rect;
    sfVector2f sprite_p;
    sfText *txt;
    sfVector2f txt_p;
    sfVector2f scale;
} obj_t;

typedef struct clock_s
{
    sfClock *clock_type;
    sfTime time_type;
    float seconds;
} sfml_clock_t;

typedef struct pnj_s
{
    int id;
    int orientation;
    char *nom;
    char *dialogue;
    sfSprite *character;
} pnj_t;

typedef struct life_s
{
    int life;
    int life_max;
    sfSprite* sp_life;
    sfRectangleShape *rect_life;
    sfVector2f size_life;
    sfVector2f pos_life;
} life_t;

typedef struct capacity_s
{
    char *name;
    sfText *name_ct;
    sfVector2f name_pos;
    char *type;
    sfText *type_ct;
    sfVector2f type_pos;
    char *categorie;
    sfText *categorie_ct;
    sfVector2f categorie_pos;
    int puissance;
    sfText *puissance_ct;
    sfVector2f puissance_pos;
    int precision;
    sfText *precision_ct;
    sfVector2f precision_pos;
    int pp;
    int current_pp;
    sfText *pp_ct;
    sfVector2f pp_pos;
    char *cible;
} capacity_t;

typedef struct pokemon_s
{
    sfSprite *pkmn;
    sfSprite *pkmn_battle;
    sfIntRect rect_pkmn;
    sfIntRect rect_pkmn_battle;
    sfVector2f pos_pkmn;
    sfVector2f pos_pkmn_battle;
    sfText *name_pkmn;
    sfVector2f name_pos;
    sfText *level_pkmn;
    sfVector2f level_pos;
    sfText *id_pkmn;
    sfVector2f id_pos;
    sfText *pv_pkmn;
    sfVector2f pv_pos;
    sfText *attack_pkmn;
    sfVector2f attack_pos;
    sfText *defense_pkmn;
    sfVector2f defense_pos;
    sfText *speed_pkmn;
    sfVector2f speed_pos;
    sfText *type1_pkmn;
    sfVector2f type1_pos;
    sfText *type2_pkmn;
    sfVector2f type2_pos;
    sfText *type3_pkmn;
    sfVector2f type3_pos;
    sfMusic *sound;
    int id;
    char *name;
    int case_pos_x;
    int case_pos_y;
    int evolve_level;
    int next_id;
    char **type;
    char **capacity;
    char **level_capacity;
    capacity_t **moves;
    int nbmoves;
    int level;
    int pv;
    int current_pv;
    int attaque;
    int defense;
    int vitesse;
} pokemon_t;

typedef struct pkmn_player_s
{
    sfSprite *stats_menu;
    pokemon_t **pokemon;
    int nb_pokemon;
    int display_stats;
    int pkmn_display_stats;
} pkmn_player_t;

typedef struct battle_s
{
    obj_t interface;
    obj_t random_pkmn_obj;
    pokemon_t *random_pkmn;
    obj_t pkmn_obj;
    life_t *pkmn_life;
    life_t *random_pkmn_life;
    sfml_clock_t sound_clk;
    sfml_clock_t plyr_attack_clk;
    sfml_clock_t effect_hit_clk;
    sfml_clock_t rdm_attack_clk;
    sfml_clock_t catch_pkmn_clk;
    sfml_clock_t catch_effect_clk;
    obj_t move_player_txt;
    obj_t move_random_txt;
    obj_t *pkbl;
    obj_t *pkbl_catch;
    sfMusic *battle_wild;
    sfMusic *pkbl_catch_sound;
    sfMusic *catch_sucess;
    sfView *view;
    const sfView *view_origin;
    sfVector2f zoom_xy;
    int stop_sound;
    int choice_player;
    int choice_random;
    int stop;
    int loop_nb;
    float turn;
    int display_pkmn_wild;
    int display_pkmn;
    int i_pkmn;
    int gotcha;
} battle_t;

typedef struct htp_s
{
    char *old_name;
    char *name;
    int state;
    sfText *name_player;
    sfClock *cl_move;
    sfTime time;
    float seconds;
    int size;
    sfSprite *h1_1;
    sfSprite *h1_2;
    sfSprite *h2_1;
    sfSprite *h2_2;
    sfSprite *h2_3;
    sfSprite *h3_1;
    sfSprite *h3_2;
    sfSprite *h4_1;
    sfSprite *h4_2;
    sfSprite *h5_1;
    sfSprite *h5_2;
    sfSprite *h5_3;
    sfSprite *h6_1;
    sfSprite *h6_2;
    sfSprite *h6_3;
    sfSprite *before_playing;
    sfSprite *boy;
    sfSprite *girl;
    sfSprite *select;
} htp_t;

typedef struct file_parameters_s
{
    char **pokemon_params;
    char **capacity_params;
} file_parameters_t;

typedef struct menu_s
{
    sfText *play;
    sfText *quit;
    sfVector2f pos_play;
    sfVector2f pos_quit;
    sfSprite *sp_menu;
    sfMusic *music;
    sfMusic *music_intro;
    htp_t *how_to_play;
} menu_t;

typedef struct item_s
{
    char *nb;
    sfVector2f pos_item;
    sfVector2f pos_nb;
    sfText *tx_name;
    sfText *tx_nb;
} item_t;

typedef struct game_s
{
    sfMusic *music;
    sfSprite* sp_map;
    sfSprite* sp_player;
    int boy_girl;
    sfSprite* sp_bag;
    sfVector2f pos_bag;
    sfSprite* sp_labo;
    sfIntRect rect_player;
    sfVector2f pos_player;
    sfVector2f pos_map;
    sfClock *cl_move;
    sfTime time;
    int disp_bag;
    int disp_pause;
    float seconds;
    int move;
    sfml_clock_t clock_cb;
    item_t *item;
    file_parameters_t *files;
    pkmn_player_t *pkmn_bag;
    pnj_t **pnj;
} game_t;

typedef struct pause_s
{
    sfSprite *sp_menu;
} pause_t;

typedef struct rpg_s
{
    sfRenderWindow *window;
    sfVector2u size_window;
    sfVector2i old_mouse_pos;
    sfVector2i mouse_pos;
    sfEvent event;
    int status;
    int game_state;
    menu_t *menu;
    game_t *game;
    pause_t *pause;
} rpg_t;
