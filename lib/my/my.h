/*
** EPITECH PROJECT, 2023
** Created by loann.picard-blardone@epitech.eu on 06/11/23.
** File description:
** my.h
*/

#pragma once
#include <sys/types.h>
#include <sys/stat.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int flags(char name_flag);
int ls_classic(void);
int ls_flags_a(void);
int ls_flags_1(void);
int ls_flags_c(void);
int ls_classic_with_name(char const *file_of_name);
int ls_flags_large_c(void);
int ls_flags_large_r(char firs_letter, char seconde_letters);
int verif_firs_letters(int argc, char *firs_letter, char *seconde_letter);

//Info file call all function
void info_file(int nb_caract, char *argv[]);

//Lib
void my_putstr(char *str);
void my_putchar(char c);
char *my_strcat(const char *s1, const char *s2);
long my_getnbr(char const *str);
void my_put_nbr(int n);
char *my_strdup(char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strncpy(char *dest, char const *src, int n);
int my_strlen(const char *str);
char *my_strcpy(char *dest, const char *src);

//file
const char *get_file_name(const char *file_path);
void get_file_type(const char *file_path);
void add_all_file(const char *directory_path);
int get_file_inode(const char *file_path);
int get_file_hard_link(const char *file_path);
int get_file_size(const char *file_path);
int get_file_allocated_space(const char *file_path);
int get_device_minor(const char *file_path);
int get_device_major(const char *file_path);
int get_file_uid(const char *file_path);
int get_file_gid(const char *file_path);

//error
int error(int nb_flags);
