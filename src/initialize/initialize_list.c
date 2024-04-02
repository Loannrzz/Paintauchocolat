/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/21/24.
** File description:
** initialize_list.c
*/

#include "../../include/my.h"

node_t *create_node(char **data, int size)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        my_putstr_error("can't malloc node in create_node()");
    node->text = data;
    node->len = size;
    node->prev = NULL;
    node->next = NULL;
    node->str = NULL;
    return node;
}

void supp_list(list_t *list, node_t *node)
{
    node_t *next = NULL;

    while (node) {
        next = node->next;
        for (int i = 0; node->text[i]; ++i)
            free(node->text[i]);
        free(node->text);
        free(node);
        node = next;
    }
    free(list);
}

void add_node(list_t *list, node_t *node)
{
    if (!list || !node)
        return;
    if (list->nb_nodes == 0) {
        list->premier = node;
        list->dernier = node;
    } else {
        list->dernier->next = node;
        node->prev = list->dernier;
        list->dernier = node;
    }
    ++list->nb_nodes;
}

list_t *new_list(void)
{
    list_t *list = malloc(sizeof(*list));

    if (!list)
        my_putstr_error("can't malloc list in new_list()");
    list->nb_nodes = 0;
    list->add = add_node;
    list->supp = supp_list;
    list->new = create_node;
    list->premier = NULL;
    list->dernier = NULL;
    return list;
}
