/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** while.c
*/

#include "my.h"

void analyser(mysh_t *mysh, char *input)
{
    execve_function(mysh, input);
}

void executer(mysh_t *mysh, list_t *list)
{
    parsing(mysh, list);
}

int ret_boucle(mysh_t *mysh)
{
    size_t taille = 0;
    char *ligne = NULL;

    do {
        if (isatty(0))
                my_putstr("[Tu es le meilleurs AER] ~> ");
        if (getline(&ligne, &taille, stdin) == -1)
            return mysh->error;
        executer(mysh, ligne);
        for (int i = 0; i < mysh->commands.size; ++i)
            analyser(mysh, mysh->commands.array[i]);
        free(ligne);
        ligne = NULL;
        if (mysh->exit)
            return mysh->error;
    } while (1);
}
