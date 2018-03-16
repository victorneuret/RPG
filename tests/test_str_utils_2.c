/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** test_utils
*/

#include <criterion/criterion.h>

#include "str_utils.h"

Test(str_utils, my_strncmp)
{
	cr_assert_eq(my_strncmp("Hello", "Hello", 5) == 0, true);
	cr_assert_eq(my_strncmp("Hello", "Hello", 6) == 0, true);
	cr_assert_eq(my_strncmp("Hello friend", "Hello world", 5) == 0, true);
	cr_assert_eq(my_strncmp("Heyya", "Hello", 5) == 0, false);
	cr_assert_eq(my_strncmp("", "", 5) == 0, true);
	cr_assert_eq(my_strncmp(NULL, NULL, 5) == 0, true);
	cr_assert_eq(my_strncmp(NULL, "NULL", 5) == 0, false);
}

Test(str_utils, get_nb_len)
{
	cr_assert_eq(get_nb_len(42), 2);
	cr_assert_eq(get_nb_len(-42), 3);
	cr_assert_eq(get_nb_len(1234567890), 10);
	cr_assert_eq(get_nb_len(0), 1);
}

Test(str_utils, int_to_str)
{
	char *str;

	str = int_to_str(42);
	cr_assert_str_eq(str, "42");
	free(str);
	str = int_to_str(-42);
	cr_assert_str_eq(str, "-42");
	free(str);
	str = int_to_str(87654);
	cr_assert_str_eq(str, "87654");
	free(str);
	str = int_to_str(0);
	cr_assert_str_eq(str, "0");
	free(str);
}

Test(str_utils, my_strdup)
{
	char src[] = "Hello world!";
	char *dup = my_strdup(src);

	cr_assert_str_eq(src, dup);
	free(dup);
}
