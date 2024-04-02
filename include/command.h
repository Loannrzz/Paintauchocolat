/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 2/29/24.
** File description:
** command.h
*/

#pragma once

#include "my.h"
#include "shell.h"

// Forward declaration of t_shell
typedef struct s_shell t_shell;

typedef void (*command_func)(char **, char **, t_shell *);

typedef struct {
    char *command;
    command_func func;
} command_map;

extern command_map commands[];
