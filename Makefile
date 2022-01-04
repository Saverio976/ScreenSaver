##
## EPITECH PROJECT, 2021
## sample
## File description:
## sample description
##

# COLOUR
CYAN		=	'\033[0;36m'
GREEN 		= 	'\033[0;32m'
RESET		=	'\033[0m'

# TARGET
TARGET		=	my_screensaver

LIB_TARGET	=	lib/liball.a

TARGET_TEST	=	bin_test

SRCDIR		=	src/

VPATH		=	$(SRCDIR) lib/ include/ tests/

SRC		:=	$(shell find $(SRCDIR) -name '*.c')
SRC		:=	$(filter-out $(SRCDIR)main.c, $(SRC))
OBJ		:=	$(SRC:%.c=%.o)

MAIN_SRC	=	$(SRCDIR)main.c
MAIN_OBJ	:=	$(MAIN_SRC:%.c=%.o)

CFLAGS		= 	-Iinclude/ -Ilib/include/ -Wall -Wextra -Wpedantic

LFLAGS		=	-Llib/ -lall -lcsfml-graphics -lcsfml-system -lm

# ----------------------------------------------------------------------------

%.o: %.c
	@$(CC)     $(CFLAGS)    $^ -c -o $@
#@echo -e $(CYAN)'compil : $(notdir $^) -> $(notdir $@)'$(RESET)

.PHONY: all
all:	$(LIB_TARGET) $(TARGET) ## Build lib+binary

$(TARGET):	$(OBJ) $(MAIN_OBJ) ## Build the binary
	@$(CC) $(OBJ) $(MAIN_OBJ) -o $(TARGET) $(LFLAGS) $(CFLAGS)
	@echo -e $(GREEN)[finished]: $(TARGET): make $(TARGET)$(RESET)

$(LIB_TARGET): ## Build the lib
	@$(MAKE) -C lib/ -s

.PHONY: clean
clean: ## Clean obj and gcno/gcda
	@rm -f $(OBJ) $(MAIN_OBJ)
	@rm -f $(shell find . -name 'vgcore.*')
	@rm -f $(shell find . -name '*.gcno') $(shell find . -name '*.gcda')

.PHONY: fclean
fclean:	clean ## Clean+Remove target/target_test and call lib fclean
	@$(MAKE) -C lib/ fclean -s
	@rm -f $(TARGET) $(TARGET_TEST)
	@echo -e $(GREEN)[finished]: $(TARGET): make fclean$(RESET)

.PHONY: re
re:	fclean all ## Fclean+All
