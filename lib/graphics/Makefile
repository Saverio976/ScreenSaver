##
## EPITECH PROJECT, 2021
## MYSCREENSAVER
## File description:
## make the graphics
##

NAME 	= 	libgraph.a

SRC 	= 	context_t_destroy.c 	\
		context_t_init.c 	\
		figures.c 		\
		framebuffer.c

OBJ 	= 	$(SRC:.c=.o)

IPREFIX = 	../../include/

CFLAGS 	= 	-Wall -Wextra -Wpedantic -I$(IPREFIX)

# ----------------------------------------------------------------------------

all: 		$(OBJ)
	ar rc $(NAME) $(OBJ)

$(NAME): 	all

clean:
	rm -rf *.swp

fclean: 	clean
	rm -rf $(OBJ) $(NAME)

re: 		fclean all
