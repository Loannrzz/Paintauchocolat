/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** exit.c
*/

#include "my.h"

void exit_shell(mysh_t *mysh)
{
    mysh->exit = true;
}

void set_exit_status(mysh_t *mysh, const char *exit_arg)
{
    if (!my_str_isnum(exit_arg)) {
        if (my_isalpha(exit_arg[0])) {
            my_putstr_error("exit: Expression Syntax.\n");
        } else {
            my_putstr_error("exit: Badly formed number.\n");
        }
        mysh->error = 1;
    } else if (exit_arg[0] == '-' && !exit_arg[1]) {
        my_putstr_error("exit: Expression Syntax.\n");
        mysh->error = 1;
    } else {
        mysh->error = my_atoi(exit_arg) % 256;
        exit_shell(mysh);
    }
}

int my_exit(mysh_t *mysh, node_t *command)
{
    switch (command->len) {
        case 1:
            exit_shell(mysh);
            break;
        case 2:
            set_exit_status(mysh, command->text[1]);
            break;
        default:
            my_putstr_error("exit: Expression Syntax.\n");
            mysh->error = 1;
            break;
    }
    return (1);
}
