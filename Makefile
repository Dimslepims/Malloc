##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile shared library
##

SOURCE	=	malloc.c        \
			calloc.c    \
			free.c           \
			tools.c         \
			realloc.c         \

INC_PATH=include

SRC =	$(SOURCE)

OBJS = $(SRC:.c=.o)

CFLAGS += -fPIC -Wall -Wextra -Werror -I $(INC_PATH)

RM = rm -f

NAME = libmy_malloc.so

all: $(NAME)

$(NAME): $(OBJS)
	@gcc -fPIC -shared -o $(NAME) $(OBJS)
	@echo -e "\n\033[01;38;5;10mCompiling : Done\033[0;0m"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:    fclean all

.PHONY: all clean fclean re