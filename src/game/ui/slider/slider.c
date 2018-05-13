/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** slider
*/

#include "render_window.h"
#include "slide_bar.h"
#include "my_calloc.h"

bool init_slide_bar(ui_t *ui)
{
	ui->slide_bar = my_calloc(sizeof(slide_bar_t *), 3);
	if (!ui->slide_bar)
		return false;
	for (size_t i = 0; slide_bar_def[i].game_state != ALL; i++) {
		ui->slide_bar[i] = my_calloc(sizeof(slide_bar_t), 1);
		ui->slide_bar[i]->game_state = slide_bar_def[i].game_state;
		ui->slide_bar[i]->rect = init_rectangle(slide_bar_def[i].pos,
					(sfVector2f) {255, 30},
					hex_to_rgba(slide_bar_def[i].clr));
		ui->slide_bar[i]->cursor = init_rectangle((sfVector2f)
			{slide_bar_def[i].pos.x + 255, slide_bar_def[i].pos.y},
			(sfVector2f) {1, 30}, sfWhite);
		ui->slide_bar[i]->value = 255;
	}
	return true;
}

static void set_player_color(player_t *player, slide_bar_t **slide_bar)
{
	sfColor color = sfColor_fromRGB(slide_bar[0]->value,
			slide_bar[1]->value, slide_bar[2]->value);

	sfSprite_setColor(player->sprite, color);
}

static void check_slider_hit_box(slide_bar_t *slide_bar, win_t *win)
{
	sfFloatRect rect = sfRectangleShape_getGlobalBounds(slide_bar->rect);
	sfVector2f cursor_pos = sfRectangleShape_getPosition(slide_bar->cursor);
	sfVector2f mouse = get_mouse_pos(win);
	sfVector2f pos = {mouse.x, cursor_pos.y};

	if (win->game_state != CUSTOM)
		return;
	if (pos.x < rect.left)
		pos.x = rect.left;
	else if (pos.x > rect.left + rect.width)
		pos.x = rect.left + rect.width;
	if (mouse.y >= rect.top && mouse.y <= rect.top + rect.height) {
		sfRectangleShape_setPosition(slide_bar->cursor, pos);
		slide_bar->value = pos.x - rect.left;
		set_player_color(win->game->player, win->game->ui->slide_bar);
	}
}

void slide_bar_click(slide_bar_t **slide_bar, win_t *win, uint8_t status)
{
	static uint8_t state = 0;

	if (status == 1)
		state = 1;
	else if (status == 0)
		state = 0;
	if (state == 0)
		return;
	for (size_t i = 0; slide_bar_def[i].game_state != ALL; i++)
		check_slider_hit_box(slide_bar[i], win);
}

void draw_slide_bar(ui_t *ui, win_t *win)
{
	slide_bar_click(ui->slide_bar, win, 2);
	for (size_t i = 0; slide_bar_def[i].game_state != ALL; i++) {
		sfRenderWindow_drawRectangleShape(win->sf_win,
						ui->slide_bar[i]->rect, 0);
		sfRenderWindow_drawRectangleShape(win->sf_win,
						ui->slide_bar[i]->cursor, 0);
	}
}
