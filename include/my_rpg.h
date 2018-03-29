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

#include "render_window.h"
#include "my_calloc.h"
#include "nb_utils.h"
#include "mouse_utils.h"

#include "game/events.h"
#include "game/backgrounds.h"
#include "fps.h"
#include "particle.h"
#include "particle_updater.h"
#include "particle_drawer.h"
#include "particle_explosion.h"
#include "particle_stars.h"
#include "particle_fire.h"

bool my_rpg_loop(win_t *win);
