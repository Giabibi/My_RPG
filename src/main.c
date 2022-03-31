/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** The main function of the project.
*/

#include "map.h"

int main(int argc, const char * const *argv, const char * const *env)
{
    if (is_error(argc, argv, env))
        return 84;
    return map((char *)argv[1]);
}