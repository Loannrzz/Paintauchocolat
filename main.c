/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 4/2/24.
** File description:
** main.c
*/

#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 1)
        printf("Hello, World!\n");
    else
        printf("Hello, %s!\n", argv[1]);
    for (int i = 0; i < argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    return 0;
}
