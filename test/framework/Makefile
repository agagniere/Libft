# Files
NAME  = libunit.a
FILES = libunit.c comparisons.c
OBJ   = ${FILES:.c=.o}

# Compiler
CFLAGS   += --std=c99 -Wall -Wextra
CPPFLAGS += -Wno-unused-result -Wformat=2
CPPFLAGS += -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean
