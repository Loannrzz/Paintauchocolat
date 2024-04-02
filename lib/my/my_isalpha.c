/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** my_isalpha
*/

int my_isalpha(char c)
{
    return ((c >= 'A' && c <= 'Z')
    || (c >= 'a' && c <= 'z'));
}
