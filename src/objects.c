/*
** EPITECH PROJECT, 2022
** objects.c
** File description:
** Objects handling.
*/

#include "map.h"
#include <string.h>
#include <stdlib.h>

void choose_correct_bg(sfRenderWindow *window, int *offset, object_t *objects)
{
    if (*offset == 0) {
        destroy_sprite(objects->background);
        objects->background = create_map(window, objects->filepath_str);
    } else if (*offset == 1) {
        destroy_sprite(objects->background);
        objects->background = create_sprite(SCENE_1);
    } else if (*offset == 2) {
        destroy_sprite(objects->background);
        objects->background = create_sprite(SCENE_2);
    } else if (*offset == 3) {
        destroy_sprite(objects->background);
        objects->background = create_map(window, objects->filepath_str);
    }
}

void free_objects(object_t *objects)
{
    destroy_sprite(objects->background);
    destroy_sprite(objects->select);
    destroy_text(objects->filepath);
    free(objects->filepath_str);
    free(objects);
}

object_t *create_objects(sfRenderWindow *window, char *filepath)
{
    object_t *objects = malloc(sizeof(object_t));

    objects->background = create_map(window, filepath);
    objects->filepath_str = malloc(sizeof(char) * 100);
    objects->select = create_sprite(SP_SELECT);
    sfSprite_setPosition(objects->select, \
        (sfVector2f){-sfSprite_getTextureRect(objects->select).width, 0});
    memset(objects->filepath_str, 0, 100);
    memcpy(objects->filepath_str, filepath, strlen(filepath));
    objects->filepath = create_text((sfVector2f){0, -100}, \
        sfWhite, sfFont_createFromFile(FONT_ARIAL), objects->filepath_str);
    return objects;
}