/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/24/24.
** File description:
** verify_command.c
*/

#include "../../include/my.h"

static const verify_command_dev_t verify_command_dev[] = {
    //    {"cd", my_cd},
    //    {"echo", my_echo},
    //    {"env", my_env_to},
    //    {"setenv", my_setenv},
    //    {"unsetenv", my_unsetenv},
    {NULL, NULL}};

int verify_command(char *command)
{
    int i = 0;

    printf("je suis dans la fonction verify_command\n");
    while (verify_command_dev[i].ptr) {
        if (!my_strcmp(verify_command_dev[i].name, command))
            return 1;
        i++;
    }
    return 0;
}

static int check_command_r(node_t *node)
{
    int i = 1;
    int ret = 0;

    printf("je suis dans la fonction check_command_r\n");
    for (int i = 0; node->text[i]; ++i) {
        printf("je suis dans le while TTTTTTT\n");
        if (!my_strchr(node->text[i][0], "<>"))
            continue;
        if (i == 0)
            return 0;
        if (!node->text[i + 1] || my_strchr(node->text[i + 1][0], "<>"))
            return 0;
        if (++ret > 1)
            return 0;
    }
    printf("je suis dans le return 1A\n");
    return 1;
}

static int check_command_p(myshell_t *my_shell, node_t *node, char *command)
{
    struct stat sb;
    const int ACCESS_CHECK_FLAGS = F_OK | X_OK;

    printf("je suis dans la fonction check_command_p : %s\n", command);
    if (stat(command, &sb) != 0)
        return 0;
    if (!S_ISREG(sb.st_mode) || access(command, ACCESS_CHECK_FLAGS) == -1) {
        my_putstr_error(command);
        my_putstr_error(": Permission denied.\n");
        return -1;
    }
    return 1;
}

static int check_command_s(myshell_t *my_shell, node_t *node)
{
    char *command = NULL;
    int ret = 0;

    printf("DGÇIVHOFGÇIFHÇÀGÇFIHÇOFÇHF\n");
    for (int i = 0; my_shell->path && my_shell->path[i]; ++i) {
        command = my_concat(3, my_shell->path[i], "/", node->text[0]);
        if ((ret += check_command_p(my_shell, node, command))) {
            node->str = command;
            return 1;
        }
    }
    return ret;
}

int check_command(myshell_t *my_shell, node_t *node)
{
    int ret = 0;
    int i = 0;

    if (my_strchr('/', node->text[0])) {
        node->str = node->text[0];
        ret = check_command_p(my_shell, node, node->text[0]);
    } else
        ret = check_command_s(my_shell, node);
    if (ret == 1)
        return 1;
    while (node->text[i]) {
        if (node->text[0][i] != '\\')
            my_putchar(node->text[0][i]);
        i++;
    }
    if (ret != 1) {
        my_putstr_error(node->text[0]);
        my_putstr_error(": Command not found.\n");
    }
    return 0;
}

int check_command2(myshell_t *my_shell, node_t *node)
{
    for (int i = 0; verify_command_dev[i].ptr; i++) {
        if (my_strcmp(verify_command_dev[i].name, node->text[0]))
            return verify_command_dev[i].ptr(my_shell, node);
    }
    return 0;
}

int check(myshell_t *my_shell, node_t *node)
{
    printf("je suis dans la fonction check\n");
    if (!check_command_r(node)) {
        my_putstr_error("Invalid null command.\n");
        return 0;
    }
    if (verify_command(node->text[0])) {
        my_putstr_error("Missing name for redirect.\n");
        return 1;
    }
    if (!check_command(my_shell, node)) {
        printf("je suis dans le if\n");
        return 0;
    }
    printf("je suis dans le return 1B\n");
    return 1;
}