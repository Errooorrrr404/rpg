/*
** EPITECH PROJECT, 2019
** ALEXIS DESRUMAUX
** File description:
** file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Font.h>
#include "my.h"
#include "rpg.h"

sfVector2f set_position_csfml_float(float x, float y)
{
    sfVector2f position;

    position.x = x;
    position.y = y;
    return (position);
}

sfVector2f set_position_csfml(int x, int y)
{
    sfVector2f position;

    position.x = x;
    position.y = y;
    return (position);
}

sfSprite* image2sprite(char *path)
{
    sfSprite* sprite;
    sfTexture* texture;

    texture = sfTexture_createFromFile(path, NULL);
    sprite = sfSprite_create();
    if (!sprite || !texture)
        return NULL;
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

sfText* string2text(char *font_path, char *str, int size)
{
    sfText* text = sfText_create();
    sfFont* font = sfFont_createFromFile(font_path);

    if (!text || !font)
        return NULL;
    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, size);
    return (text);
}

sfText* int2text(char *font_path, int nb, int size)
{
    sfText* text = sfText_create();
    sfFont* font = sfFont_createFromFile(font_path);
    char *str = malloc(sizeof(char) * 20);

    str = int2char(str, nb);
    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, size);
    free(str);
    return (text);
}