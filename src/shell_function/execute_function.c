/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** execute_function.c
*/

#include "my.h"

bool built_in_renomme(mysh_t *mysh, node_t *node)
{
    return built_in(mysh, node);
}

void execute(mysh_t *mysh, node_t *node, const int nb_pipes, const int n)
{
    static int pipe_fd[2][2];
    pid_t pid = fork();

    if (nb_pipes && pipe(pipe_fd[0]) == -1) {
        return;
    }
    if (pid == 0) {
        connecter_pipe(pipe_fd, nb_pipes, n);
        rediriger_sortie(node->text);
        rediriger_entree(mysh, node->text);
        if ((my_strcmp(node->text[0], "env") == 0)
            || (my_strcmp(node->text[0], "setenv")) == 0) {
            my_env(mysh);
        } else {
            execve(node->str, node->text, mysh->env);
        }
        exit(EXIT_FAILURE);
    }
    fermer_pipe(pipe_fd, nb_pipes, n);
    echanger_pipe((int **) pipe_fd);
}

void execve_function2(mysh_t *mysh, list_t *commands, node_t *node)
{
    for (int i = 0; node; ++i) {
        if (!node->text[0])
            my_putstr_error("Invalid null command.\n");
        if (!built_in_renomme(mysh, node))
            execute(mysh, node, commands->nb_nodes - 1, i);
        if (node->next)
            node = node->next;
        node = node->next;
    }
}

void execve_function(mysh_t *mysh, list_t *commands)
{
    int status = 0;
    node_t *node = commands->first;

    if (commands->nb_nodes == 0)
        return;
    execve_function2(mysh, commands, node);
    for (int i = 0; i < commands->nb_nodes; i++) {
        wait(&status);
        handle_signal_error(status);
        if (mysh->error == 0 && WIFEXITED(status))
            mysh->error = WEXITSTATUS(status);
    }
}
