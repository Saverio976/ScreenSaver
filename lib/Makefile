##
## EPITECH PROJECT, 2021
## MYSCREENSAVER
## File description:
## make teh liball
##

NAME 	= 	liball.a

GPREFIX = 	graphics/

MPREFIX = 	my/

BPREFIX = 	bitmap/

FPREFIX = 	file/

# ----------------------------------------------------------------------------

$(NAME): 	build_libmy build_libgraphics build_libfile build_bitmap
	ar rcT $(NAME) $(GPREFIX)libgraph.a $(MPREFIX)libmy.a \
		$(BPREFIX)libmap.a $(FPREFIX)libfile.a

all: 	$(NAME)

build_libmy:
	make -C $(MPREFIX)

build_libgraphics:
	make -C $(GPREFIX)

build_libfile:
	make -C $(FPREFIX)

build_bitmap:
	make -C $(BPREFIX)

clean:
	rm -rf *.swp

fclean: clean
	rm -rf $(NAME)
	make -C $(GPREFIX) fclean
	make -C $(MPREFIX) fclean
	make -C $(FPREFIX) fclean
	make -C $(BPREFIX) fclean

re: 	fclean all
