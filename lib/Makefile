##
## EPITECH PROJECT, 2021
## MYSCREENSAVER
## File description:
## make teh liball
##

# COLOUR
CYAN		=	'\033[0;36m'
GREEN 		= 	'\033[0;32m'
RESET		=	'\033[0m'

# NAME
NAME 	= 	liball.a

GPREFIX = 	graphics/

MPREFIX = 	my/

BPREFIX = 	bitmap/

FPREFIX = 	file/

# ----------------------------------------------------------------------------

$(NAME): 	build_libmy build_libgraphics build_libfile build_bitmap
	@ar rcT $(NAME) $(GPREFIX)libgraph.a $(MPREFIX)libmy.a \
		$(BPREFIX)libmap.a $(FPREFIX)libfile.a
	@echo -e $(GREEN)[finished]: $(NAME): make $(NAME)$(RESET)

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
	@rm -rf $(NAME)
	@make -C $(GPREFIX) fclean -s
	@make -C $(MPREFIX) fclean -s
	@make -C $(FPREFIX) fclean -s
	@make -C $(BPREFIX) fclean -s
	@echo -e $(GREEN)[finished]: $(NAME): make fclean$(RESET)

re: 	fclean all
