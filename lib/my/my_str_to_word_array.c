/*
** EPITECH PROJECT, 2023
** Created by loann.picard-blardone@epitech.eu on 09/11/23.
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include "../../include/my.h"
#include <string.h>

char *extract_word(char **str, const char *delimiters) {
    if (*delimiters == NULL || **str == '\0')
        return NULL;

    int len = strcspn(*str, delimiters); // Trouve la longueur du mot
    char *word = malloc(len + 1); // Alloue la mémoire pour le mot
    if (word == NULL) {
        // Gestion d'erreur si l'allocation échoue
        printf("Error: Unable to allocate memory\n");
        return NULL;
    }
    my_strncpy(word, *str, len); // Copie le mot depuis str
    word[len] = '\0'; // Ajoute le terminateur de chaîne
    *str += len + strspn(*str + len, delimiters); // Avance str jusqu'au prochain mot
    return word;
}

char **my_str_to_word_array(const char *str, const char *delimiters, size_t *size) {
    if (str == NULL || delimiters == NULL || size == NULL) {
        printf("Error: str, delimiters or size is NULL\n");
        return NULL;
    }

    // Compter le nombre de mots
    *size = 0;
    const char *ptr = str;
    while (*ptr) {
        ptr += strspn(ptr, delimiters); // Saute les délimiteurs
        if (*ptr)
            ++(*size);
        ptr += strcspn(ptr, delimiters); // Saute les non-délimiteurs
    }

    // Allouer de la mémoire pour le tableau de pointeurs
    char **words = malloc((*size + 1) * sizeof(char *));
    if (words == NULL) {
        printf("Error: Unable to allocate memory\n");
        return NULL;
    }

    // Extraire les mots et les stocker dans le tableau
    ptr = str;
    for (size_t i = 0; i < *size; ++i) {
        words[i] = extract_word((char **)&ptr, delimiters);
        if (words[i] == NULL) {
            // Gestion d'erreur si l'extraction du mot échoue
            for (size_t j = 0; j < i; ++j)
                free(words[j]); // Libérer la mémoire allouée précédemment
            free(words);
            *size = 0; // Réinitialiser la taille
            printf("Error: Unable to extract word\n");
            return NULL;
        }
    }
    words[*size] = NULL; // Terminateur de tableau
    return words;
}
