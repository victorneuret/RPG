/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Color utils
*/

#include <stdint.h>
#include <stdbool.h>
#include <SFML/Graphics.h>

sfColor hex_to_rgb(unsigned int hex)
{
	const unsigned int mask = 255;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	b = hex & mask;
	hex >>= 8;
	g = hex & mask;
	hex >>= 8;
	r = hex & mask;
	return (sfColor) {r, g, b, 255};
}

sfColor hex_to_rgba(unsigned int hex)
{
	const unsigned int mask = 255;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;

	a = hex & mask;
	hex >>= 8;
	b = hex & mask;
	hex >>= 8;
	g = hex & mask;
	hex >>= 8;
	r = hex & mask;
	return (sfColor) {r, g, b, a};
}

uint8_t get_particle_alpha(bool fade_in, bool fade_out,
			uint32_t current, uint32_t lifetime)
{
	double ratio = current / (double) lifetime;

	if (!fade_out && fade_in)
		return ratio * 255.f;
	if (fade_out && !fade_in)
		return 255 - (ratio * 255.f);
	if (fade_out && fade_in) {
		if (ratio <= 0.5)
			return (2 * ratio) * 255.f;
		else
			return (-2 * ratio + 2) * 255.f;
	}
	return 255;
}
