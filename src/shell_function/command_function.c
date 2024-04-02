/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/24/24.
** File description:
** command_function.c
*/

#include "../../include/my.h"

void supp(heap_t *heap)
{
    if (heap->size == 0)
        return;
    while (heap->array[heap->size - 1]->premier)
        heap->array[heap->size - 1]->supp(
            heap->array[heap->size - 1], heap->array[heap->size - 1]->dernier);
    --heap->size;
}

void add(heap_t *heap, list_t *list)
{
    heap->array[heap->size++] = list;
}

heap_t new_command(myshell_t *my_shell)
{
    printf("morgh\n");
    heap_t heap = {
        .size = 0,
        .array = malloc(sizeof(list_t *)),
        .add = add,
        .supp = supp
    };
    return heap;
}
