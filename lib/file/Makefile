##
## EPITECH PROJECT, 2021
## BSQ
## File description:
## make the liball
##

NAME 		= 	libfile.a

HPREFIX 	= 	../../include/

SRC 		= 	check_perms.c 		\
			check_type.c 		\
			open_ronly.c 		\
			file_size.c 		\
			fs_get_content.c

OBJ 		= 	$(SRC:.c=.o)

CWFLAGS 	= 	-Wall -Wextra -Wpedantic

CFLAGS 		= 	$(CWFLAGS) -I$(HPREFIX)

# ----------------------------------------------------------------------------

$(NAME): 	$(OBJ)
	ar rc $(NAME) $(OBJ)

all: 		$(NAME)

re: 		fclean all

clean:
	rm -f *.swp

fclean: 	clean
	rm -f *.o
	rm -f $(NAME)
