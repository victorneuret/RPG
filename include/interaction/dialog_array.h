/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** dialog_array
*/

#pragma once

#include <stdlib.h>

static char *dialog_array[10][5] = {
	{
		"Welcome to this awesome game!",
		"My name is Satoru Iwata. I will help you to progress!",
		"Take the gun over there and come back after.",
		NULL
	},
	{
		"Are you ready for your first quest?",
		"Yeah! So, you have to kill 5 enemies.",
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
			" in your inventory,\nchoose carefully.",
		"Now, try to kill 10 enemies with the UZI. Good luck!",
		NULL
	},
	{
		"Well played! You are no longer a newbie. Hmm... so, " \
			"I will increase\nthe difficulty.",
		"Try to kill 5 big ghosts. Be careful, they do a lot of" \
			" damages.",
		NULL
	},
	{
		"WOW! You are a real gamer!",
		"I am scared by medium ghosts, can you kill 15" \
			" of them for me please?",
		NULL
	},
	{
		"Thank you so much my friend! You saved me.",
		"That is all for now. You can come back later.",
		NULL
	},
	{
		"Do you already want a new quest? You do not waste your time!",
		"OK, take or find the shotgun and kill 25 baby ghosts.",
		NULL
	},
	{
		"GAME IS FINISHED! You can do whatever you want!",
		NULL
	},
	{
		NULL
	}
};
