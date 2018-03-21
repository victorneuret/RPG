/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** title_page
*/

#include "title_page.h"

title_page_t *init_title_page(void)
{
	title_page_t *title_page = malloc(sizeof(title_page_t));

	if (!title_page)
		return NULL;
	return title_page;
}
