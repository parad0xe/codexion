# structure
NAME = codexion
ARGS = 

# directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build
INCLUDE_DIR = includes

# compiler and flags
CC = cc
CFLAGS = -MMD -MP -pthread
MAKEFLAGS += -j $$(nproc)
INCLUDES = -I $(INCLUDE_DIR)

# tools
VALGRIND = valgrind --leak-check=full \
		   --show-leak-kinds=all \
		   --track-origins=yes -s --error-exitcode=1

# files
SRCS =\
	  $(SRC_DIR)/heapq/heapq_create.c\
	  $(SRC_DIR)/heapq/heapq_destroy.c\
	  $(SRC_DIR)/heapq/heapq_enqueue.c\
	  $(SRC_DIR)/heapq/heapq_dequeue.c\
	  $(SRC_DIR)/heapq/heapq_debug.c\
	  $(SRC_DIR)/heapq/heapq_peek.c\
	  $(SRC_DIR)/dongle/dongles_create.c\
	  $(SRC_DIR)/dongle/dongles_destroy.c\
	  $(SRC_DIR)/dongle/dongle_managers_create.c\
	  $(SRC_DIR)/dongle/dongle_managers_destroy.c\
	  $(SRC_DIR)/dongle/dongle_manager_pool_create.c\
	  $(SRC_DIR)/dongle/dongle_manager_pool_destroy.c\
	  $(SRC_DIR)/coder/coders_create.c\
	  $(SRC_DIR)/coder/coders_destroy.c\
	  $(SRC_DIR)/workspace/workspace_create.c\
	  $(SRC_DIR)/workspace/workspace_destroy.c\
	  $(SRC_DIR)/utils/absmod.c\
	  $(SRC_DIR)/main.c\

TEST_VERBOSE ?= 0
TEST_SRCS =\
		   $(TEST_DIR)/_core/test_utils.c

TESTS =\
	   $(TEST_DIR)/heapq/test_heapq_create.c\
	   $(TEST_DIR)/heapq/test_heapq_enqueue.c\
	   $(TEST_DIR)/heapq/test_heapq_dequeue.c\
	   $(TEST_DIR)/heapq/test_heapq_destroy.c\
	   $(TEST_DIR)/heapq/test_heapq_peek.c\
	   $(TEST_DIR)/dongle/test_dongles_create.c\
	   $(TEST_DIR)/dongle/test_dongles_destroy.c\
	   $(TEST_DIR)/dongle/test_dongle_managers_create.c\
	   $(TEST_DIR)/dongle/test_dongle_managers_destroy.c\
	   $(TEST_DIR)/dongle/test_dongle_manager_pool_create.c\
	   $(TEST_DIR)/dongle/test_dongle_manager_pool_destroy.c\
	   $(TEST_DIR)/coder/test_coders_create.c\
	   $(TEST_DIR)/coder/test_coders_destroy.c\
	   $(TEST_DIR)/workspace/test_workspace_create.c\
	   $(TEST_DIR)/workspace/test_workspace_destroy.c\

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

check: all
	$(VALGRIND) ./$(NAME)

build-debug:
	@$(MAKE) $(NAME) \
		CFLAGS="$(CFLAGS) -g3 -fsanitize=address" \
		--no-print-directory

debug: build-debug
	./$(NAME)

check-debug: build-debug
	$(VALGRIND) ./$(NAME)

tests:
	@$(MAKE) tests-run \
		CFLAGS="$(CFLAGS) -g3" \
		SRCS="$(SRCS) $(TEST_SRCS)" \
		INCLUDES="$(INCLUDES) -I tests/_core" \
		--no-print-directory

check-tests:
	@$(MAKE) check-tests-run \
		CFLAGS="$(CFLAGS) -g3" \
		SRCS="$(SRCS) $(TEST_SRCS)" \
		INCLUDES="$(INCLUDES) -I tests/_core" \
		--no-print-directory

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all check build-debug debug check-debug tests check-tests clean fclean re

else

tests-run: $(TEST_BINS)
	@failed=0; \
	for test in $(TEST_BINS); do \
		name=$$(basename $$test .bin); \
		printf "\033[1;36m▶ running test:\033[0m \033[1;35m$$name\033[0m\n"; \
		out=$$(./$$test); \
		res=$$(echo $$?); \
		if [ "$(TEST_VERBOSE)" = "1" ]; then \
			printf "%s\n" "$$out"; \
		fi; \
		if [ $$res -eq 0 ]; then \
			printf "\033[1;32m✔ success\033[0m\n\n"; \
		else \
			printf "\033[1;31m✖ failure in $$name\033[0m\n\n"; \
			failed=1; \
		fi; \
	done; \
	if [ $$failed -eq 0 ]; then \
		printf "\033[1;32m✔ all tests passed successfully\033[0m\n"; \
	else \
		printf "\033[1;31m✖ some tests failed\033[0m\n"; \
		exit 1; \
	fi

check-tests-run: $(TEST_BINS)
	@failed=0; \
	for test in $(TEST_BINS); do \
		name=$$(basename $$test .bin); \
		printf "\033[1;36m▶ checking memory:\033[0m \033[1;35m$$name\033[0m\n"; \
		out=$$($(VALGRIND) ./$$test 2>&1 >/dev/null); \
		if [ $$? -eq 0 ]; then \
			printf "\033[1;32m✔ memory ok\033[0m\n\n"; \
		else \
			printf "\033[0;33m%s\033[0m\n" "$$out"; \
			printf "\033[1;31m✖ memory error in $$name\033[0m\n\n"; \
			failed=1; \
		fi; \
	done; \
	if [ $$failed -eq 0 ]; then \
		printf "\033[1;32m✔ all memory checks passed\033[0m\n"; \
	else \
		printf "\033[1;31m✖ some memory checks failed\033[0m\n"; \
		exit 1; \
	fi

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
