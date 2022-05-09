##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile for bistro
##

SRC	=	main.c	\
		object_handling/object_creation.c 	\
		object_handling/object_delete.c 	\
		object_handling/move_object.c	\
		object_handling/move_sprite_rects.c	\
		object_handling/display_objects.c	\
		object_handling/collision.c 	\
		object_handling/score.c 	\
		window_actions/analyse_events.c 	\
		window_actions/window_create.c	\
		object_display/background_display.c	\
		backgrounds_handling/create_backgrounds.c	\
		car_handling/create_car.c	\
		car_handling/car_animate.c	\
		manage_config_files/put_config_into_str.c	\
		map/map_create.c	\
		sound_handling/sound_handling.c	\
		map/get_obstacles.c	\
		map/obstacle_create.c 	\
		menu_handling.c	\
		text_handling/text_display.c	\
		text_handling/score_display.c	\
		text_handling/menu_display.c 	\
		help.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iinclude/ -Llib/my/ -lmy -g

FILES	= 	my_runner.c

CCRITERION	= 	--coverage -lcriterion

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CSFML)

tests_run:
	rm -f unit*
	make -C lib/my/
	gcc -o unit_tests $(FILES) tests/tests_pushswap.c $(CFLAGS) $(CCRITERION)
	./unit_tests

clean:
	rm -f $(OBJ)

fclean: clean
	make clean -C lib/my
	$(RM) $(NAME)
	rm -f unit*

re: fclean all

.PHONY : all re clean tests_run fclean
