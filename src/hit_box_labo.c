/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** hit_box_labo
*/

#include "rpg.h"
#include "my.h"

int display_houses_or_map(rpg_t *rpg)
{
    float labo_left[4] = {-700.00, -545.00, -1002, -818};
    float labo_right[4] = {-905.00, -771.80, -1002, -818};
    float labo_center[4] = {-742.00, -706.80, -970, -818};
    float labo_widht[4] = {-905.00, -545.80, -970, -818};
    float house_left[4] = {-774.00, -598.00, -1295, -1160};
    float house_middle[4] = {-988.00, -807.00, -1295, -1160};
    float house_right[4] = {-1210.00, -1019.00, -1295, -1100};
    float house_t_right[4] = {-1178, -1012.40, -1000, -818};

    if (check_touch_boxe(labo_left, rpg->game->pos_map) == 1 ||
    check_touch_boxe(labo_right, rpg->game->pos_map) == 1 ||
    check_touch_boxe(labo_center, rpg->game->pos_map) == 1 ||
    check_touch_boxe(labo_widht, rpg->game->pos_map) == 1)
        return 1;
    if (check_touch_boxe(house_left, rpg->game->pos_map) == 1 ||
    check_touch_boxe(house_middle, rpg->game->pos_map) == 1 ||
    check_touch_boxe(house_right, rpg->game->pos_map) == 1 ||
    check_touch_boxe(house_t_right, rpg->game->pos_map) == 1)
        return 1;
    return 0;
}

void market_center_inside(rpg_t *rpg)
{
    float shop_wall_w[4] = {-1044.70, -1040.00, -1004.50, -900};
    float shop_wall_e[4] = {-1142.90, -1138.90, -1004.50, -900};
    float shop_wall_n[4] = {-1171.70, -1000.40, -923.80, -814};
    float shop_wall_s[4] = {-1171.70, -1078.80, -1000, -985.51};
    float house_middle_wall_w[4] = {-843.60, -830.60, -1286.11, -1190};
    float house_middle_wall_e[4] = {-966.80, -948, -1286.11, -1190};
    float house_middle_wall_n[4] = {-969.00, -819.00, -1254.90, -1200};
    float house_middle_wall_s[4] = {-960.00, -880.00, -1280.11, -1274};

    my_hiy_box(rpg, house_middle_wall_w);
    my_hiy_box(rpg, house_middle_wall_e);
    my_hiy_box(rpg, house_middle_wall_n);
    my_hiy_box(rpg, house_middle_wall_s);
    my_hiy_box(rpg, shop_wall_w);
    my_hiy_box(rpg, shop_wall_e);
    my_hiy_box(rpg, shop_wall_n);
    my_hiy_box(rpg, shop_wall_s);
}

void last_box(rpg_t *rpg)
{
    float house_right_bed[4] = {-1181.00, -1130.60, -1237.30, -1150};
    float house_left_bed[4] = {-761.00, -710.60, -1237.30, -1150};
    float shop_box[4] = {-1160.00, -1129.20, -1004.11, -944};
    float shop_money[4] = {-1090.80, -1024.00, -962.31, -900};

    my_hiy_box(rpg, shop_box);
    my_hiy_box(rpg, shop_money);
    my_hiy_box(rpg, house_left_bed);
    my_hiy_box(rpg, house_right_bed);
}

void houses_box_inside(rpg_t *rpg)
{
    float house_left_wall_w[4] = {-632.60, -630.00, -1286.11, -1190};
    float house_left_wall_e[4] = {-758.00, -735.80, -1286.11, -1190};
    float house_left_wall_n[4] = {-744.00, -610.00, -1214.20, -1200};
    float house_left_wall_s[4] = {-750.00, -671.00, -1280.11, -1270};
    float house_right_wall_w[4] = {-1050.60, -1040.00, -1286.11, -1190};
    float house_right_wall_e[4] = {-1178.00, -1155.80, -1286.11, -1190};
    float house_right_wall_n[4] = {-1164.00, -1030.00, -1214.20, -1200};
    float house_right_wall_s[4] = {-1170.00, -1091.00, -1280.11, -1270};

    my_hiy_box(rpg, house_left_wall_w);
    my_hiy_box(rpg, house_left_wall_e);
    my_hiy_box(rpg, house_left_wall_n);
    my_hiy_box(rpg, house_left_wall_s);
    my_hiy_box(rpg, house_right_wall_w);
    my_hiy_box(rpg, house_right_wall_e);
    my_hiy_box(rpg, house_right_wall_n);
    my_hiy_box(rpg, house_right_wall_s);
    last_box(rpg);
}

void labo_inside_box(rpg_t *rpg)
{
    float labo_computer[4] = {-609.70, -579.00, -932.50, -899};
    float labo_left_right_door[4] = {-710.90, -642.90, -1004.11, -986.00};
    float labo_left_left_door[4] = {-579.70, -542.40, -1004.11, -814};
    float labo_right[4] = {-910.00, -871.20, -1004.11, -814};
    float labo_furniture_b[4] = {-910.00, -750.00, -1004.11, -946};
    float labo_furniture_top[4] = {-910.00, -808.00, -912.60, -880};
    float labo_middle[4] = {-910.00, -675.80, -1004.11, -961};
    float labo_top[4] = {-910.00, -579.80, -900, -880};

    my_hiy_box(rpg, labo_computer);
    my_hiy_box(rpg, labo_left_left_door);
    my_hiy_box(rpg, labo_left_right_door);
    my_hiy_box(rpg, labo_right);
    my_hiy_box(rpg, labo_middle);
    my_hiy_box(rpg, labo_furniture_b);
    my_hiy_box(rpg, labo_furniture_top);
    my_hiy_box(rpg, labo_top);
}