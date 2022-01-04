##
## EPITECH PROJECT, 2021
## LIBMY
## File description:
## make the libmy
##

# COLOUR
CYAN		=	'\033[0;36m'
GREEN 		= 	'\033[0;32m'
RESET		=	'\033[0m'

# CURRENT RULE
CURR_RULE	=	all

# TARGET
TARGET		=	libmy.a

SRCDIR		=	.

VPATH		=	$(SRCDIR) $(OBJDIR) include/

SRC		=	$(shell find $(SRCDIR) -name '*.c')

OBJ		:=	$(SRC:%.c=%.o)

CFLAGS		=	-I../../include -Wall -Wextra -Wpedantic

# ----------------------------------------------------------------------------

%.o: %.c
	@$(CC)     $(CFLAGS)     $^ -c -o $@

.PHONY: all
all:	CURR_RULE = all
all:	init $(TARGET) ## Call $(TARGET)
	@echo -e $(GREEN)[finished]: $(TARGET): make $(CURR_RULE)$(RESET)

$(TARGET):	CURR_RULE = $(TARGET)
$(TARGET):	init $(OBJ) ## Build the lib
	@ar rc $(TARGET) $(OBJ)
	@echo -e $(GREEN)[finished]: $(TARGET): make $(CURR_RULE)$(RESET)

init:
	@echo -e $(CYAN)[starting]: $(TARGET): make $(CURR_RULE) ...$(RESET)

.PHONY: clean
clean: ## Clean obj/*.o
	@rm -f $(OBJ)

.PHONY: fclean
fclean: CURR_RULE = fclean
fclean:	init clean ## Clean the binary
	@rm -f $(TARGET)
	@echo -e $(GREEN)[finished]: $(TARGET): make $(CURR_RULE)$(RESET)

.PHONY: re
re:	fclean all ## Fclean+All
