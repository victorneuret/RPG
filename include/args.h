/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Argument management header
*/

#pragma once

#include "settings.h"

#define ARG_HELP "--help"
#define ARG_HELP_SHORT "-h"

#define ARG_FULLSCREEN "--fullscreen"
#define ARG_SHOW_FPS "--fps"
#define ARG_FPS_LIMIT "--fps-limit="

settings_t *get_settings(size_t ac, char **av);
