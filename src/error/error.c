/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** error.c
*/

#include "my.h"

static void afficher_erreur(char *message)
{
    my_putstr_error(message);
}

static void handle_sigsegv_error(int statut)
{
    if (WTERMSIG(statut) == SIGSEGV) {
        if (WCOREDUMP(statut)) {
            afficher_erreur("Segmentation fault (core dumped)\n");
        } else {
            afficher_erreur("Segmentation fault\n");
        }
    }
}

static void handle_sigfpe_error(int statut)
{
    if (WTERMSIG(statut) == SIGFPE) {
        if (WCOREDUMP(statut)) {
            afficher_erreur("Floating exception (core dumped)\n");
        } else {
            afficher_erreur("Floating exception\n");
        }
    }
}

static void handle_sigabrt_error(int statut)
{
    if (WTERMSIG(statut) == SIGABRT) {
        afficher_erreur("Exec format error. Wrong Architecture.\n");
    }
}

void handle_signal_error(int statut)
{
    if (WIFSIGNALED(statut)) {
        handle_sigsegv_error(statut);
        handle_sigfpe_error(statut);
        handle_sigabrt_error(statut);
    }
}
