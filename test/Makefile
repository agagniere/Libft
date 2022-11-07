# Files
EXEC  = test_libft.exe
FILES = $(shell find . dict heap -maxdepth 1 -name '*.c')
OBJ   = $(FILES:.c=.o)

# Compiler
CC       ?= gcc
CFLAGS   += -Wall -Wextra -g
CPPFLAGS += -I . -D_GNU_SOURCE

# ========== Conan ==========
CONAN_BUILD_INFO = conanbuildinfo.mak
include $(wildcard $(CONAN_BUILD_INFO))
CFLAGS   += $(CONAN_CFLAGS)
CPPFLAGS += $(addprefix -I, $(CONAN_INCLUDE_DIRS))
CPPFLAGS += $(addprefix -D, $(CONAN_DEFINES))
LDFLAGS  += $(addprefix -L, $(CONAN_LIB_DIRS))
LDLIBS   += $(addprefix -l, $(CONAN_LIBS))
# ===========================

build: $(EXEC)

fbuild: fclean
	@$(MAKE) build --no-print-directory

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@

test_print%.o: test_print%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -Wno-format -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(EXEC)

.PHONY: all clean fclean
