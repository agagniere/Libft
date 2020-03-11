FILE=libunit.c comparisons.c
NAME=libunit.a
LIBFT_PATH=../..

CPPFLAGS+=-I $(LIBFT_PATH)/include
CPPFLAGS+=-Wall -Wextra -O2 -g

OBJ=${FILE:.c=.o}

all: $(NAME)

re: fclean all

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

.PHONY: all re clean fclean
