/*
 * ** EPITECH PROJECT, 2024
 ** Created by loann.picard-blardone@epitech.eu on 2/29/24.
 ** File description:
 ** command.h
 */

#pragma once

#include "my.h"
#include "shell.h"

// Forward declaration of t_shell
typedef struct s_shell t_shell;

// Function declarations
void my_unsetenv(char **commande, char **env, t_shell *my_shell);
void my_setenv(char **commande, char **env, t_shell *my_shell);
void my_pwd(char **commande, char **env, t_shell *my_shell);
void my_echo(char **commande, char **env, t_shell *my_shell);
void my_clear(char **commande, char **env, t_shell *my_shell);
void my_cd(char **commande, char **env, t_shell *my_shell);

typedef void (*command_func)(char **, char **, t_shell *);

typedef struct {
    char *command;
    command_func func;
} command_map;

extern command_map commands[];
