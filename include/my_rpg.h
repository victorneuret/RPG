/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** my_rpg_2017
*/

#pragma once

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>

#include "window/render_window.h"
#include "utils/my_calloc.h"
#include "utils/csfml/mouse_utils.h"

#include "game/events.h"
#include "game/display/fps.h"
#include "game/display/drawer.h"
#include "game/particles/particle.h"
#include "game/particles/particle_updater.h"

bool my_rpg_loop(win_t *win);
