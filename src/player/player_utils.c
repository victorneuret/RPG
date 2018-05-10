/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** player_utils
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

bool is_player_immune(sfClock *timer)
{
	return sfTime_asSeconds(sfClock_getElapsedTime(timer)) < 1.f;
}
