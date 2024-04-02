/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/21/24.
** File description:
** initialize_up_env.c
*/

#include "../../include/my.h"

char *join_string(char *str1, char *str2)
{
    printf("join_string\n");
    char *result =
        malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    int i = 0;

    if (!result)
        my_putstr_error("can't malloc result in join_string()");
    for (; str1[i]; ++i)
        result[i] = str1[i];
    for (int j = 0; str2[j]; ++j)
        result[i++] = str2[j];
    result[i] = '\0';
    printf("join_string end\n");
    return result;
}

void handle_node_text(myshell_t *myshell, char *text0, char *text1, size_t *k)
{
    printf("handle_node_text\n");
    if (my_strcmp(text0, "HOME") == 0)
        myshell->home = my_strcpy(text1);
    if (my_strcmp(text0, "OLDPWD") == 0)
        myshell->oldpwd = my_strcpy(text1);
    if (my_strcmp(text0, "PATH") == 0)
        myshell->path = my_str_to_word_array(text1, ":", k);
    printf("handle_node_text end\n");
}

void up_env(myshell_t *myshell)
{
    node_t *node = myshell->list_env->premier;
    size_t k = 0;

    printf("up_env\n");
    myshell->env = malloc(sizeof(node_t) * (myshell->list_env->nb_nodes + 1));
    myshell->env[myshell->list_env->nb_nodes] = NULL;
    for (int i = 0; node; ++i) {
        if (node->text[0] && node->text[1]) {
            handle_node_text(myshell, node->text[0], node->text[1], &k);
            myshell->env[i] = join_string(node->text[0], node->text[1]);
        }
        node = node->next;
    }
    printf("up_env end : %d\n", myshell->list_env->nb_nodes);
}
