/*
** EPITECH PROJECT, 2023
** Created by loann.picard-blardone@epitech.eu on 09/11/23.
** File description:
** allocate_space.c
*/

#include "my.h"
#include <sys/stat.h>
#include <bits/struct_stat.h>

int get_file_allocated_space(const char *file_path)
{
    struct stat file_all;
    int allocate_space;
    int ret = stat(file_path, &file_all);

    if (ret == 0) {
        allocate_space = file_all.st_blocks;
        my_put_nbr(allocate_space);
    }
    my_putchar('\n');
    return 0;
}
