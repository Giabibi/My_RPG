/*
** EPITECH PROJECT, 2022
** map.h
** File description:
** Header for 'map' project.
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "macro.h"
    #include "struct.h"
    #include <stdbool.h>

/**
 * @brief Load a map from file
 *
 * @param filepath Path of the file to load
 * @return int
 */
int map(char *filepath);

/**
 * @brief Check for an error
 *
 * @param argc Number of arguments given
 * @param argv Arguments given
 * @param env All environments variables
 * @return true or false
 */
bool is_error(int argc, const char * const *argv, const char *const *env);

/**
 * @brief Free an array of array
 *
 * @param array Array to free
 */
void free_2d_array(void **array);

/**
 * @brief Load a array in 2 dimensions from file
 *
 * @param filepath Path of the file to load
 * @param rows Number of rows in file to load
 * @param cols Number of columns in file to load
 * @return int**
 */
int **load_map_from_file(char const *filepath, int rows, int cols);

/**
 * @brief Write a character (new_char) at the position (x, y) in the file (filepath)
 *
 * @param x Position horizontal
 * @param y Position vertical
 * @param filepath Path of the file
 * @param new_char Character to write
 */
void write_in_file(int x, int y, char *filepath, char new_char);

/**
 * @brief Handle events from user inputs
 *
 * @param window Main window of the project
 * @param event Event to handle
 * @param objects Objects useful to handle
 */
void event_handling(sfRenderWindow *window, sfEvent event, object_t *objects);

/**
 * @brief Create a map object
 *
 * @param window Main window of the project
 * @param filepath Path of the file to load
 * @return sfSprite*
 */
sfSprite *create_map(sfRenderWindow *window, const char *filepath);

/**
 * @brief Create a sprite object
 *
 * @param filepath Path of the image to load
 * @return sfSprite*
 */
sfSprite *create_sprite(char *filepath);

/**
 * @brief Create a text object
 *
 * @param pos Position to draw text
 * @param color Color of the text
 * @param font Font of the text
 * @param content Content of the text
 * @return sfText*
 */
sfText *create_text(sfVector2f pos, sfColor color, sfFont *font, char *content);

/**
 * @brief Create a window object
 *
 * @param width Width of the window
 * @param height Height of the window
 * @param name Name of the window
 * @return sfRenderWindow*
 */
sfRenderWindow *create_window(int width, int height, char *name);

/**
 * @brief Destroy sprite
 *
 * @param sprite Sprite to destroy
 */
void destroy_sprite(sfSprite *sprite);

/**
 * @brief Destroy text
 *
 * @param text Text to destroy
 */
void destroy_text(sfText *text);

/**
 * @brief Change background according to the offset
 *
 * @param window Main window of the project
 * @param offset Index of the scene
 * @param objects Main objects
 */
void choose_correct_bg(sfRenderWindow *window, int *offset, object_t *objects);

/**
 * @brief Free main objects
 *
 * @param objects Objects to free
 */
void free_objects(object_t *objects);

/**
 * @brief Create a objects object
 *
 * @param window Main window of the project
 * @param filepath Filepath of the map
 * @return object_t*
 */
object_t *create_objects(sfRenderWindow *window, char *filepath);

#endif
