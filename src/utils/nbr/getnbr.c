/*
** EPITECH PROJECT, 2018
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

float str_to_float(char *str)
{
	int len = 0;
	int n = 0;
	int i = 0;
	float f = 1.0;
	float val = 0.0;

	while (str[len])
		len++;
	if (!len)
		return 0;
	while (i < len && str[i] != '.')
		n = 10 * n + (str[i++] - '0');
	if (i == len)
		return n;
	i++;
	while (i < len) {
		f *= 0.1;
		val += f * (str[i++] - '0');
	}
	return (val + n);
}
