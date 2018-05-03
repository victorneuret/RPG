/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** String utils
*/

#pragma once

#include <unistd.h>
#include <stdbool.h>

size_t my_strlen(char const *str);
void putstr(char const *str);
void puterr(char const *str);
bool str_eq(char const *str1, char const *str2);
int my_strncmp(char const *s1, char const *s2, int n);

bool is_number(char const *str);
bool is_pos_number(char const *str);
char *int_to_str(int nb);
size_t get_nb_len(int nb);
char *my_strncat(char *dest, char const *to_add, size_t n);
char *my_strdup(const char *str);
