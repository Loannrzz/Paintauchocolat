/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** shell_command.c
*/

#include "my.h"

void boucle_heredoc(int *pipe_fd, const char *eof)
{
    char *ligne = NULL;
    size_t n = 0;
    ssize_t taille = 0;

    while (1) {
        my_putstr("? ");
        taille = getline(&ligne, &n, stdin);
        ligne[taille - 1] = '\0';
        if (my_strcmp(eof, ligne) == 0) {
            free(ligne);
            break;
        }
        write(pipe_fd[1], ligne, taille);
        write(pipe_fd[1], "\n", 1);
        free(ligne);
        ligne = NULL;
    }
}

static int gerer_heredoc(const char *eof)
{
    int pipe_fd[2];
    pid_t pid = 0;

    if (pipe(pipe_fd) == -1)
        return (0);
    pid = fork();
    if (pid == 0) {
        close(pipe_fd[0]);
        boucle_heredoc(pipe_fd, eof);
        close(pipe_fd[1]);
        exit(EXIT_SUCCESS);
    } else {
        wait(NULL);
    }
    close(pipe_fd[1]);
    return (pipe_fd[0]);
}

static void rediriger_entree_depuis(
    mysh_t *mysh, const char *nom_fichier, int option)
{
    static int entree;

    if (entree)
        close(entree);
    if (option == 1) {
        entree = open(nom_fichier, O_RDONLY, 0777);
    } else {
        entree = gerer_heredoc(nom_fichier);
    }
    if (entree == -1) {
        my_putstr(nom_fichier);
        if (access(nom_fichier, F_OK) == -1) {
            my_putstr_error(": No such file or directory.\n");
        } else {
            my_putstr_error(": -: Is a directory");
        }
        mysh->error = 1;
        exit(0);
    }
    dup2(entree, STDIN_FILENO), close(entree);
}

int rediriger_entree(mysh_t *mysh, char **arguments)
{
    for (int i = 0; arguments[i]; ++i) {
        if (my_strcmp(arguments[i], "<") == 0) {
            rediriger_entree_depuis(mysh, arguments[i + 1], 1);
            erase(&arguments[i], 2);
            return (0);
        }
        if (my_strcmp(arguments[i], "<<") == 0) {
            rediriger_entree_depuis(mysh, arguments[i + 1], 2);
            erase(&arguments[i], 2);
            return (0);
        }
    }
    return (true);
}

void fermer_pipe(int pipes[2][2], const int nb_pipes, const int n)
{
    if (nb_pipes) {
        if (n == nb_pipes || n != 0)
            close(pipes[1][0]);
        if (n == 0 || n != nb_pipes)
            close(pipes[0][1]);
    }
}

void connecter_pipe(int pipes[2][2], const int nb_pipes, const int n)
{
    if (nb_pipes) {
        if (n == nb_pipes || n != 0)
            dup2(pipes[1][0], STDIN_FILENO);
        if (n == 0 || n != nb_pipes)
            dup2(pipes[0][1], STDOUT_FILENO);
    }
}

void echanger_pipe(int **pipes)
{
    int *pipe_courant;

    pipe_courant = pipes[0];
    pipes[0] = pipes[1];
    pipes[1] = pipe_courant;
}
