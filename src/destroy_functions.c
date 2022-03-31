/*
** EPITECH PROJECT, 2022
** destroy_functions.c
** File description:
** Functions to destroy some variables.
*/

#include <SFML/Graphics.h>

void destroy_text(sfText *text)
{
    if (!text)
        return;
    sfFont_destroy((sfFont *)sfText_getFont(text));
    sfText_destroy(text);
}

void destroy_sprite(sfSprite *sprite)
{
    if (!sprite)
        return;
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(sprite));
    sfSprite_destroy(sprite);
}
