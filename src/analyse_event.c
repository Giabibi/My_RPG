/*
** EPITECH PROJECT, 2022
** analyse_event.c
** File description:
** Analyse events from user.
*/

#include "map.h"
#include <stdio.h>
#include <string.h>

static void analyse_event_edit(sfRenderWindow *window, sfEvent event, object_t *objects, int *offset)
{
    sfVector2f pos_select = sfSprite_getPosition(objects->select);

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        /*                               EXERCISE 03                                      */
        /*                        Code to edit the file (.txt)                            */
        /*    You need to let the player choose the block he want to change on the map    */
        /*        you've got a sprite with a white frame that can surround a block        */
        /*      with the directional key the player can move the frame around the map     */
        /* Do a case to validate the changes occurred by the player when enter is pressed */
        /*             Do a case to change the texture of the current block               */
        /*      quick reminder a block is a char that is stocked in your file (.txt)      */

        /* CHECK THIS : sfSprite_setPosition                                              */
        /* CHECK THIS : write_in_file                                                     */
        /* CHECK THIS : choose_correct_bg                                                 */
    }
}

static void analyse_event_new(sfRenderWindow *window, sfEvent event, object_t *objects, int *offset)
{
    FILE *ptr = NULL;
    int i = 0;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        /*                           EXERCISE 02                             */
        /*                    Code to edit the filepath                      */
        /* You need to add at the end of the filepath the character entered  */
        /*    If the user press the delete key, remove the last character    */
        /*      When the user press enter check if the filepath is valid     */
        /*              Edit the offset to change the scene                  */

        /* CHECK THIS : fopen                                                */
        /* CHECK THIS : fclose                                               */
        /* CHECK THIS : choose_correct_bg                                    */
        /* CHECK THIS : sfText_setString                                     */
    }
}

static void analyse_event_choose(sfRenderWindow *window, sfEvent event, object_t *objects, int *offset)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            *offset = IDX_MAP;
            choose_correct_bg(window, offset, objects);
        } else if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft && sfMouse_getPositionRenderWindow(window).y < WIN_HEIGHT / 2) {
            *offset = IDX_NEW_FILEPATH;
            choose_correct_bg(window, offset, objects);
            sfText_setPosition(objects->filepath, (sfVector2f){15, WIN_HEIGHT / 2});
        }// else if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {    // === EX 03 ===
        //    *offset = IDX_EDIT_FILE;
        //    choose_correct_bg(window, offset, objects);
        //    sfSprite_setPosition(objects->select, (sfVector2f){0, 0});
        //}
    }
}

static void analyse_event_map(sfRenderWindow *window, sfEvent event, object_t *objects, int *offset)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        //if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {     // === EX 02 ===
        //    *offset = IDX_CHOOSE;
        //    choose_correct_bg(window, offset, objects);
        //}
    }
}

void analyse_event(sfRenderWindow *window, sfEvent event, object_t *objects)
{
    static int offset = IDX_MAP;

    if (offset == IDX_MAP)
        analyse_event_map(window, event, objects, &offset);
    //else if (offset == IDX_CHOOSE)                                // === EX 02 ===
    //    analyse_event_choose(window, event, objects, &offset);    // === EX 02 ===
    //else if (offset == IDX_NEW_FILEPATH)                          // === EX 02 ===
    //    analyse_event_new(window, event, objects, &offset);       // === EX 02 ===
    //else if (offset == IDX_EDIT_FILE)                             // === EX 03 ===
    //    analyse_event_edit(window, event, objects, &offset);      // === EX 03 ===
}