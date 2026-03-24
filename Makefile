# structure
NAME = codexion

SRC_DIR = coders
BUILD_DIR = build

# flags
CC = cc
CFLAGS = -MMD -MP -pthread
MAKEFLAGS += -j $$(nproc)
INCLUDES = 

# files
SRCS =\
		coders/codexion.c\

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

# rules
ifeq ($(MAKELEVEL),0)

.PHONY: all
all $(NAME) &:
	@$(MAKE) $(NAME) CFLAGS="$(CFLAGS) -Wall -Wextra -Werror" --no-print-directory

.PHONY: clean
clean:
	rm -rf $(BUILD)

.PHONY: debug
debug:
	@$(MAKE) $(NAME) --no-print-directory


.PHONY: fclean
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

.PHONY: re
re: fclean all

else

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

endif

# miscellaneous
-include $(DEPS)
