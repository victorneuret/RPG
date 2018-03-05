/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Color utils
*/

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
