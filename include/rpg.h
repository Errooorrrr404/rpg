/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_
#include "struct.h"

float *to_float_array(float nb1, float nb2, float nb3, float nb4);

//create_menu.c
int create_menu(menu_t *menu);

//create.c
int create_window(rpg_t *rpg);

//display.c
void set_element_bag(pkmn_player_t *pkmn_bag, int pos[2], int i);
void get_time(game_t *game);
void display_bag(rpg_t *rpg);
void display_all(rpg_t *rpg);
void houses_box_inside(rpg_t *rpg);
void market_center_inside(rpg_t *rpg);

//event.c
void event_menu(rpg_t *rpg);
void event_game(rpg_t *rpg);
void event(rpg_t *rpg);

//free.c
void free_menu(menu_t *menu);
void free_item(item_t *item);
void free_game(game_t *game);
void free_rpg(rpg_t *rpg);

//get_time.c
void get_time(game_t *game);
void get_time_custom(sfml_clock_t *clock_st);
void get_time_game_loop(game_t *game, sfml_clock_t *clock_st);

//game_rpg.c
void game_rpg(rpg_t *rpg);

// how_to_play.c
void put_player_name(rpg_t *rpg, int size);
void state_is_five(rpg_t *rpg, int next[4], int previous[4]);
void state_is_four(rpg_t *rpg, int next[4], int previous[4]);
void state_is_three(rpg_t *rpg, int next[4]);
void state_is_two(rpg_t *rpg, int next[4]);
void state_is_one(rpg_t *rpg, int next[4], int previous[4]);
void state_is_zero(rpg_t *rpg, int next[4]);
void state_is_neg(rpg_t *rpg, int left[4], int right[4]);
void disp_how_to_play(rpg_t *rpg);

//init_game.c
item_t create_item(char *name, char *nb, sfVector2f pos_item,
sfVector2f pos_nb);
void init_item(game_t *game);
void init_position_game(game_t *game);
void init_assets_game(game_t *game);
int create_game(game_t *game);

//init_hit_box.c
void labo_inside_box(rpg_t *rpg);
int check_touch_boxe_2(int *size, sfVector2i player);
void houses_box(rpg_t *rpg);
void lake_river_box(rpg_t *rpg);
void forest_wood_box(rpg_t *rpg);
void mountain_map_box(rpg_t *rpg);
void init_hit_box(rpg_t *rpg);
void my_hiy_box_2(rpg_t *rpg, float *square);

//hit_box_labo.c
int display_houses_or_map(rpg_t *rpg);

//init.c
int init_struct(rpg_t *rpg);
sfSprite *init_sprite(char *filepath, sfVector2f vector);
sfSprite *init_sprite2(char *filepath);
void resize_mouse(rpg_t *rpg);

//main.c
int main(int ac, __attribute__((unused)) char **argv);

//check.c
int define_pkmn_id_next(char *level, char **pkmn_p, int line, pokemon_t *pkmn);
int add_basic_parameter(char *str, pokemon_t *pkmn, char **pkmn_p, int line);
void display_pokemon_menu(pkmn_player_t *pkmn_bag, rpg_t *rpg, int i, int *pos);
void exec_stat_two(rpg_t *rpg, sfVector2f pos, sfFont *font);
void destroy_text_display_stats(pkmn_player_t *pkmn_bag, int i);

//menu_rpg.c
void menu_rpg(rpg_t *rpg);
void menu_pause(rpg_t *rpg);

//move_map.c
void move_map_up_down(rpg_t *rpg);
void move_map_left_right(rpg_t *rpg);
void move_map(rpg_t *rpg);
void move_player(rpg_t *rpg);
void move_map_player(rpg_t *rpg);

//my_hit_box.c
void change_1(rpg_t *rpg, float *square, float m_height, float m_widht);
void change_move_person(rpg_t *rpg, float *square, int move);
int check_touch_boxe(float *size, sfVector2f player);
void my_hiy_box(rpg_t *rpg, float *square);

//rpg.c
int rpg(void);

//add_pkmn.c
pokemon_t *add_pkmn(char *id, char *level, file_parameters_t *files);

//random.c
int random_value(int lower, int upper, int max, int *alea);
int *binare_tab(int lower, int upper, int max);
void resize_mouse2(rpg_t *rpg);

//file_to_tab.c
char **file_to_tab(char *path);

//catch_str.c
char *catch_str(int i, char symbol, char *origin, char symbol2);
int catch_str_int(int i, char symbol, char *origin, char symbol2);

//csfml_tools.c
sfSprite* image2sprite(char *path);
sfText* int2text(char *font_path, int nb, int size);
sfText* string2text(char *font_path, char *str, int size);
sfVector2f set_position_csfml(int x, int y);

//define_basic_value.c
int add_basic_parameters(pokemon_t *pokemon, int line,
char **pokemon_params, int id_pkmn);
int move_by_level(int i, char **pokemon_params, pokemon_t *pokemon);
int define_basic_stats_pkmn(int , char *, char **, pokemon_t *);
int add_sprite_pkmn(pokemon_t *pokemon);

//add_default_capacity_pkmn.c
int add_default_capacity(pokemon_t *pokemon, file_parameters_t *files);

//display_stats.c
void display_stats(rpg_t *rpg);

// csfml_tools.c
sfText* int2text(char *font_path, int nb, int size);
sfVector2f set_position_csfml_float(float x, float y);

//define_color_type.c
void color_by_type_pkmn(pokemon_t *pokemon);
void switch_color_pkmn(int i, sfText *type_pkmn);
void switch_color_pkmn2(int i, sfText *type_pkmn, sfColor *color);
sfColor *define_color_type(void);
sfColor create_sfcolor_tab(int a, int r, int g, int b);

//get_position_from_window.c
void get_position_from_window(sfSprite *sprite, sfVector2f position,
sfRenderWindow *window);

//manage_pnj.c
pnj_t **manage_pnj(void);

//concat_all_stat_value.c
void concat_all_stat_value(pkmn_player_t *pkmn_bag, int i);
sfText *concat_stat_value(char *stat, int value, int size);

//my_malloc.c
void *my_malloc(size_t size);

//pkmn_battle_random.c
void pkmn_battle_random(rpg_t *rpg);
void choose_random_pkmn_battle(battle_t *battle, rpg_t *rpg);
void define_scale_pos_battle(battle_t *battle, pokemon_t **pokemon);

//manage_pnj.c
pnj_t **manage_pnj(void);

//get_info.c
int get_information_stats_capacity(int i, capacity_t *capacity,
file_parameters_t *files, int id);

//pkmn_battle_random_misc.c
void set_position_draw_moves_loop(pokemon_t **pokemon,
rpg_t *rpg, battle_t *battle);
void define_color_moves_battle(capacity_t **moves, int nbmoves);
void create_life(life_t *life, pokemon_t *pokemon, int pos_x, int pos_y);
void manage_life(sfRenderWindow*, life_t *, float, float);
int event_battle(rpg_t *rpg, battle_t *battle, pokemon_t **pokemon);

//choose_capacity_battle.c
int choose_capacity_battle(rpg_t *rpg, battle_t *battle);
void battle_player_turn(battle_t *battle, pokemon_t **pokemon, rpg_t *rpg);
void battle_random_turn(battle_t *battle, pokemon_t **pokemon);
void mouse_released(battle_t *battle, rpg_t *rpg);

//add_pkmn_sound.c
int add_pkmn_sound(pokemon_t *pokemon);

//define_battle_struct.c
void define_battle_struct(battle_t *battle, rpg_t *rpg, pokemon_t **pokemon);
sfText *sfText_move_animation(char *name, char *ct, int ennemi);

//cinematic_battle_wild.c
void cinematic_pkmn_player(battle_t *battle, pokemon_t **pokemon);
void cinematic_pkmn_random(battle_t *battle, pokemon_t **pokemon);
void turn_management(battle_t *battle, pokemon_t **pokemon, rpg_t *rpg);

//free_battle_wild_random.c
void free_battle_wild_random(battle_t *battle, rpg_t *rpg);

//free_pkmn_struct.c
void free_pkmn_struct(pokemon_t *pokemon);
void free_capacity_struct(capacity_t **moves, int nbmoves);

//set_pos_sprite_battle.c
void set_pos_sprite_battle(battle_t *battle, pokemon_t **pokemon);

//catch_pkmn.c
void define_pkmn_catch(battle_t *battle, pokemon_t **pokemon);
void cinematic_pkmn_catch(rpg_t *rpg, battle_t *battle, pokemon_t **pokemon);

#endif
