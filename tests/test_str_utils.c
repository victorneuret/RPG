/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** test_utils
*/

#include <criterion/criterion.h>

#include "utils/str_utils.h"

Test(str_utils, is_number)
{
	cr_assert_eq(is_number("42"), true);
	cr_assert_eq(is_number("-42"), true);
	cr_assert_eq(is_number("Moira > All"), false);
	cr_assert_eq(is_number("44ozkdp"), false);
	cr_assert_eq(is_number("aaaaaa50"), false);
	cr_assert_eq(is_number(""), false);
	cr_assert_eq(is_number(NULL), false);
}

Test(str_utils, is_pos_number)
{
	cr_assert_eq(is_pos_number("42"), true);
	cr_assert_eq(is_pos_number("-42"), false);
	cr_assert_eq(is_pos_number("Moira > All"), false);
	cr_assert_eq(is_pos_number("44ozkdp"), false);
	cr_assert_eq(is_pos_number("aaaaaa50"), false);
	cr_assert_eq(is_pos_number(""), false);
	cr_assert_eq(is_pos_number(NULL), false);
}

Test(str_utils, get_path)
{
	char *path = get_path("hello");

	if (!path)
		return;
	cr_assert_str_eq(path, "maps/hello.legend");
	free(path);
}

Test(str_utils, my_strncat)
{
	char str[128];

	for (size_t i = 0; i < 128; i++)
		str[i] = '\0';
	my_strncat(str, "Hello", 5);
	my_strncat(str, " ", 1);
	my_strncat(str, "world", 5);
	my_strncat(str, "!mlzff", 1);
	cr_assert_str_eq(str, "Hello world!");
}

Test(str_utils, str_eq)
{
	cr_assert_eq(str_eq("Hello", "Hello"), true);
	cr_assert_eq(str_eq("", ""), true);
	cr_assert_eq(str_eq("", " "), false);
	cr_assert_eq(str_eq(NULL, NULL), true);
	cr_assert_eq(str_eq(NULL, "NULL"), false);
	cr_assert_eq(str_eq("my_rpg", "my_rpg"), true);
}
