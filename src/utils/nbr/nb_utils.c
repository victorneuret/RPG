/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Number utils
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "macros.h"

static unsigned int random_seed(void)
{
	unsigned int seed = 0;
	char *tmp1 = malloc(1);
	char *tmp2 = malloc(1);

	seed = (unsigned long) tmp1 * (unsigned long) tmp2;
	free(tmp1);
	free(tmp2);
	return seed;
}

static unsigned int rand_uint(unsigned int min, unsigned int max)
{
	static unsigned int seed = 0;

	if (!seed) {
		seed = random_seed();
		srand(seed);
	}
	return ((double) rand() / (double) RAND_MAX) * (max + 1 - min) + min;
}

double rand_range(void)
{
	static unsigned int seed = 0;

	if (!seed) {
		seed = random_seed();
		srand(seed);
	}
	return (double) rand() / (double) RAND_MAX;
}

int rand_int(int min, int max)
{
	int rdm;
	int min_cpy = min;

	if (min < 0) {
		max += ABS(min);
		min = 0;
	}
	rdm = rand_uint(MIN(min, max), MAX(min, max));
	if (min_cpy < 0)
		rdm -= ABS(min_cpy);
	return rdm;
}

unsigned int distance(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
