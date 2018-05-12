/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** dialog_array
*/

#pragma once

#include <stdlib.h>

static char *dialog_array[5][255] = {
	{
		"Welcome to this super game!",
		"My name is Satoru Iwata.. I will help you to progress!",
		"Press Y to learn basic commands.",
		NULL
	},
	{
		"Are you ready for your first quest ?",
		"Yeeeeeees! So, you have to kill 10 enemies..",
		"Come back to me when once you are done.",
		NULL
	},
	{
		"Perfect! You finished the first quest!",
		"You earn XP when you finished a quest, so" \
		" come back to me to have\nanother one.",
		NULL
	},
	{
		"Enemies can drop weapons, you can have 3 weapons" \
		" in your inventory,\nchoose well.",
		"Now, try to kill 10 enemies with the Uzi..",
		"Good luck!",
		NULL
	},
	{
		NULL
	}
};
