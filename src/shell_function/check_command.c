/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** check_command.c
*/

#include "my.h"

static int check_file_permission(char *path)
{
    struct stat st;

    if (stat(path, &st) != 0)
        return (0);
    if (!S_ISREG(st.st_mode) || access(path, F_OK | X_OK) == -1)
        return (-1);
    return (1);
}

int verifier_permission_fichier(char *chemin)
{
    return check_file_permission(chemin);
}

int redirection_valide(char **commande)
{
    int redirection = 0;

    for (int index = 0; commande[index]; ++index) {
        if (!my_strchr(commande[index][0], "<>"))
            continue;
        if (index == 0) {
            my_putstr_error("Invalid null command.\n");
            return (0);
        }
        if (!commande[index + 1] || my_strchr(commande[index + 1][0], "<>")) {
            my_putstr_error("Missing name for redirect.\n");
            return (0);
        }
        redirection = redirection + 1;
        if (redirection > 1) {
            my_putstr_error("Ambiguous output redirect.\n");
            return (0);
        }
    }
    return (1);
}

int commande_systeme(mysh_t *mysh, node_t *noeud)
{
    char *chemin = NULL;
    int permission = 0;

    for (int index = 0; mysh->path && mysh->path[index]; ++index) {
        chemin = my_concat(3, mysh->path[index], "/", noeud->text[0]);
        permission = verifier_permission_fichier(chemin);
        if (permission) {
            noeud->str = chemin;
            return (1);
        }
    }
    return (permission);
}

int commande_valide(mysh_t *mysh, node_t *noeud)
{
    int permission = 0;

    if (my_strchr('/', noeud->text[0])) {
        noeud->str = noeud->text[0];
        permission = verifier_permission_fichier(noeud->text[0]);
    } else {
        permission = commande_systeme(mysh, noeud);
    }
    if (permission == 1)
        return (1);
    for (int index = 0; noeud->text[0][index]; ++index) {
        if (noeud->text[0][index] != '\\')
            my_putchar(noeud->text[0][index]);
    }
    if (permission == 0) {
        my_putstr_error(": Command not found.\n");
    } else {
        my_putstr_error(": Permission denied.\n");
    }
    return 0;
}

int entree_valide(mysh_t *mysh, node_t *noeud)
{
    if (!redirection_valide(noeud->text))
        return (0);
    if (is_built_in(noeud->text[0]))
        return (1);
    if (!commande_valide(mysh, noeud))
        return (0);
    return (1);
}
