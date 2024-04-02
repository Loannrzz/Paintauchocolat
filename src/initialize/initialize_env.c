/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/21/24.
** File description:
** initialize_env.c
*/

#include "../../include/my.h"

list_t *create_new_list(void)
{
    printf("je suis dans create_new_list\n");
    list_t *list = malloc(sizeof(*list));

    if (!list)
        my_putstr_error("can't malloc list in create_new_list()");
    list->nb_nodes = 0;
    list->add = add_node;
    list->supp = supp_list;
    list->new = create_node;
    list->premier = NULL;
    list->dernier = NULL;
    printf("je sort de create_new_list\n");
    return list;
}

list_t *initialize_env(char **env)
{
    list_t *list_env = create_new_list();
    char **temp = 0;
    node_t *node = NULL;

    for (int i = 0; env[i]; ++i) {
        temp = malloc(sizeof(char *) * 3);
        temp[0] = my_strccpy(env[i], "=");
        temp[1] = my_strcpy(env[i] + my_strlen(temp[0]) + 1);
        temp[2] = NULL;
        node = list_env->new(temp, 2);
        list_env->add(list_env, node);
    }
    return list_env;
}
