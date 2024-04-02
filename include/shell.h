/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/11/24.
** File description:
** shell.h
*/

#pragma once

#include "my.h"
#include "command.h"
#include <stdbool.h>
#include "unistd.h"

typedef struct node_s { // Arbre binaire
    struct node_s *next; // Fils droit
    struct node_s *prev; // Fils gauche
    char **text; // Commande
    char *str; // Commande
    int len; // Longueur de la commande
}node_t;

typedef struct list_s {
    int nb_nodes; // Nombre de noeuds
    node_t *premier; // Premier noeud
    node_t *dernier; // Dernier noeud
    void (*add)(struct list_s *, node_t *); // Ajouter un noeud
    node_t *(*new)(char **, int); // Créer un noeud
    void (*supp)(struct list_s *, node_t *); // Supprimer un noeud
    int (*size)(struct list_s *); // Taille de la liste
} list_t;

typedef struct heap_s {
    list_t **array; // Tableau de listes
    int size; // Taille
    void (*add)(struct heap_s *, list_t *); // Ajouter une liste
    void (*supp)(struct heap_s *); // Supprimer une liste
}heap_t;

typedef struct myshell_s { // Structure principale
    heap_t commands; // Tas de commandes
    list_t *list_env; // Liste des variables d'environnement
    char **env; // Variables d'environnement
    char *oldpwd; // Ancien répertoire
    char *home; // Répertoire home
    char **path; // Chemin
    int error; // Erreur
    bool exit; // Sortie
}myshell_t;

typedef struct verify_command_dev_s {
    char *name; // Nom de la commande
    int (*ptr)(myshell_t *, node_t *); // Pointeur de fonction
}verify_command_dev_t;

void my_env_to(myshell_t *my_shell);
heap_t new_command(myshell_t *my_shell);
