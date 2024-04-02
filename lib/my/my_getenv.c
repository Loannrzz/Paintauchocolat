/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 2/12/24.
** File description:
** my_getenv.c
*/

#include "../../include/my.h"

char *my_getenv(const char *name, char **env)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(name, env[i], my_strlen(name))
                    == 0 && env[i][my_strlen(name)] == '=')
            return &env[i][my_strlen(name) + 1];
    }
    my_putstr_error("Environment variable not found\n");
    return NULL;
}
