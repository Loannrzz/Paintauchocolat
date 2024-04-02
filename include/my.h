/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/11/24.
** File description:
** my.h
*/

#pragma once

// Forward declaration of functions

#include "./shell.h"
#include "./command.h"
#include <stdlib.h>
#include "stdio.h"
#include <sys/stat.h>

// Forward declaration of t_shell
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
char **my_str_to_word_array(const char *str, const char *delimiters, size_t *size);
int my_strcspn(const char *s, const char *reject);
void *my_realloc(char *str, int size);
void my_putstr_error(char *str);
int count_words(const char *str, const char *delimiters);
char *my_strccpy(const char *str, const char *delimiters);
int my_isdigit(const char c);
char *my_concat(int count, ...);

    // Forward declaration of Error functions
int error_message(char *function, char *message);
void handle_segfault(int status);

// Forward declaration of Initialize functions
myshell_t initialize(char **env);
char **convert_env_to_array(t_shell *my_shell);

// Forward declaration of Process functions
int process_input(myshell_t *my_shell);

// Forward declaration of Free functions

// Forward declaration of my_fonction functions
int verify_command(char *command);
void my_cd(char **commande, char **env, t_shell *my_shell);
void my_clear(char **commande, char **env, t_shell *my_shell);
void my_echo(char **commande, char **env, t_shell *my_shell);
void my_pwd(char **commande, char **env, t_shell *my_shell);
void my_setenv(char **commande, char **env, t_shell *my_shell);
void my_unsetenv(char **commande, char **env, t_shell *my_shell);

// Forward declaration of initialize functions
myshell_t initialize(char **env);
void add_node(list_t *list, node_t *node);
void supp_list(list_t *list, node_t *node);
node_t *create_list(char **data, int size);
node_t *create_node(char **data, int size);
list_t *initialize_env(char **env);
list_t *create_new_list(void);
void up_env(myshell_t *myshell);
char *join_string(char *str1, char *str2);

// Forward declaration of parcing functions
void parcing(myshell_t *my_shell, char *input);

// Forward declaration of check functions
int check(myshell_t *my_shell, node_t *node);
int check_command(myshell_t *my_shell, node_t *node);
static int check_command_2(myshell_t *my_shell, node_t *node, int ret);
int check_command2(myshell_t *my_shell, node_t *node);
static int check_command_s(myshell_t *my_shell, node_t *node);
static int check_command_p(myshell_t *my_shell, node_t *node, char *command);
static int check_command_r(node_t *node);
int verify_command(char *command);

// Forward declaration of exec functions
void add(heap_t *heap, list_t *list);
void supp(heap_t *heap);
int heap_size(heap_t *heap);

// Forward declaration of run functions
int execute(myshell_t *my_shell, list_t *commande);

// Forward declaration of pipe functions

// Forward declaration of env functions
void update_env(myshell_t *my_shell, char *name, char *value);
