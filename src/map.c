/*
** EPITECH PROJECT, 2022
** map.c
** File description:
** Map function to create map
*/

#include "map.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int map(char *filepath)
{
    sfEvent event;
    sfRenderWindow *window = create_window(WIN_WIDTH, WIN_HEIGHT, "Workshop");
    object_t *objects = create_objects(window, filepath);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, objects->background, NULL);     // === EX 01 ===
        // sfRenderWindow_drawText(window, objects->filepath, NULL);         // === EX 02 ===
        // sfRenderWindow_drawSprite(window, objects->select, NULL);         // === EX 03 ===
        sfRenderWindow_display(window);
        event_handling(window, event, objects);
    }
    free_objects(objects);
    sfRenderWindow_destroy(window);
    return 0;
}