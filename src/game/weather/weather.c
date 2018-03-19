/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** weather
*/

#include "render_window.h"
#include "weather.h"

void update_weather(win_t *win)
{
	for (size_t i = 0; weather_list[i].update != NULL; i++)
		if (win->game->weather_type == weather_list[i].weather_type)
			weather_list[i].update(win);
}
