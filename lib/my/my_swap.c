/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** my_swap
*/

void my_swap(char *a, char *b)
{
    char tmp = *a;

    *a = *b;
    *b = tmp;
}
