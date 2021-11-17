##
## EPITECH PROJECT, 2021
## MYSCREENSAVER
## File description:
## make teh liball
##

NAME 	= 	liball.a

GPREFIX = 	graphics/

MPREFIX = 	my/

# ----------------------------------------------------------------------------

$(NAME): 	build_libmy build_libgraphics
	ar rcT $(NAME) $(GPREFIX)libgraph.a $(MPREFIX)libmy.a

all: 	$(NAME)

build_libmy:
	make -C $(MPREFIX)

build_libgraphics:
	make -C $(GPREFIX)

clean:
	rm -rf *.swp

fclean: clean
	rm -rf $(NAME)
	make -C $(GPREFIX) fclean
	make -C $(MPREFIX) fclean

re: 	fclean all
