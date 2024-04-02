##
## EPITECH PROJECT, 2023
## makefile
## File description:
## libmy
##

CFLAGS = -W -Wall -Wextra -Werror

CPPFLAGS = -I../../include

SRC = $(wildcard my/*.c flags/*.c handlers/*.c)

OBJ = $(SRC:.c=.o)

LIB = libmy.a

all: $(LIB)

$(LIB) :    $(OBJ)
	@$(AR) rc $(LIB) $(OBJ)
	@cp $(LIB) ../

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(LIB)
	@$(RM) ../$(LIB)

re: fclean all
