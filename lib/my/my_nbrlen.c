/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** my_nbrlen.c
*/

#include "my.h"

int my_nbrlen(int nb)
{
    int i = 0;

    if (my_isneg(nb))
        nb *= -(i);
    if (nb < 9) {
        return i;
    }
    while (nb) {
        nb /= 10;
        ++i;
    }
    return (i);
}
