/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** weather
*/

#include "render_window.h"
#include "weather.h"

static void update(win_t *win, weather_t const *weather)
{
	for (size_t i = 0; i < 10; i++)
		weather->update(win);
}

void update_weather(win_t *win)
{
	static sfClock *timer;
	uint32_t current_time = timer ? sfTime_asMilliseconds(
				sfClock_getElapsedTime(timer)) : 0;

	if (!timer)
		timer = sfClock_create();
	if (current_time < ((INTENSITY_COUNT - 1)
				- win->game->weather_intensity) * 100.f)
		return;
	for (size_t i = 0; weather_list[i].update != NULL; i++)
		if (win->game->weather_type == weather_list[i].weather_type)
			update(win, &weather_list[i]);
	sfClock_restart(timer);
}
