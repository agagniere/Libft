#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 17:38:00 by angagnie          #+#    #+#              #
#    Updated: 2018/12/12 20:12:58 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# ==== Editable ====
NAME:=libft.a

FILES=ft_atoi ft_bzero ft_itoa ft_itoa_base ft_memalloc ft_memccpy ft_memchr \
	ft_memdel ft_memcmp ft_memcpy ft_memmove ft_memset ft_memdup ft_putchar \
	ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr \
	ft_putstr_fd ft_realloc ft_print_memory ft_gnl ft_malloc ft_memswp \
	ft_string is_refresh

CTYPE_PATH:=ft_ctype/
CTYPE:=ft_isalnum ft_isalpha ft_isascii ft_isblank ft_iscntrl ft_isdigit \
	ft_isgraph ft_islower ft_isprint ft_ispunct ft_isspace ft_isupper \
	ft_isxdigit ft_tolower ft_toupper

STRL_PATH:=ft_string_legacy/
STRL:=ft_strcat ft_strchr ft_strrchr ft_strcmp ft_strcpy ft_strdup ft_strjoin \
	ft_strlcat ft_strlen ft_strncat ft_strncmp ft_strncpy ft_strnew ft_strnstr \
	ft_strstr ft_strdel ft_strtrim ft_strsub ft_strsplit ft_strclr ft_strequ \
	ft_striter ft_striter ft_strmap ft_striteri ft_strmapi ft_strnequ ft_strrev \
	wide_char

LIST_PATH:=ft_list/
LIST:=ftl_new ftl_add ftl_pop ftl_del

PRINTF_PATH:=ft_printf/
PRINTF:=ft_convert ft_convert_1 ft_convert_2 ft_convert_3 ft_convert_4 \
	ft_convert_5 ft_printf ft_vasprintf ft_vprintf db_printf

VECTOR_PATH:=ft_array/
VECTOR:=fta_alloc fta_append fta_new fta_reserve fta_resize fta_trim \
	fta_clear fta_clearf fta_popback fta_iter fta_iteri fta_popindex \
	fta_swap fta_overwrite fta_string fta_replace

DEQUE_PATH:=ft_deque/
DEQUE:=ftq_push ftq_pop ftq_getters ft_deque ftq_iter ftq_string ftq_is_sorted \
	ftq_private ftq_private_getters ftq_private_utils \
	ft_stack ft_stack_pushswap
# ==================

# ==== Standard ====
CC:=clang
CCHPATH:=cache/
SRCPATH:=src/
HDRPATH:=include/
CFLAGS:=-Wall -Wextra -I $(HDRPATH) -ansi
# ==================

# ===== Colors =====
EOC:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
# ==================

# ====== Auto ======
FOLDERS=$(CTYPE_PATH) $(STRL_PATH) $(LIST_PATH) $(PRINTF_PATH) $(VECTOR_PATH) $(DEQUE_PATH)
FILES+=$(addprefix $(CTYPE_PATH),$(CTYPE))
FILES+=$(addprefix $(STRL_PATH),$(STRL))
FILES+=$(addprefix $(LIST_PATH),$(LIST))
FILES+=$(addprefix $(PRINTF_PATH),$(PRINTF))
FILES+=$(addprefix $(VECTOR_PATH),$(VECTOR))
FILES+=$(addprefix $(DEQUE_PATH),$(DEQUE))

SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================

MAKEFLAGS+=-sj

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(EOC)
	@echo $(CYAN) " - Compiling $@" $(EOC)
	ar rcs $@ $^
	@echo $(GREEN) " - Done" $(EOC)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHPATH)
	@echo -n .
	$(CC) $(CFLAGS) -c $< -o $@

$(CCHPATH):
	mkdir -p $(addprefix $@/,$(FOLDERS))

clean:
	rm -rf $(CCHPATH)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

norm:
	@echo $(RED)
	norminette $(SRC) $(HDRPATH) | grep -v Norme -B1 || true
	@echo $(EOC)

.PHONY: all clean fclean re norm
