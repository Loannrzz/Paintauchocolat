/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** my_put_nbr
*/

#include "../../include/my.h"

void my_put_nbr(int nb)
{
    if (my_isneg(nb)){
        my_putchar('-');
        nb *= -1;
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar('0' + (nb % 10));
    } else {
        my_putchar('0' + nb);
    }
}
