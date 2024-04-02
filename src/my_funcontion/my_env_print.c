/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 2/29/24.
** File description:
** my_env.c
*/

#include "../../include/my.h"

void my_env_to(myshell_t *my_shell)
{
    int i = 0;

    while (my_shell->env[i] != NULL) {
        my_putstr(my_shell->env[i]);
        my_putstr("\n");
        i++;
    }
}
