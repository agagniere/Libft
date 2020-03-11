FILE=libunit.c
NAME=libunit.a
LIBFT_PATH=../..

CPPFLAGS+=-I $(LIBFT_PATH)/include
CPPFLAGS+=-Wall -Wextra -Werror

OBJ=${FILE:.c=.o}

all: $(NAME)

re: fclean all

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

$(OBJECT): $(FILE)

clean:
	$(RM) $(OBJECT)

fclean: clean
	$(RM) $(NAME)

.PHONY: all re clean fclean
