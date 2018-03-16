/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Argument management
*/

#include <stdlib.h>

#include "args.h"
#include "settings.h"
#include "render_window.h"

#include "getnbr.h"
#include "str_utils.h"
#include "my_calloc.h"

static bool get_fps_limit(char const *arg, settings_t *settings)
{
	settings->fps_limit = getnbr(arg);
	if (!is_pos_number(arg) || settings->fps_limit == 0) {
		puterr("FPS limit must be a positive integer > 0.\n");
		return false;
	}
	return true;
}

static bool get_arg(char *arg, settings_t *settings, bool *valid_args)
{
	if (!my_strncmp(arg, ARG_FPS_LIMIT, my_strlen(ARG_FPS_LIMIT))) {
		*valid_args = get_fps_limit(arg + 12, settings);
		return true;
	}
	if (str_eq(arg, ARG_HELP) || str_eq(arg, ARG_HELP_SHORT)) {
		settings->display_help = true;
		return true;
	}
	if (str_eq(arg, ARG_SHOW_FPS)) {
		settings->display_fps = true;
		return true;
	}
	if (str_eq(arg, ARG_FULLSCREEN)) {
		settings->fullscreen = true;
		return true;
	}
	return false;
}

static void init_settings(settings_t *settings)
{
	if (!settings)
		return;
	settings->fps_limit = 60;
}

settings_t *get_settings(size_t ac, char **av)
{
	settings_t *settings = my_calloc(1, sizeof(settings_t));
	bool valid_args = true;

	if (!settings)
		return 0;
	init_settings(settings);
	if (ac == 1)
		return settings;
	for (size_t i = 1; valid_args && i < ac; i++)
		if (!get_arg(av[i], settings, &valid_args)) {
			puterr("Retry with ./my_rpg -h\n");
			valid_args = false;
		}
	if (!valid_args) {
		free(settings);
		return NULL;
	}
	return settings;
}
