/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Settings
*/

#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
	uint32_t fps_limit;
	bool display_help;
	bool display_fps;
	bool fullscreen;
	bool skip_intro;
	bool no_sound;
} settings_t;
