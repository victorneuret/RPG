/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** interaction
*/

#pragma once

#include <stdint.h>

#include "render.h"

static const char *FONT_PATH = "res/fonts/space_mono_regular.ttf";

static const uint16_t TEXTBOX_W = 900;
static const uint16_t TEXTBOX_H = 100;
static const uint16_t TEXTBOX_POS_X = (WIN_MAX_W / 2) - (TEXTBOX_W / 2);
static const uint16_t TEXTBOX_POS_Y = WIN_MAX_H - TEXTBOX_H - 150;
