/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/11/24.
** File description:
** my.h
*/

#pragma once

// Forward declaration of functions

#include <stdlib.h>
#include <sys/stat.h>
#include "./command.h"
#include "./shell.h"
#include "stdio.h"

// Forward declaration of t_shellj
int my_strclen(const char *str, const char *delimiters);
void my_putstr(char const *str);
void my_putchar(char c);
char *my_strcat(char *dest, const char *src);
long my_getnbr(char const *str);
void my_put_nbr(int n);
char *my_strdup(char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strncpy(char *dest, char const *src, int n);
int my_strlen(const char *str);
char *my_strcpy(const char *str);
int my_strchr(const char c, const char *delimiters);
int my_strncmp(char const *s1, char const *s2, int n);
char **my_str_to_word_array(const char *str, const char *del,
    size_t *size);
int my_strcspn(const char *s, const char *reject);
void *my_realloc(char *str, int size);
void my_putstr_error(char *str);
int count_words(const char *str, const char *delimiters);
char *my_strccpy(const char *str, const char *delimiters);
int my_isdigit(const char c);
char *my_concat(int count, ...);
char *my_str_replace(char *input, char *replace, char *to_find);
int my_str_isalpha(const char *str);
int my_atoi(const char *str);

// Forward declaration of built_in functions
// zdjkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk

int ret_boucle(mysh_t *mysh);

void parsing(mysh_t *mysh, char *iexpand_error_variablenput);
int entree_valide(mysh_t *mysh, node_t *node);

void execve_function(mysh_t *mysh, list_t *list);

void execute(mysh_t *mysh, node_t *node, const int nb_pipes, const int n);
void connecter_pipe(int pipes[2][2], const int nb_pipes, const int n);
void fermer_pipe(int pipes[2][2], const int nb_pipes, const int n);
void echanger_pipe(int **pipes);

int rediriger_sortie(char **arguments);
int rediriger_entree(mysh_t *mysh, char **arguments);

int built_in(mysh_t *mysh, node_t *node);
int is_built_in(char *str);

int my_cd(mysh_t *mysh, node_t *node);
int my_setenv(mysh_t *mysh, node_t *node);
int my_unsetenv(mysh_t *mysh, node_t *command);
int my_exit(mysh_t *mysh, node_t *command);
void up_env(mysh_t *mysh);
int my_echo(mysh_t *mysh, node_t *node);
void my_env(mysh_t *mysh);

void erase(char **text, size_t n);
static void add_heap(list_t *list, node_t *node);
void my_puterr(const char *str);
int my_isalpha(int c);
int my_str_isnum(const char *str);
int my_atoi(const char *str);
char *my_strstr(char *str, const char *to_find);
char *my_itoa(int nb);
int my_nbrlen(int nb);
void handle_signal_error(int status);
mysh_t initialize(char **env);
int my_strncmp(const char *str1, const char *str2, const int n);
