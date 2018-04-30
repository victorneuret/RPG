/*
** EPITECH PROJECT, 2018
** xml
** File description:
** xml
*/

#pragma once

#include <libxml/parser.h>

#include <stdbool.h>

xmlDoc *load_xml_file(char *file_name);
xmlNode *load_xml_node(xmlDoc *document);
xmlNode *get_node_by_name(xmlNode *root, char *name);
char *get_node_string(xmlNode *root, char *node_name);
int get_node_int(xmlNode *root, char *node_name);
char *get_prop(xmlNode *root, char *prop_name);
bool parse_player(xmlNode *root);
bool xml_exemple(void);
