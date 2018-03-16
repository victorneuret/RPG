/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** test_utils
*/

#include <criterion/criterion.h>

#include "getnbr.h"

Test(getnbr, getnbr)
{
	cr_assert_eq(getnbr("42"), 42);
	cr_assert_eq(getnbr("-42"), -42);
	cr_assert_eq(getnbr("Hello"), 0);
	cr_assert_eq(getnbr("44ozkdp"), 44);
	cr_assert_eq(getnbr("aaaaaa50"), 0);
	cr_assert_eq(getnbr(""), 0);
}
