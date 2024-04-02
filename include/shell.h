/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/11/24.
** File description:
** shell.h
*/

#pragma once

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "command.h"
#include "my.h"

typedef struct node_s {
    struct node_s *next;
    struct node_s *prev;
    char **text;
    char *str;
    int len;
} node_t;

typedef struct list_s {
    int nb_nodes;
    node_t *first;
    node_t *last;
    void (*add)(struct list_s *, node_t *);
    node_t *(*new)(char **, int);
    void (*pop)(struct list_s *, node_t *);
} list_t;

list_t *new_liked_list(void);

typedef struct heap_s {
    list_t **array;
    int capacity;
    int size;
    void (*add)(struct heap_s *, list_t *);
    void (*pop)(struct heap_s *);
} heap_t;

heap_t new_heap(int capacity);

typedef struct mysh_s {
    heap_t commands;
    list_t *list_env;
    char **env;
    char *oldpwd;
    char *home;
    char **path;
    int error;
    bool exit;
} mysh_t;

typedef struct built_in_t {
    char *name;
    int (*ptr)(mysh_t *, node_t *);
} built_in_t;

void my_env_to(mysh_t *mysh);
heap_t new_command(mysh_t *mysh);

typedef struct ReplaceParams {
    char *input;
    char *replace;
    char *result;
    int to_findlen;
} ReplaceParams;
