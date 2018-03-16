/*
** EPITECH PROJECT, 2017
** mysh
** File description:
** Int to string
*/

#include <stdlib.h>

#include "macros.h"
#include "my_calloc.h"
#include "str_utils.h"

static void recursive_append_nb(int nb, char *result, int *index)
{
	if (nb >= 10 || nb <= -10)
		recursive_append_nb(nb / 10, result, index);
	result[*index] = (ABS(nb) % 10 + 48);
	*index = *index + 1;
}

size_t get_nb_len(int nb)
{
	size_t length = 0;

	if (nb < 0)
		length++;
	if (nb == 0)
		return 1;
	while (nb != 0) {
		nb /= 10;
		length++;
	}
	return length;
}

char *int_to_str(int nb)
{
	int index = 0;
	size_t length = get_nb_len(nb);
	char *result = my_calloc(length + 1, sizeof(char));

	if (!result)
		return 0;
	if (nb < 0)
		result[index++] = '-';
	if (nb == 0)
		result[index++] = '0';
	else
		recursive_append_nb(nb, result, &index);
	result[length] = 0;
	return result;
}
