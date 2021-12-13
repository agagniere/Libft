# Files
NAME  = libunit.a
FILES = libunit.c comparisons.c
OBJ   = ${FILES:.c=.o}

# Compiler
CC     ?= gcc
CFLAGS += -Wall -Wextra


all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean
