/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** setenv.c
*/

#include "my.h"

int my_unsetenv(mysh_t *mysh, node_t *command)
{
    node_t *node = mysh->list_env->first;

    if (command->len == 1) {
        my_putstr_error("unsetenv: Too few arguments.\n");
        mysh->error = 1;
        return (1);
    }
    for (int i = 1; node && command->text[i];) {
        if (my_strcmp(node->text[0], command->text[i]) == 0) {
            mysh->list_env->pop(mysh->list_env, node);
            up_env(mysh);
            node = mysh->list_env->first;
            ++i;
            continue;
        }
        if (!node == node->next) {
            node = mysh->list_env->first;
        }
    }
    return (1);
}

void my_setenv_with_args(mysh_t *mysh, node_t *command)
{
    char **env = NULL;
    node_t *node = mysh->list_env->first;

    while (node) {
        if (my_strcmp(node->text[0], command->text[1]) == 0) {
            free(node->text[1]);
            node->text[1] = my_strcpy(command->text[2]);
            up_env(mysh);
            return;
        }
        node = node->next;
    }
    env = malloc(sizeof(char *) * 3);
    env[2] = NULL;
    env[0] = my_strcpy(command->text[1]);
    env[1] = my_strcpy(command->text[2]);
    mysh->list_env->add(mysh->list_env, mysh->list_env->new (env, 2));
    up_env(mysh);
}

int validate_setenv_argument(mysh_t *mysh, const char *var_name)
{
    if (!my_isalpha(var_name[0]) && var_name[0] != '_') {
        my_putstr_error("setenv: Variable name must begin with a letter.\n");
        mysh->error = 1;
        return 0;
    } else if (!my_str_isalpha(var_name)) {
        my_putstr("setenv: characters.\n");
        mysh->error = 1;
        return 0;
    } else {
        return 1;
    }
}

int my_setenv(mysh_t *mysh, node_t *node)
{
    for (int i = 0; node->text[i]; ++i)
        if (my_strchr(node->text[i][0], "<>"))
            return (0);
    switch (node->len) {
        case 1:
            return (0);
        case 2 ... 3:
            if (validate_setenv_argument(mysh, node->text[1])) {
                my_setenv_with_args(mysh, node);
            }
            break;
        default:
            my_putstr("setenv: Too many arguments.");
            mysh->error = 1;
            break;
    }
    return (1);
}
