/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** joystick
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct render_window win_t;

typedef struct switch_gamepad {
	sfVector2i mouse_pos;
	sfVector2i gamepad_pos;
	bool gamepad;
	sfClock *clock;
} switch_gamepad_t;

typedef struct joystick {
	uint32_t id;
	float lx;
	float ly;
	float rx;
	float ry;
	float dirx;
	float diry;
	float lt;
	float rt;
	switch_gamepad_t *switch_gamepad;
} joystick_t;

#include "render_window.h"

typedef enum joystick_button {
	CONTROLLER_A,
	CONTROLLER_B,
	CONTROLLER_X,
	CONTROLLER_Y,
	CONTROLLER_LB,
	CONTROLLER_RB,
	CONTROLLER_SELECT,
	CONTROLLER_START,
	CONTROLLER_MENU,
	CONTROLLER_L,
	CONTROLLER_R,

	BTN_COUNT
} joystick_button;

typedef enum stick {
	JOYSTICK_LX = sfJoystickX,
	JOYSTICK_LY = sfJoystickY,
	JOYSTICK_LT = sfJoystickZ,
	JOYSTICK_RT = sfJoystickR,
	JOYSTICK_RX = sfJoystickU,
	JOYSTICK_RY = sfJoystickV,
	JOYSTICK_DIRX = sfJoystickPovX,
	JOYSTICK_DIRY = sfJoystickPovY
} stick;


typedef struct struct_gamepad_button_state {
	joystick_button button;
	bool state;
	void (*func)(win_t *win, bool press);
} struct_gamepad_button_state_t;

void button_a(win_t *win, bool press);
void button_b(win_t *win, bool press);
void button_x(win_t *win, bool press);
void button_y(win_t *win, bool press);
void button_lb(win_t *win, bool press);
void button_rb(win_t *win, bool press);
void button_select(win_t *win, bool press);
void button_start(win_t *win, bool press);
void button_menu(win_t *win, bool press);
void button_l(win_t *win, bool press);
void button_r(win_t *win, bool press);

void button_lt(win_t *win, bool press);
void button_rt(win_t *win, bool press);

extern struct_gamepad_button_state_t gamepad_button_state[];

void update_joystick(win_t *win);
void update_mouse_pos_joystick(joystick_t *joystick, win_t *win);
void update_ui_joystick(joystick_t *joystick, win_t *win);
