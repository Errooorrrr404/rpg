/*
** EPITECH PROJECT, 2018
** HUB
** File description:
** get_strarg_float.c
*/

#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

int detect_getfloat(char *strarg, int dot)
{
    int nbdec = 0;

    while (strarg[dot] != '#') {
        dot++;
        nbdec++;
    }
    return (nbdec);
}

float convert2float(char *strarg, int position, int sav_i)
{
    int nb = 0;
    int dec1 = 0;
    float dec2 = 0;
    int dot = 0;
    int nbdec = 0;

    sav_i--;
    while (strarg[sav_i] != '#') {
        if (strarg[sav_i] == '.') {
            strarg[sav_i] = '#';
            dot = sav_i;
        }
        sav_i--;
    }
    nb = get_strarg_int(strarg, position);
    dec1 = get_strarg_int(strarg, position + 1);
    dot++;
    nbdec = detect_getfloat(strarg, dot);
    dec2 = dec1 * f_puiss_float(10, -nbdec);
    return (nb + dec2);
}

float to_beginning_float(char *strarg, int sav_i)
{
    int nb = 0;
    int dec1 = 0;
    float dec2 = 0;
    int dot = 0;
    int nbdec = 0;

    while (sav_i != 0) {
        if (strarg[sav_i] == '.') {
            strarg[sav_i] = '#';
            dot = sav_i;
        }
        sav_i--;
    }
    nb = get_strarg_int(strarg, 1);
    dec1 = get_strarg_int(strarg, 2);
    dot++;
    nbdec = detect_getfloat(strarg, dot);
    dec2 = dec1 * f_puiss_float(10, -nbdec);
    return (nb + dec2);
}

float get_strarg_float(char *strarg, int position)
{
    int i = 0;
    int sav_i = 0;
    int nbarg = 0;

    while (strarg[i] != '\0' && nbarg != position) {
        if (strarg[i] == '#') {
            nbarg++;
            sav_i = i;
        }
        i++;
    }
    if (position < 2)
        return (to_beginning_float(strarg, sav_i));
    else if (position >= 2)
        return (convert2float(strarg, position, sav_i));
    return (0.0);
}
