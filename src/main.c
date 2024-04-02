/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/11/24.
** File description:
** main.c
*/

#include "my.h"

mysh_t initialiser(char **environnement)
{
    return initialize(environnement);
}

int boucle(mysh_t *mysh)
{
    return ret_boucle(mysh);
}

int main(int argc, char **argv, char **env)
{
    int codeErreur = 0;
    mysh_t mysh = initialiser(env);

    if (argc != 1) {
        return 84;
    }
    codeErreur = boucle(&mysh);
    return codeErreur;
}
