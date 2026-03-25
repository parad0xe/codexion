# structure
NAME = codexion
ARGS = 

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build
INCLUDE_DIR = includes

# Compiler and flags
CC = cc
CFLAGS = -MMD -MP -pthread
MAKEFLAGS += -j $$(nproc)
INCLUDES = -I $(INCLUDE_DIR)

# tools
VALGRIND = valgrind --leak-check=full \
		   --show-leak-kinds=all \
		   --track-origins=yes

# files
SRCS =\
	  $(SRC_DIR)/coders.c\
	  $(SRC_DIR)/monitor.c\
	  $(SRC_DIR)/dongle.c\
	  $(SRC_DIR)/utils.c\
	  $(SRC_DIR)/heapq/heapq_create.c\
	  $(SRC_DIR)/heapq/heapq_destroy.c\
	  $(SRC_DIR)/heapq/heapq_enqueue.c\
	  $(SRC_DIR)/heapq/heapq_dequeue.c\
	  $(SRC_DIR)/heapq/heapq_debug.c\
	  $(SRC_DIR)/main.c\

TESTS =\
	   $(TEST_DIR)/heapq/test_heapq_create.c\
	   $(TEST_DIR)/heapq/test_heapq_enqueue.c\
	   $(TEST_DIR)/heapq/test_heapq_dequeue.c\
	   $(TEST_DIR)/heapq/test_heapq_destroy.c\

TEST_CORE =\
		   $(TEST_DIR)/_core/test_utils.c

# main objects
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

# core objects
CORE_SRCS = $(filter-out $(SRC_DIR)/main.c, $(SRCS))
CORE_OBJS = $(CORE_SRCS:%.c=$(BUILD_DIR)/%.o)

# test objects
TEST_OBJS = $(TESTS:%.c=$(BUILD_DIR)/%.o)
TEST_BINS = $(TESTS:%.c=$(BUILD_DIR)/%.bin)
TEST_DEPS = $(TEST_OBJS:.o=.d)

# rules
ifeq ($(MAKELEVEL),0)

all $(NAME) &:
	@$(MAKE) $(NAME) \
		CFLAGS="$(CFLAGS) -Wall -Wextra -Werror" \
		--no-print-directory

build-debug:
	@$(MAKE) $(NAME) \
		CFLAGS="$(CFLAGS) -g3" \
		--no-print-directory

debug: build-debug
	./$(NAME)

check: build-debug
	$(VALGRIND) ./$(NAME)

tests:
	@$(MAKE) tests-run \
		CFLAGS="$(CFLAGS) -g3" \
		SRCS="$(SRCS) $(TEST_CORE)" \
		INCLUDES="$(INCLUDES) -I tests/_core" \
		--no-print-directory

check-tests:
	@$(MAKE) check-tests-run \
		CFLAGS="$(CFLAGS) -g3" \
		SRCS="$(SRCS) $(TEST_CORE)" \
		INCLUDES="$(INCLUDES) -I tests/_core" \
		--no-print-directory

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all build-debug debug check tests check-tests clean fclean re

else

tests-run: $(TEST_BINS)
	@for test in $(TEST_BINS); do \
		name=$$(basename $$test .bin); \
		printf "\033[1;34m▶ running test:\033[0m \033[1;37m$$name\033[0m\n"; \
		./$$test || exit 1; \
		printf "\033[1;32m✔ success\033[0m\n\n"; \
	done

check-tests-run: $(TEST_BINS)
	@for test in $(TEST_BINS); do \
		name=$$(basename $$test .bin); \
		printf "\033[1;33m▶ checking memory:\033[0m \033[1;37m$$name\033[0m\n"; \
		$(VALGRIND) ./$$test || exit 1; \
		printf "\033[1;32m✔ memory ok\033[0m\n\n"; \
	done

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.o $(CORE_OBJS)
	$(CC) -o $@ $< $(CORE_OBJS)

.PHONY: tests-run check-tests-run

endif

-include $(DEPS) $(TEST_DEPS)
