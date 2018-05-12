/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** dialog_array
*/

#pragma once

#include <stdlib.h>

static char *dialog_array[6][5] = {
	{
		"Welcome to this super game!",
		"My name is Satoru Iwata.. I will help you to progress!",
		"Take the gun over there and come back after.",
		NULL
	},
	{
		"Are you ready for your first quest?",
		"Yeah! So, you have to kill 5 enemies..",
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
		"Now, try to kill 10 enemies with the UZI.. Good luck!",
		NULL
	},
	{
		"WOW! You finished the game! You can now do what you want.",
		NULL
	},
	{
		NULL
	}
};
