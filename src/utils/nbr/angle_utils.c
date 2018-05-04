/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** angle
*/

#include <math.h>

float approximate_angle(float angle)
{
	if (angle < 0) {
		if (angle >= -45.f)
			return 0.f;
		if (angle >= -135.f)
			return 270.f;
		return 180.f;
	}
	if (angle <= 45.f)
		return 0.f;
	if (angle <= 135.f)
		return 90.f;
	if (angle <= 225.f)
		return 180.f;
	if (angle <= 315.f)
		return 270.f;
	return 0.f;
}
