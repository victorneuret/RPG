/*
** EPITECH PROJECT, 2018
** xml
** File description:
** xml
*/

#pragma once

#include <libxml/parser.h>

#include <stdbool.h>

#include "player.h"
#include "inventory.h"
#include "texture.h"

xmlDoc *load_xml_file(char *file_name);
xmlNode *load_xml_node(xmlDoc *document);
xmlNode *get_node_by_name(xmlNode *root, const char *name);
char *get_node_string(xmlNode *root, const char *node_name);
int get_node_int(xmlNode *root, const char *node_name);
float get_node_float(xmlNode *root, const char *node_name);
char *get_prop(xmlNode *root, const char *prop_name);
bool parse_player(xmlNode *root);
bool xml_exemple(void);
bool xml_player(player_t *player);
bool xml_item(item_t *item, textures_t *texture);
