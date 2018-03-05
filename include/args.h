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

#define ARG_FLAT_MAP "--flat"
#define ARG_LOAD_FILE "--load="
#define ARG_FPS_LIMIT "--fps-limit="
#define ARG_SAVE_ON_EXIT "--save-on-exit="

settings_t *get_settings(size_t ac, char **av);
