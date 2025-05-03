#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 17:38:00 by angagnie          #+#    #+#              #
#    Updated: 2021/10/26 21:31:00 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Folders
SOURCE_PATH := src
CACHE_PATH  := cache
HEADER_PATH := include

# Files
TARGET_STATIC = libft.a
TARGET_SHARED = libft.so
FILES         = $(shell find $(SOURCE_PATH) -name '*.c')
OBJECTS       = $(subst $(SOURCE_PATH),$(CACHE_PATH),$(FILES:.c=.o))
DEPFILES      = $(OBJECTS:.o=.d)

# Compiler
CFLAGS   += --std=gnu99 -Wall -Wextra
CPPFLAGS += -I $(HEADER_PATH)
CPPFLAGS += -Wno-unused-result -Wformat=2
CPPFLAGS += -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition

static: $(TARGET_STATIC)

shared: $(TARGET_SHARED)

all: static shared

include $(wildcard $(DEPFILES))

$(TARGET_STATIC): $(OBJECTS)
	$(AR) rcs $@ $^

$(TARGET_SHARED): $(OBJECTS)
	$(CC) -shared $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(CACHE_PATH)/%.o: $(SOURCE_PATH)/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -c $< -o $@

clean:
	$(RM) -r $(CACHE_PATH)

fclean: clean
	$(RM) $(TARGET_STATIC) $(TARGET_SHARED)

.PHONY: static shared all clean fclean

local:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) fclean -C test
	@$(MAKE) fclean -C test/framework
	@CFLAGS="-g -O2" $(MAKE) --no-print-directory -j8
	@CFLAGS="-g -O2" CPPFLAGS="-I ../../include" $(MAKE) -C test/framework
	@CFLAGS="-g -O2" CPPFLAGS="-I ../include -I framework" LDFLAGS="-L .. -L framework" LDLIBS="-lunit -lft" $(MAKE) -C test -j8
