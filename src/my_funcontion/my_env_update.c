/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/27/24.
** File description:
** my_env_update.c
*/

#include "../../include/my.h"

void reset_env(myshell_t *my_shell)
{
    if (my_shell->path != NULL)
        free(my_shell->path);
    if (my_shell->home != NULL)
        free(my_shell->home);
    if (my_shell->oldpwd != NULL)
        free(my_shell->oldpwd);
    if (my_shell->env != NULL) {
        for (int i = 0; my_shell->env[i]; ++i)
            free(my_shell->env[i]);
        free(my_shell->env);
    }
}

void update_env(myshell_t *my_shell, char *name, char *value)
{
    size_t i = 0;
    node_t *node = my_shell->list_env->premier;

    reset_env(my_shell);
    my_shell->env = malloc(sizeof(node_t) * (my_shell->list_env->nb_nodes + 1));
    my_shell->env[my_shell->list_env->nb_nodes] = NULL;
    for (int i = 0; node; ++i) {
        if (my_strcmp(node->text[0], "PATH") == 0)
            my_shell->path = my_str_to_word_array(node->text[1], ":", &i);
        if (my_strcmp(node->text[0], "HOME") == 0)
            my_shell->home = my_strcpy(node->text[1]);
        if (my_strcmp(node->text[0], "OLDPWD") == 0)
            my_shell->oldpwd = my_strcpy(node->text[1]);
        my_shell->env[i] = my_strcat(node->text[0], "=");
        my_shell->env[i] = my_strcat(my_shell->env[i], node->text[1]);
        node = node->next;
    }
}