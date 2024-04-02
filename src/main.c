/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/11/24.
** File description:
** main.c
*/

#include <fcntl.h>
#include <signal.h>
#include "../include/my.h"
#include <sys/wait.h>

void handle_segfault(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV) {
            if (WCOREDUMP(status)) {
                printf("Segmentation fault (core dumped)\n");
            } else {
                printf("Segmentation fault\n");
            }
        }
    }
}

int check_execute(myshell_t *my_shell, list_t *commande, node_t *node)
{
    printf("je suis dans le check_execute\n");
    printf(node == NULL ? "node est null\n" : "node n'est pas null\n");
    if (node == NULL)
        return 1;
    printf("je suis dans le if\n");
    if (commande->nb_nodes == 0)
        return 1;
    printf("je suis dans le if 2\n");
    return 0;
}

void connect_pipe(int pipe[2][2], const int nb_pipes, const int i)
{
    if (nb_pipes) {
        if (i == nb_pipes || i != 0) {
            close(pipe[i - 1][1]);
            dup2(pipe[1][0], STDIN_FILENO);
        }
        if (i != nb_pipes || i == 0) {
            close(pipe[i][0]);
            dup2(pipe[0][1], STDOUT_FILENO);
        }
    }
}

int redirect_out_to(const char *filename, int option)
{
    static int output;

    if (output)
        close(output);
    if (option == 1)
        output = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (option == 2)
        output = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
    dup2(output, STDOUT_FILENO);
    close(output);
}

void erase(char **argument, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        for (int j = 0; argument[i]; ++j) {
            argument[i] = argument[i + 1];
        }
    }
}

int redirect_out(node_t *node)
{
    for (int i = 0; node->text[i]; i++) {
        if (my_strcmp(node->text[i], ">") == 0) {
            redirect_out_to(node->text[i + 1], 1);
            erase(&node->text[i], 2);
            return 0;
        }
        if (my_strcmp(node->text[i], ">>") == 0) {
            redirect_out_to(node->text[i + 1], 2);
            erase(&node->text[i], 2);
            return 0;
        }
    }
    return true;
}

int handle_loop(int pipe_fd[2], const char *eof)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    while (1) {
        my_putstr("? ");
        len = getline(&line, &len, stdin);
        line[read - 1] = '\0';
        if (my_strcmp(line, eof) == 0) {
            free(line);
            break;
        }
        write(pipe_fd[1], line, len);
        write(pipe_fd[1], "\n", 1);
        free(line);
        line = NULL;
    }
}

int handle_heredoc(const char *eof)
{
    int pipe_fd[2];
    pid_t pid = 0;

    if (pipe(pipe_fd) == -1)
        return 0;
    pid = fork();
    if (pid == 0) {
        close(pipe_fd[0]);
        handle_loop(pipe_fd, eof);
        close(pipe_fd[1]);
        exit(EXIT_SUCCESS);
    } else {
        wait(NULL);
    }
    close(pipe_fd[1]);
    return pipe_fd[0];
}

void read_in_from(myshell_t *my_shell, const char *filename, int option)
{
    static int input;

    if (input)
        close(input);
    if (option == 1)
        input = open(filename, O_RDONLY, 0777);
    else
        input = handle_heredoc(filename);
    if (input == -1) {
        my_putstr(filename);
        if (access(filename, F_OK) == -1)
            my_putstr_error(": No such file or directory.\n");
        else
            my_putstr_error("Is a directory");
        my_shell->error = 1;
        exit(0);
    }
    dup2(input, STDIN_FILENO);
    close(input);
}

void redirect_in(myshell_t *my_shell, char **text)
{
    for (int i = 0; text[i]; i++) {
        if (my_strcmp(text[i], "<") == 0) {
            read_in_from(my_shell, text[i + 1], 1);
            erase(&text[i], 2);
            return;
        }
        if (my_strcmp(text[i], "<<") == 0) {
            read_in_from(my_shell, text[i + 1], 2);
            erase(&text[i], 2);
            return;
        }
    }
}

void print_co(
    myshell_t *my_shell, node_t *node, const int nb_pipes, const int i)
{
    static int pipe_2[2][2];
    pid_t pid;

    printf(" nb pirpes = %d\n", nb_pipes);
    pid = fork();
    printf("je suis dans la fonction print_co!!!! %d\n", nb_pipes);
    if (nb_pipes && pipe(pipe_2[0]) == -1)
        return;
    printf("je suis dans le if du print_co\n");
    if (pid == 0) {
        connect_pipe(pipe_2, nb_pipes, i);
        redirect_out(node->text);
        redirect_in(my_shell, node->text);
        printf("je suis dans le if du print_co 2\n");
        if ((my_strcmp(node->text[0], "env") == 0)
            || (my_strcmp(node->text[0], "setenv")) == 0) {
            printf("je suis dans le if du print_co 3\n");
            my_env_to(my_shell);
        } else {
            printf("heoigbfiigf\n");
            printf("execve(%s, %s, %s)\n", node->str, node->text[0], my_shell->env[0]);
            execve(node->str, node->text, my_shell->env);
        }
        exit(EXIT_FAILURE);
    }
    close_pipe(pipe_2, nb_pipes, i);
    swap_pipe((int **) pipe_2);
}

int close_pipe(int pipe[2][2], const int nb_pipes, const int i)
{
    if (nb_pipes) {
        if (i == nb_pipes || i != 0)
            close(pipe[i - 1][0]);
        if (i == 0 || i != nb_pipes)
            close(pipe[i][1]);
    }
}

int swap_pipe(int **pipe)
{
    int *pipe_current;

    pipe_current = pipe[0];
    pipe[0] = pipe[1];
    pipe[1] = pipe_current;
}

int execute(myshell_t *my_shell, list_t *commande)
{
    int i = 0;
    int y = 0;
    int status;

    printf("commande->nb_nodes = %d\n", commande->nb_nodes);
    node_t *node = commande->premier;

    printf("\n\n\n\n\n\nje suis dans la fonction execute\n");
    if (check_execute(my_shell, commande, node) == 1)
        return 1;
    printf("je suis dans le if\n");
    while (i < node) {
        printf("je suis dans le while\n");
        if (!node->text[i])
            return 1;
        if (!check_command2(my_shell, node))
            print_co(my_shell, node, commande->nb_nodes, i);
            i++;
        node = node->next;
    }
    printf("je sort du while\n");
    for (int i = 0; i < commande->nb_nodes; i++) {
        waitpid(i, &status, 0);
        handle_segfault(i);
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    myshell_t my_shell = initialize(env);
    int process_error = process_input(&my_shell);

    if (ac != 1)
        return 84;
    return process_error;
}
