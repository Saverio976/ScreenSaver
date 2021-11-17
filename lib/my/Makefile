##
## EPITECH PROJECT, 2021
## MYSCREENSAVER
## File description:
## make lib my
##

NAME 	= 	libmy.a

SRC 	= 	get_random_between.c 	\
		get_urandom_between.c 	\
		my_getnbr.c 		\
		my_putnbr.c 		\
		my_putstr.c 		\
		my_revstr.c 		\
		my_strlen.c

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
