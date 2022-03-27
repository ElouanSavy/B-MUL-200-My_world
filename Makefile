##
## EPITECH PROJECT, 2021
## B-MUL-100-BDX-1-1-myhunter-elouan.savy-camaret
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/texture_handler.c \
		src/window/window_handler.c \
		src/map/get_map.c \
		src/map/create_map.c \
		src/map/display_map.c \
		src/map/update_map.c \
		src/map/replace_near_point.c \
		src/map/tiles_colors.c \
		src/map/tiles_colors_reverse.c \
		src/map/file_handler.c \
		src/map/file_utils.c	\
		src/map/free_ressources.c	\
		src/game/game_loop.c \
		src/vertex/vertex_manager.c \
		src/event/event_manager.c \
		src/event/event_menu.c \
		src/event/event_load.c \
		src/event/check_clic.c \
		src/cursor/cursor.c \
		src/cursor/modif_assist.c \
		src/cursor/replace_near_point_curs.c \
		src/menu/display_menu.c \
		src/menu/menu_handler.c \
		src/menu/planet_animation.c \
		src/menu/btn_animation.c \
		src/math/calc_distances.c \
		src/game_tools/display_game_tools.c \
		src/game_tools/game_tools_handler.c \
		src/game_tools/list_handler.c \
		src/game_tools/select_action.c \
		src/game_tools/terra_action.c \
		src/game_tools/check_tools_btn.c \
		src/scroller/scroll_init.c \
		src/scroller/scroll_update.c \
		src/display_usage.c \
		src/music/init_musics.c \
		src/load/display_load.c	\
		src/load/init_load.c	\
		src/load/load_handler.c	\
		src/load/map_list_manager.c	\
		src/load/load_save_map.c	\
		src/load/check_map.c \
		src/load/btn_animation.c	\
		src/random_gen/random_gen.c \
		src/random_gen/my_noise.c \
		src/shortcut/shortcut_handler.c	\
		src/free_all_ressources.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra

NAME	=	my_world

CPPFLAGS	=	-I./include

LIB     =       -L./lib/ -lmy

LIBMYPATH =	./lib/libmy.a

all:	$(NAME)

$(NAME):	$(LIBMYPATH) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LIB) -lcsfml-graphics -lcsfml-system \
	-lcsfml-window -lcsfml-audio -lm

clean:
	rm -f $(OBJ);
	rm -f *~;
	rm -f *.gc*
	rm -f vgcore*

fclean : clean
	make fclean -C lib/my
	rm -f $(NAME)
	rm -f unit_tests

re: fclean all

debug: fclean
	make -C lib/my
	gcc -o $(NAME) $(SRC) $(CPPFLAGS) $(LIB) $(CFLAGS) -lcsfml-graphics \
	-lcsfml-system -lcsfml-window -lcsfml-audio -lm -ggdb3

tests_run:
	gcc -o unit_tests $(TEST) $(CPPFLAGS) -Llib/ -lmy -lcriterion --coverage
	./unit_tests

$(LIBMYPATH):
	make -C ./lib/my
