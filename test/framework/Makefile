FILE=libunit.c
NAME=libunit.a
LIBFT_PATH=../..

CPPFLAGS+=-I $(LIBFT_PATH)/include
CPPFLAGS+=-Wall -Wextra

OBJ=${FILE:.c=.o}

all: $(NAME)

re: fclean all

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

clean:
	$(RM) $(OBJECT)

fclean: clean
	$(RM) $(NAME)

.PHONY: all re clean fclean
