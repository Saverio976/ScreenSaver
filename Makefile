##
## EPITECH PROJECT, 2021
## MYSCREENSAVER
## File description:
## make the myscreensaver
##

NAME 	= 	my_screensaver

PREFIX 	= 	src/

MAIN 	= 	$(PREFIX)main.c

SRC 	= 	$(PREFIX)circles/circles.c 		\
		$(PREFIX)circles/circles_next.c 	\
		$(PREFIX)snow/snow.c 			\
		$(PREFIX)spawn/spawn.c 			\
		$(PREFIX)spawn/draw_a.c 		\
		$(PREFIX)nico/nico.c

OBJ 	= 	$(SRC:.c=.o)

LPREFIX = 	lib/

IPREFIX = 	include/

CFLAGS 	= 	-Wall -Wextra -Wpedantic -I$(IPREFIX)

LFLAGS 	= 	-L$(LPREFIX) -lall -lcsfml-graphics -lm -lcsfml-system

# ----------------------------------------------------------------------------

all: 		build_lib $(OBJ)
	gcc -o $(NAME) $(MAIN) $(OBJ) $(LFLAGS) $(CFLAGS)

$(NAME): 	all

build_lib:
	make -C $(LPREFIX)

clean:
	rm -rf *.swp

fclean: 	clean
	rm -rf $(OBJ) $(NAME)
	make -C $(LPREFIX) fclean

re: 		fclean all
