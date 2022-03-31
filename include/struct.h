/*
** EPITECH PROJECT, 2022
** struct.h
** File description:
** Header for 'map' project.
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <SFML/Graphics.h>

/**
 * @brief Main object for the project
 *
 * @param background   Background of the window
 * @param select       Sprite of the select cursor
 * @param filepath     Sprite of the filepath
 * @param filepath_str Filepath of the map file
 */
typedef struct object_s object_t;

struct object_s
{
    sfSprite    *background;
    sfSprite    *select;
    sfText      *filepath;
    char        *filepath_str;
};

#endif
