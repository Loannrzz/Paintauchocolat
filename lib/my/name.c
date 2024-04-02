/*
** EPITECH PROJECT, 2023
** Created by loann.picard-blardone@epitech.eu on 09/11/23.
** File description:
** name.c
*/

#include "../../include/my.h"

const char *get_file_name_2(const char *file_path, int last_bar_on_fyle)
{
    my_putstr("Name: ");
    while (file_path[last_bar_on_fyle] != '\0') {
        my_putchar(file_path[last_bar_on_fyle]);
        last_bar_on_fyle++;
        if (file_path[last_bar_on_fyle] == '.') {
            my_putstr("\n");
            return 0;
        }
    }
    my_putstr("\n");
    return 0;
}

const char *get_file_name(const char *file_path)
{
    int last_bar_on_fyle = 0;
    int error = 0;

    for (int i = 0; file_path[i] != '\0'; i++) {
        if (file_path[i] == '/') {
            last_bar_on_fyle = i;
        }
        error++;
    }
    if (last_bar_on_fyle >= 1) {
        last_bar_on_fyle++;
    }
    get_file_name_2(file_path, last_bar_on_fyle);
    return 0;
}
