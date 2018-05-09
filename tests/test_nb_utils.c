/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** test_nb_utils
*/

#include <math.h>
#include <SFML/System.h>
#include <criterion/criterion.h>

#include "nb_utils.h"

Test(nb_utils, distance)
{
	cr_assert_eq(distance((sfVector2f) {0, 0}, (sfVector2f) {5, 0}), 5);
	cr_assert_eq(distance((sfVector2f) {5, 0}, (sfVector2f) {0, 0}), 5);
	cr_assert_eq(distance((sfVector2f) {-4, 4}, (sfVector2f) {5, -8}), 15);
}
