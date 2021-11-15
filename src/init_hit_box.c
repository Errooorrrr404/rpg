/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_hit_box
*/

#include "rpg.h"
#include "my.h"

void houses_box(rpg_t *rpg)
{
    float house_left_left_door[4] = {-776.40, -672, -1297.80, -1110.00};
    float house_left_right_door[4] = {-650, -596.40, -1297.80, -1110.00};
    float house_left[4] = {-776.40, -596.40, -1290, -1110.00};
    float house_middle_left_door[4] = {-990.00, -879.60, -1297.80, -1110.00};
    float house_middle_right_door[4] = {-855.60, -805.20, -1297.80, -1110.00};
    float house_middle[4] = {-990.00, -805.20, -1290, -1110.00};
    float house_right_left_door[4] = {-1215.80, -1090, -1297.80, -1110.00};
    float house_right_right_door[4] = {-1065.20, -1016.40, -1297.80, -1110.00};

    my_hiy_box(rpg, house_left_left_door);
    my_hiy_box(rpg, house_left_right_door);
    my_hiy_box(rpg, house_middle_left_door);
    my_hiy_box(rpg, house_middle_right_door);
    my_hiy_box(rpg, house_right_left_door);
    my_hiy_box(rpg, house_right_right_door);
    my_hiy_box(rpg, house_left);
    my_hiy_box(rpg, house_middle);
}

void lake_river_box(rpg_t *rpg)
{
    float lake_b_left[4] = {-953, -471.80, -726, -576.41};
    float lake_m_left[4] = {-953, -699.80, -577.41, -407.01};
    float lake_t_right[4] = {-948.21, -539, -473.01, -289.31};
    float lake_m_right[4] = {-1113.40, -948, -407.01, -289.31};
    float river_1[4] = {-1725.58, -1267.20, -1326.40, -1030};
    float river_2[4] = {-1791.58, -1431.60, -698.61, 0};
    float river_3[4] = {-2427.55, -1725.50, -949.40, -615.01};
    float river_4[4] = {-3000, -2486.35, -949.40, -553.41};
    float river_5[4] = {-1726.78, -300, -2000, -1385.08};

    my_hiy_box(rpg, lake_b_left);
    my_hiy_box(rpg, lake_m_left);
    my_hiy_box(rpg, lake_t_right);
    my_hiy_box(rpg, lake_m_right);
    my_hiy_box(rpg, river_1);
    my_hiy_box(rpg, river_2);
    my_hiy_box(rpg, river_3);
    my_hiy_box(rpg, river_4);
    my_hiy_box(rpg, river_5);
}

void houses_2_box(rpg_t *rpg)
{
    float house_right[4] = {-1215.80, -1016.40, -1290, -1110.00};
    float labo_top[4] = {-910.00, -542.40, -850.00, -814};
    float labo_left_right_door[4] = {-706.90, -628.90, -1004.11, -814};
    float labo_left_left_door[4] = {-579.70, -542.40, -1004.11, -814};
    float labo_right[4] = {-911.00, -741.80, -1004.11, -814};
    float labo_center[4] = {-741.60, -706.80, -978.80, -814};
    float house_t_right[4] = {-1181, -1008.40, -990, -814};
    float house_t_right_door[4] = {-1181, -1090, -1004.11, -814};
    float house_t_right_left_door[4] = {-1060, -1008.40, -1004.11, -814};

    my_hiy_box(rpg, house_t_right);
    my_hiy_box(rpg, house_t_right_door);
    my_hiy_box(rpg, house_t_right_left_door);
    my_hiy_box(rpg, house_right);
    my_hiy_box(rpg, labo_top);
    my_hiy_box(rpg, labo_left_left_door);
    my_hiy_box(rpg, labo_left_right_door);
    my_hiy_box(rpg, labo_right);
    my_hiy_box(rpg, labo_center);
}

void mountain_map_box(rpg_t *rpg)
{

    float mountain_1[4] = {-3000, -2705.94, -560.80, -170};
    float mountain_2[4] = {-2708.34, -1790.54, -217.91, -170};
    float border_map_north[4] =  {-1570, -300, -167.50, 0};
    float border_map_west[4] = {-410.40, 0, -1160, -150};
    float border_map_south_west[4] = {-475.20, -300, -1336.68, -1133.19};
    float border_map_south[4] = {-381.60, 0, -1386, -1336};

    my_hiy_box(rpg, mountain_1);
    my_hiy_box(rpg, mountain_2);
    my_hiy_box(rpg, border_map_north);
    my_hiy_box(rpg, border_map_west);
    my_hiy_box(rpg, border_map_south_west);
    my_hiy_box(rpg, border_map_south);
}

void init_hit_box(rpg_t *rpg)
{
    float wood_1[4] = {-1432, -1233.61, -810, -587.70};
    float wood_2[4] = {-1300.20, -1186.80, -1033.30, -807.80};
    float forest_1[4] = {-2643.54, -1720, -2000, -1436.78};
    float forest_2[4] = {-3000, -2637.54, -1437.78, -949};

    my_hiy_box(rpg, wood_1);
    my_hiy_box(rpg, wood_2);
    my_hiy_box(rpg, forest_1);
    my_hiy_box(rpg, forest_2);
    houses_box(rpg);
    houses_2_box(rpg);
    lake_river_box(rpg);
    mountain_map_box(rpg);
}