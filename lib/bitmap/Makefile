##
## EPITECH PROJECT, 2021
## MYSCREENSAVER
## File description:
## make the bitmap lib
##

NAME 	= 	libmap.a

SRC 	= 	bitmap_t_create.c 		\
		bitmap_t_destroy.c

OBJ 	= 	$(SRC:.c=.o)

IPREFIX = 	../../include/

CFLAGS 	= 	-Wall -Wextra -Wpedantic -I$(IPREFIX)

# ----------------------------------------------------------------------------

$(NAME): 	$(OBJ)
	ar rc $(NAME) $(OBJ)

all: 		$(NAME)

clean:
	rm -rf *.swp

fclean: 	clean
	rm -rf $(NAME) $(OBJ)

re: 		fclean all
