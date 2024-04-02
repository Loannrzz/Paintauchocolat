/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** my_putstr
*/

#include "../../include/my.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
