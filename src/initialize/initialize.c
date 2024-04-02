/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/21/24.
** File description:
** initialize.c
*/

#include "../../include/my.h"

myshell_t initialize(char **env)
{
    printf("je suis dans initialize\n");
    myshell_t myshell = {
        .list_env = initialize_env(env),
        .exit = false,
    };
    printf("je vais sortir d'initialize env\n");
    up_env(&myshell);
    return myshell;
}
