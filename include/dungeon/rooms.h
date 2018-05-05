/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** rooms
*/

#pragma once

#include <unistd.h>
#include <stdint.h>

#include "dungeon.h"

static const char *rooms_setup[ROOM_HEIGHT][ROOM_WIDTH] = {
	// {
	// 	"*************",
	// 	"*************",
	// 	"*************",
	// 	"*************",
	// 	"*************",
	// 	"*************",
	// 	"*************",
	// 	NULL
	// },
	// {
	// 	"*************",
	// 	"**XXX***X****",
	// 	"********X****",
	// 	"****X***X****",
	// 	"****X********",
	// 	"****X***XXX**",
	// 	"*************",
	// 	NULL
	// },
	// {
	// 	"X************",
	// 	"*************",
	// 	"XXXXX********",
	// 	"*************",
	// 	"********XXXXX",
	// 	"*************",
	// 	"************X",
	// 	NULL
	// },
	// {
	// 	"*************",
	// 	"*X*X*****X*X*",
	// 	"****X***X****",
	// 	"*************",
	// 	"****X***X****",
	// 	"*X*X*****X*X*",
	// 	"*************",
	// 	NULL
	// },
	// {
	// 	"*************",
	// 	"***X*****X***",
	// 	"**X*******X**",
	// 	"*X**X***X**X*",
	// 	"**X*******X**",
	// 	"***X*****X***",
	// 	"*************",
	// 	NULL
	// },
	{
		"*************",
		"****XX*XX****",
		"***X*****X***",
		"***X*****X***",
		"***X*****X***",
		"****XXXXX**X*",
		"*************",
		NULL
	},
	{
		NULL
	}
};
