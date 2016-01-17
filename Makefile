#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 17:38:00 by angagnie          #+#    #+#              #
#    Updated: 2016/01/13 13:52:07 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# ==== Editable ====
NAME:=libft.a

CTYPEPATH:=ft_ctype/
CTYPE:=ft_isalnum ft_isalpha ft_isascii ft_isblank ft_iscntrl ft_isdigit \
	ft_isgraph ft_islower ft_isprint ft_ispunct ft_isspace ft_isupper \
	ft_isxdigit ft_tolower ft_toupper

VECTORPATH:=ft_vector/
VECTOR:=ft_dyna_alloc ft_dyna_append ft_dyna_dataclear ft_dyna_dataclearf \
	ft_dyna_datainit ft_dyna_del ft_dyna_new ft_dyna_popback ft_dyna_popbackf \
	ft_dyna_release ft_dyna_reserve ft_dyna_trim ft_dyna_iter ft_dyna_iteri

STRPATH:=ft_string/
STR:=ft_strcat ft_strchr ft_strrchr ft_strcmp ft_strcpy ft_strdup ft_strjoin \
	ft_strlcat ft_strlen ft_strncat ft_strncmp ft_strncpy ft_strnew ft_strnstr \
	ft_strstr ft_strdel ft_strtrim ft_strsub ft_strsplit ft_strclr ft_strequ \
	ft_striter ft_striter ft_strmap ft_striteri ft_strmapi ft_strnequ

LSTPATH:=ft_list/
LST:=ftl_new ftl_add ftl_pop

MATHPATH:=ft_math/
MATH:=

FILES:=ft_atoi ft_bzero ft_itoa ft_itoa_base ft_memalloc ft_memccpy ft_memchr \
	ft_memdel ft_memcmp ft_memcpy ft_memmove ft_memset ft_putchar \
	ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr \
	ft_putstr_fd ft_realloc ft_print_memory \
# ==================

# ==== Standard ====
CC:=clang
CCHPATH:=cache/
SRCPATH:=src/
HDRPATH:=include/
CFLAGS:=-Wall -Wextra -I $(HDRPATH)
# ==================

# ===== Colors =====
END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
# ==================

# ====== Auto ======
FILES+=$(addprefix $(CTYPEPATH),$(CTYPE))
FILES+=$(addprefix $(VECTORPATH),$(VECTOR))
FILES+=$(addprefix $(STRPATH),$(STR))
FILES+=$(addprefix $(LSTPATH),$(LST))
FILES+=$(addprefix $(MATHPATH),$(MATH))

SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN) " - Done" $(END)

$(CCHPATH)%.o: $(SRCPATH)%.c $(CCHF)
	@echo $(PURPLE) " - Compiling $< into $@" $(RED)
	@$(CC) $(CFLAGS) -c $< -o $@ 2>&1 | tail -1

%.c:
	@echo $(RED) "Missing file : $@"

$(CCHF):
	@mkdir $(CCHPATH)
	@mkdir $(CCHPATH)$(VECTORPATH)
	@mkdir $(CCHPATH)$(CTYPEPATH)
	@mkdir $(CCHPATH)$(STRPATH)
	@mkdir $(CCHPATH)$(LSTPATH)
	@mkdir $(CCHPATH)$(MATHPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test:
	@echo "Files :" $(FILES)

norme:
	@echo $(RED)
	@norminette $(SRC) $(HDRPATH) | grep -v  Norme -B1 || true
	@echo $(END)

.PHONY: all clean fclean re test norme
