EXEC=test_libft.exe

LIBUNIT_PATH=framework
LIBUNIT=$(LIBUNIT_PATH)/libunit.a
LIBFT_PATH=..
LIBFT=$(LIBFT_PATH)/libft.a

FILES=$(shell find . -name '*.c')
OBJ=$(FILES:.c=.o)

CPPFLAGS+=-Wall -Wextra -O2 -g
CPPFLAGS+=-I$(LIBUNIT_PATH) -I$(LIBFT_PATH)/include

all: $(EXEC)

re: fclean all

test:
	./$(EXEC)

$(EXEC): $(OBJ) | $(LIBUNIT) $(LIBFT)
	$(CC) $^ -L$(LIBUNIT_PATH) -L$(LIBFT_PATH) -lunit -lft -o $@

%.a:
	@$(MAKE) -C $(@D)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(EXEC)

.PHONY: all re test clean fclean
