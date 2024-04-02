/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** my_putchar
*/

#include "../../include/my.h"

void my_putchar(const char c)
{
    write(1, (char[1]){c}, 1);
}
