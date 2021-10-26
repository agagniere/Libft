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
TEST_PATH   := test

# Files
TARGET_STATIC = libft.a
TARGET_SHARED = libft.so
FILES         = $(shell find $(SOURCE_PATH) -name '*.c')
OBJECTS       = $(subst $(SOURCE_PATH),$(CACHE_PATH),$(FILES:.c=.o))
DEPFILES      = $(OBJECTS:.o=.d)

# Compiler
CC ?= gcc
CPPFLAGS += -Wall -Wextra -fPIC -O2 -g
CPPFLAGS += -I $(HEADER_PATH)

# ========== Conan ==========
CONAN_BUILD_INFO = conanbuildinfo.mak

include $(wildcard $(CONAN_BUILD_INFO))

CFLAGS   += $(CONAN_CFLAGS)
CPPFLAGS += $(addprefix -I, $(CONAN_INCLUDE_DIRS))
CPPFLAGS += $(addprefix -D, $(CONAN_DEFINES))
LDFLAGS  += $(addprefix -L, $(CONAN_LIB_DIRS))
LDLIBS   += $(addprefix -l, $(CONAN_LIBS))
# ===========================

static: $(TARGET_STATIC)

shared: $(TARGET_SHARED)

all: static shared

include $(wildcard $(DEP))

test: $(TARGET_STATIC) $(TEST_PATH)/main.c
	@$(MAKE) -C $(TEST_PATH) $@

$(TEST_PATH)/main.c:
	@(cd $(@D) && bash generate.sh)

$(TARGET_STATIC): $(OBJECTS)
	$(AR) rcs $@ $^

$(TARGET_SHARED): $(OBJECTS)
	$(CC) -shared $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(CACHE_PATH)/%.o: $(SOURCE_PATH)/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) -MMD -c -o $@ $<

clean:
	$(RM) -r $(CACHE_PATH)
	@$(MAKE) -C test $@

fclean: clean
	$(RM) $(TARGET_STATIC) $(TARGET_SHARED)
	@$(MAKE) -C test $@

.PHONY: static shared all test clean fclean
