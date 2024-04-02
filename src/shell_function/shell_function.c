/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** shell_function.c
*/

#include "my.h"

list_t *initialize2(char **environnement)
{
    list_t *list = new_liked_list();
    char **text = 0;
    node_t *node = NULL;
    int f = 0;

    if (environnement[f] == NULL)
        return list;
    for (int i = 0; environnement[i]; ++i) {
        text = malloc(sizeof(char **) * 3);
        text[0] = my_strccpy(environnement[i], "=");
        text[1] = my_strcpy(environnement[i] + my_strlen(text[0]) + 1);
        text[2] = NULL;
        node = list->new (text, 2);
        list->add(list, node);
    }
    return list;
}

mysh_t initialize(char **environnement)
{
    mysh_t mysh = {
        .list_env = initialize2(environnement),
        .exit = false
    };

    up_env(&mysh);
    return mysh;
}
