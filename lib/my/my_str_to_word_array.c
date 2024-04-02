/*
** EPITECH PROJECT, 2023
** Created by loann.picard-blardone@epitech.eu on 09/11/23.
** File description:
** allocate_space.c
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

char **allocate_word_array(size_t size)
{
    char **words = malloc((size + 1) * sizeof(char *));

    if (words == NULL) {
        my_putstr_error("Error: Unable to allocate memory\n");
        return NULL;
    }
    return words;
}

void free_word_array(char **words, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        free(words[i]);
    free(words);
}

char *extract_word(char **str, const char *delimiters)
{
    int len = strcspn(*str, delimiters);
    char *word = malloc(len + 1);

    if (word == NULL) {
        my_putstr_error("Error: Unable to allocate memory\n");
        return NULL;
    }
    my_strncpy(word, *str, len);
    word[len] = '\0';
    *str += len + strspn(*str + len, delimiters);
    return word;
}

static void loop(char **words, size_t *size, const char *del, const char *ptr)
{
    for (size_t i = 0; i < *size; ++i) {
        words[i] = extract_word((char **)&ptr, del);
        if (words[i] == NULL) {
            free_word_array(words, i);
            *size = 0;
            my_putstr_error("Error: Unable to extract word\n");
            return NULL;
        }
    }
}

char **my_str_to_word_array(const char *str, const char *del, size_t *size)
{
    char **words;
    const char *ptr;

    if (str == NULL || del == NULL || size == NULL) {
        my_putstr_error("Error: str, delimiters or size is NULL\n");
        return NULL;
    }
    *size = count_words(str, del);
    words = allocate_word_array(*size);
    if (words == NULL)
        return NULL;
    ptr = str;
    loop(words, size, del, ptr);
    words[*size] = NULL;
    return words;
}
