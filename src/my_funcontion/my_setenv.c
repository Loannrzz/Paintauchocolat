///*
//** EPITECH PROJECT, 2024
//** Created by loann.picard-blardone@epitech.eu on 2/29/24.
//** File description:
//** my_setenv.c
//*/
//
//#include "../../include/my.h"
//
//static int is_alpha(char *c)
//{
//    int i = 0;
//
//    while (c[i] != 0) {
//        if (c[i] >= 'a' && c[i] <= 'z')
//            return 1;
//        if (c[i] >= 'A' && c[i] <= 'Z')
//            return 1;
//        i++;
//    }
//    return 0;
//}
//
//void push_to_back(t_env **head, t_env *new_node)
//{
//    t_env *current;
//
//    if (*head == NULL) {
//        *head = new_node;
//    } else {
//        current = *head;
//        while (current->next != NULL) {
//            current = current->next;
//        }
//        current->next = new_node;
//    }
//}
//
//t_env *new_node_env(char *name, char *value)
//{
//    t_env *new_node = malloc(sizeof(t_env));
//
//    new_node->name = my_strdup(name);
//    new_node->value = my_strdup(value);
//    new_node->next = NULL;
//    return new_node;
//}
//
//void add_in_list(t_shell *my_shell, char *name, char *value)
//{
//    t_env *new_node = new_node_env(name, value);
//
//    push_to_back(&my_shell->env, new_node);
//}
//
//void find_var_exist(t_env **head, char *name, char *value)
//{
//    t_env *tmp = *head;
//
//    while (tmp != NULL) {
//        if (my_strcmp(tmp->name, name) == 0) {
//            free(tmp->value);
//            tmp->value = my_strdup(value);
//            return;
//        }
//        tmp = tmp->next;
//    }
//    push_to_back(head, new_node_env(name, value));
//}
//
//void my_setenv(char **commande, char **env, t_shell *my_shell)
//{
//    if (commande[1] == NULL) {
//        my_env_to(commande, env, my_shell);
//        return;
//    }
//    if (my_shell->cmd->arg[0] == NULL) {
//        my_env_to(commande, env, my_shell);
//        return;
//    }
//    if (is_alpha(my_shell->cmd->arg[0]) == 0) {
//        my_putstr_error("setenv: is not config.\n");
//        my_shell->ret->status = 84;
//        return;
//    }
//    if (my_shell->cmd->arg[1] == NULL)
//        add_in_list(my_shell, my_shell->cmd->arg[0], "");
//    else
//        add_in_list(my_shell, my_shell->cmd->arg[0], my_shell->cmd->arg[1]);
//}
