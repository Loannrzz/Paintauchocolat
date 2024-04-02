/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** redirect.c
*/

#include "my.h"

static void rediriger_sortie_vers(const char *nom_fichier, int option)
{
    static int sortie;

    if (sortie)
        close(sortie);
    if (option == 1)
        sortie = open(nom_fichier, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (option == 2)
        sortie = open(nom_fichier, O_WRONLY | O_CREAT | O_APPEND, 0777);
    dup2(sortie, STDOUT_FILENO);
    close(sortie);
}

int rediriger_sortie(char **arguments)
{
    for (int i = 0; arguments[i]; ++i) {
        if (my_strcmp(arguments[i], ">") == 0) {
            rediriger_sortie_vers(arguments[i + 1], 1);
            erase(&arguments[i], 2);
            return 0;
        }
        if (my_strcmp(arguments[i], ">>") == 0) {
            rediriger_sortie_vers(arguments[i + 1], 2);
            erase(&arguments[i], 2);
            return 0;
        }
    }
    return true;
}
