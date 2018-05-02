/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** main
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "my_rpg.h"
#include "args.h"
#include "settings.h"
#include "render_window.h"
#include "xml.h"

#include "getnbr.h"
#include "str_utils.h"

#include "dungeon.h"

static bool is_valid_env(char **env)
{
	for (size_t i = 0; env && env[i]; i++)
		if (my_strncmp("DISPLAY=", env[i], 8) == 0)
			return true;
	return false;
}

static int print_help(void)
{
	char buffer[2];
	int fd = open("README.txt", O_RDONLY);

	if (fd == -1)
		return 84;
	while (read(fd, buffer, 1) > 0) {
		buffer[1] = '\0';
		putstr(buffer);
	}
	close(fd);
	return 0;
}

static bool start_rpg(int ac, char **av, char **env)
{
	win_t *window = 0;
	settings_t *settings = 0;

	if (!is_valid_env(env)) {
		puterr("Invalid environment: Missing DISPLAY variable.\n");
		return false;
	}
	settings = get_settings(ac, av);
	if (!settings)
		return false;
	if (settings->display_help)
		return print_help();
	window = create_window(1600, 900, settings);
	if (!window)
		return false;
	window->settings = settings;
	my_rpg_loop(window);
	destroy_window(window);
	return true;
}

int main(int ac, char **av, char **env)
{
	if (!start_rpg(ac, av, env))
		return 84;
	if (!xml_exemple())
		return 84;
	dungeon_t *dungeon = init_dungeon();
	if (!dungeon)
		return 84;
	print_dungeon(dungeon);
	return 0;
}
