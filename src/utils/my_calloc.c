/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** my_calloc
*/

#include <stdlib.h>
#include <string.h>

void *my_calloc(size_t n, size_t n_size)
{
	void *ptr = malloc(n * n_size);

	if (!ptr)
		return NULL;
	memset(ptr, 0, n * n_size);
	return ptr;
}
