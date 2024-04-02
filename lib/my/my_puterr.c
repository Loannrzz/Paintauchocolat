/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** my_puterr
*/

#include "../../include/my.h"

void my_puterr(const char *str)
{
    write(2, str, my_strlen(str));
}
