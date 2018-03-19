/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** weather_modifiers
*/

#include "render_window.h"
#include "weather.h"

void next_weather(win_t *win)
{
	win->game->weather_type++;
	if (win->game->weather_type >= WEATHER_COUNT)
		win->game->weather_type = WEATHER_COUNT - 1;
}

void previous_weather(win_t *win)
{
	if (win->game->weather_type == 0)
		return;
	win->game->weather_type--;
}

void next_intensity(win_t *win)
{
	win->game->weather_intensity++;
	if (win->game->weather_intensity >= INTENSITY_COUNT)
		win->game->weather_intensity = INTENSITY_COUNT - 1;
}

void previous_intensity(win_t *win)
{
	if (win->game->weather_intensity == 0)
		return;
	win->game->weather_intensity--;
}
