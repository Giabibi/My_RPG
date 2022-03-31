/*
** EPITECH PROJECT, 2022
** create_functions.c
** File description:
** Functions to create some utils variables.
*/

#include "map.h"
#include <stdlib.h>

static sfSprite **create_tileset()
{
    sfSprite **tileset = malloc(sizeof(sfSprite *) * 4);

    tileset[0] = create_sprite("res/tileset/grass.jpeg");
    tileset[1] = create_sprite("res/tileset/forest.jpeg");
    tileset[2] = create_sprite("res/tileset/water.jpeg");
    tileset[3] = NULL;
    return tileset;
}

sfSprite *create_sprite(char *filepath)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, sfTexture_createFromFile(filepath, NULL), true);
    return sprite;
}

sfText *create_text(sfVector2f pos, sfColor color, sfFont *font, char *content)
{
    sfText *text_display = sfText_create();

    sfText_setPosition(text_display, pos);
    sfText_setColor(text_display, color);
    sfText_setFont(text_display, font);
    sfText_setString(text_display, content);
    return text_display;
}

sfRenderWindow *create_window(int width, int height, char *name)
{
    return sfRenderWindow_create((sfVideoMode){width, height, 32}, name, sfClose, NULL);
}

sfSprite *create_map(sfRenderWindow *window, const char *filepath)
{
    // Initialization of all usefull variables
    int **map = load_map_from_file(filepath, FILE_WIDTH, FILE_HEIGHT);
    sfSprite **tileset = create_tileset();
    sfSprite *background = sfSprite_create();


    /*                          EXERCISE 01                             */
    /*              Code to create background's sprite                  */
    /* Your objective here is to draw all the tileset to the good place */
    /*       You need to do a save of the texture and return it         */

    /* CHECK THIS : sfSprite_setPosition                                */
    /* CHECK THIS : sfRenderWindow_draw_Sprite                          */
    /* CHECK THIS : sfTexture_updateFromRenderWindow                    */
    /* CHECK THIS : sfSprite_setTexture                                 */


    // All functions to free
    free_2d_array((void**)map);
    for (size_t i = 0; tileset[i]; ++i)
        destroy_sprite(tileset[i]);
    free(tileset);

    // Return the background's sprite
    return background;
}