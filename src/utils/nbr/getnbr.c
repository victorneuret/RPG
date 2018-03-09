/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** send string return number
*/

#include <stdio.h>
#include <unistd.h>

int getnbr(char const *str)
{
	int nb = 0;
	int j = 0;

	if (!str)
		return 0;
	for (int i = 0; str[i] != '\0'; i++) {
		for (j = j; str[i] == '+' || str[i] == '-'; i++)
			(str[i] == '-') ? j++ : 0;
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + (str[i] - '0');
		if (str[i] < '0' || str[i] > '9') {
			(j % 2 == 1) ? nb = nb * -1 : 0;
			return nb;
		}
	}
	if (j % 2 == 1)
		nb = nb * -1;
	return nb;
}
