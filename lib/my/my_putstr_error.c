/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 2/29/24.
** File description:
** my_putstr_error.c
*/

#include "../../include/my.h"

void my_putstr_error(char *str)
{
    write(2, str, my_strlen(str));
}
