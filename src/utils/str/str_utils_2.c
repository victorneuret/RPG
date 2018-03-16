/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Sring Utils 2
*/

#include <stdlib.h>

#include "str_utils.h"

char *my_strncat(char *dest, char const *to_add, size_t n)
{
	size_t i;
	size_t dest_len = my_strlen(dest);

	for (i = 0; to_add[i] && i < n; i++)
		dest[dest_len + i] = to_add[i];
	dest[dest_len + i] = 0;
	return dest;
}

char *my_strdup(const char *str)
{
	char *ptr = malloc(my_strlen(str) + 1);
	int count;

	if (ptr == NULL)
		return NULL;
	for (count = 0; str[count] != '\0'; count += 1)
		ptr[count] = str[count];
	ptr[count] = '\0';
	return ptr;
}

bool is_number(char const *str)
{
	size_t i = 0;

	if (!str || my_strlen(str) == 0)
		return false;
	if (str[i] == '-')
		i++;
	for (; i < my_strlen(str); i++) {
		if (str[i] >= '0' && str[i] <= '9')
			continue;
		return false;
	}
	return true;
}

bool is_pos_number(char const *str)
{
	if (!is_number(str))
		return false;
	for (size_t i = 0; i < my_strlen(str); i++) {
		if (str[i] >= '0' && str[i] <= '9')
			continue;
		return false;
	}
	return true;
}
