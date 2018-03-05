/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** test_nb_utils
*/

#include <math.h>
#include <criterion/criterion.h>

#include "utils/nb_utils.h"

Test(nb_utils, distance)
{
	cr_assert_eq(distance(0, 0, 5, 0), 5);
	cr_assert_eq(distance(5, 0, 0, 0), 5);
	cr_assert_eq(distance(-4, 4, 5, -8), 15);
}
