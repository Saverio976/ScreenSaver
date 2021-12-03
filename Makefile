##
## EPITECH PROJECT, 2021
## MYSCREENSAVER
## File description:
## make the myscreensaver
##

NAME 	= 	my_screensaver

PREFIX 	= 	src/

MAIN 	= 	$(PREFIX)main.c

SCREEN1 = 	$(PREFIX)circles/circles.c 	\
		$(PREFIX)circles/circles_next.c \
		$(PREFIX)circles/explain.c

SCREEN2 = 	$(PREFIX)snow/snow.c 		\
		$(PREFIX)snow/snow_next.c 	\
		$(PREFIX)snow/explain.c

SCREEN3 = 	$(PREFIX)spawn/spawn.c 		\
		$(PREFIX)spawn/draw_a.c 	\
		$(PREFIX)spawn/explain.c

SCREEN4 = 	$(PREFIX)nico/nico.c 		\
		$(PREFIX)nico/pixels_fade.c	\
		$(PREFIX)nico/explain.c

SCREEN5 = 	$(PREFIX)bubulles/bubulles.c 			\
		$(PREFIX)bubulles/circles_t_iscolide.c 		\
		$(PREFIX)bubulles/draw_plain_circle.c 		\
		$(PREFIX)bubulles/circles_t_update_colision.c 	\
		$(PREFIX)bubulles/explain.c

SCREEN6 = 	$(PREFIX)bg_fade/bg_fade.c 	\
		$(PREFIX)bg_fade/explain.c

SCREEN7 = 	$(PREFIX)square_rec/square_rec.c \
		$(PREFIX)square_rec/explain.c

SCREEN8 = 	$(PREFIX)langton/langton.c 			\
		$(PREFIX)langton/table_t_create.c 		\
		$(PREFIX)langton/table_t_destroy.c 		\
		$(PREFIX)langton/table_t_to_framebuffer.c 	\
		$(PREFIX)langton/explain.c

SCREEN9 = 	$(PREFIX)gameoflife/gameoflife.c 			\
		$(PREFIX)gameoflife/gameoflife_t_check_three_next.c 	\
		$(PREFIX)gameoflife/gameoflife_t_create.c 		\
		$(PREFIX)gameoflife/gameoflife_t_destroy.c 		\
		$(PREFIX)gameoflife/gameoflife_t_to_buffer.c 		\
		$(PREFIX)gameoflife/explain.c

SCREEN10 = 	$(PREFIX)barnsley_fern/barnsley_fern.c 		\
		$(PREFIX)barnsley_fern/explain.c

SCREEN11 = 	$(PREFIX)fract_square/fract_square.c 	\
		$(PREFIX)fract_square/explain.c

SRC 	= 	$(SCREEN1) 			\
		$(SCREEN2) 			\
		$(SCREEN3) 			\
		$(SCREEN4) 			\
		$(SCREEN5) 			\
		$(SCREEN6) 			\
		$(SCREEN7) 			\
		$(SCREEN8) 			\
		$(SCREEN9) 			\
		$(SCREEN10) 			\
		$(SCREEN11) 			\
		$(PREFIX)master_event.c 	\
		$(PREFIX)cmd_functions.c 	\
		$(PREFIX)main.c

OBJ 	= 	$(SRC:.c=.o)

LPREFIX = 	lib/

IPREFIX = 	include/

CFLAGS 	= 	-Wall -Wextra -Wpedantic -I$(IPREFIX)

LFLAGS 	= 	-L$(LPREFIX) -lall -lcsfml-graphics -lm -lcsfml-system

# ----------------------------------------------------------------------------

all: 	build_lib $(NAME)

$(NAME): 	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LFLAGS) $(CFLAGS)

build_lib:
	make -C $(LPREFIX)

clean:
	rm -rf *.swp

fclean: 	clean
	rm -rf $(OBJ) $(NAME)
	make -C $(LPREFIX) fclean

re: 		fclean all
