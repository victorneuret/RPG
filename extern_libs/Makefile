##
## EPITECH PROJECT, 2018
## my_rpg_2017
## File description:
## Makefile
##

current_dir = $(shell pwd)

lib_dir = libxml2-2.7.2

NAME	= lib/libxml2.so

all:	$(NAME)

$(NAME):
	tar xzf $(lib_dir).tar.gz
	@cd $(lib_dir);	\
	echo -e "[\e[34m$(lib_dir)\e[39m] : Configuration";	\
	./configure --prefix="$(current_dir)" &> /dev/null;	\
	echo -e "[\e[34m$(lib_dir)\e[39m] : Compiling";	\
	make &> /dev/null;	\
	make install &> /dev/null
	cp $(NAME) libxmllib.so

clean:
	@rm -rf libxml2-2.7.2
	@rm -rf include
	@rm -rf bin
	@rm -rf lib
	@rm -rf share

fclean:	clean
	@rm -f libxmllib.so

re:	fclean all

.PHONY:	all clean fclean re
