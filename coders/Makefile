# structure
NAME = codexion
ARGS ?= 

# directories
SRC_DIR = src
LIB_DIR = lib
TEST_DIR = tests
BUILD_DIR = build

# compiler and flags
CC = cc
CFLAGS = -MMD -MP -pthread
MAKEFLAGS += -j $$(nproc)
INCLUDES = -I include -I lib/heapq/include

# tools
VALGRIND = valgrind --leak-check=full \
		   --show-leak-kinds=all \
		   --track-origins=yes -s --error-exitcode=1

# files
SRCS =\
	  $(LIB_DIR)/heapq/src/heapq_lifecycle_create.c\
	  $(LIB_DIR)/heapq/src/heapq_lifecycle_destroy.c\
	  $(LIB_DIR)/heapq/src/heapq_action_enqueue.c\
	  $(LIB_DIR)/heapq/src/heapq_action_dequeue.c\
	  $(LIB_DIR)/heapq/src/heapq_action_peek.c\
	  $(LIB_DIR)/heapq/src/heapq_debug.c\
	  $(SRC_DIR)/dongle/dongle_lifecycle_create.c\
	  $(SRC_DIR)/dongle/dongle_lifecycle_destroy.c\
	  $(SRC_DIR)/dongle/dongle_action_wait.c\
	  $(SRC_DIR)/dongle/dongle_action_acquire.c\
	  $(SRC_DIR)/dongle/dongle_action_release.c\
	  $(SRC_DIR)/dongle/dongle_state_usage.c\
	  $(SRC_DIR)/coder/coder_lifecycle_create.c\
	  $(SRC_DIR)/coder/coder_lifecycle_destroy.c\
	  $(SRC_DIR)/coder/coder_lifecycle_routine.c\
	  $(SRC_DIR)/coder/coder_dongles_wait.c\
	  $(SRC_DIR)/coder/coder_dongles_release.c\
	  $(SRC_DIR)/coder/coder_dongles_acquire.c\
	  $(SRC_DIR)/coder/coder_action_sync.c\
	  $(SRC_DIR)/coder/coder_action_die.c\
	  $(SRC_DIR)/coder/coder_action_compile.c\
	  $(SRC_DIR)/coder/coder_action_debug.c\
	  $(SRC_DIR)/coder/coder_action_refactor.c\
	  $(SRC_DIR)/coder/coder_state_burnout.c\
	  $(SRC_DIR)/coder/coder_state_priority.c\
	  $(SRC_DIR)/coder/coder_state_running.c\
	  $(SRC_DIR)/workspace/workspace_lifecycle_create.c\
	  $(SRC_DIR)/workspace/workspace_lifecycle_destroy.c\
	  $(SRC_DIR)/workspace/workspace_lifecycle_monitor.c\
	  $(SRC_DIR)/workspace/workspace_thread_start.c\
	  $(SRC_DIR)/workspace/workspace_thread_join.c\
	  $(SRC_DIR)/utils/util_time.c\
	  $(SRC_DIR)/utils/util_math.c\
	  $(SRC_DIR)/main.c\

TEST_VERBOSE ?= 0
TEST_SRCS =\
		   $(TEST_DIR)/_core/asserts/assert_null.c\
		   $(TEST_DIR)/_core/test_util.c\

TESTS =\
	   $(TEST_DIR)/heapq/test_heapq_lifecycle_create.c\
	   $(TEST_DIR)/heapq/test_heapq_lifecycle_destroy.c\
	   $(TEST_DIR)/heapq/test_heapq_action_enqueue.c\
	   $(TEST_DIR)/heapq/test_heapq_action_dequeue.c\
	   $(TEST_DIR)/heapq/test_heapq_action_peek.c\
	   $(TEST_DIR)/dongle/test_dongle_lifecycle_create.c\
	   $(TEST_DIR)/dongle/test_dongle_lifecycle_destroy.c\
	   $(TEST_DIR)/coder/test_coder_lifecycle_create.c\
	   $(TEST_DIR)/coder/test_coder_lifecycle_destroy.c\
	   $(TEST_DIR)/workspace/test_workspace_lifecycle_create.c\
	   $(TEST_DIR)/workspace/test_workspace_lifecycle_destroy.c\

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

define switch_build_mode
	@if [ -f $(BUILD_DIR)/.flag_$(1) ]; then \
		printf "\033[1;33m⚠ Switching build mode. Cleaning up...\033[0m\n"; \
		rm -rf $(BUILD_DIR); \
	fi
	@mkdir -p $(BUILD_DIR)
	@touch $(BUILD_DIR)/.flag_$(2)
endef

# rules
ifeq ($(MAKELEVEL),0)

all $(NAME) &:
	$(call switch_build_mode,debug,prod)
	@$(MAKE) $(NAME) \
		CFLAGS="$(CFLAGS) -Wall -Wextra -Werror" \
		--no-print-directory

check: all
	$(VALGRIND) ./$(NAME) $(ARGS)

build-debug:
	$(call switch_build_mode,prod,debug)
	@$(MAKE) $(NAME) \
		CFLAGS="$(CFLAGS) -g3" \
		--no-print-directory

debug: build-debug
	./$(NAME) $(ARGS)

check-debug: build-debug
	$(VALGRIND) ./$(NAME) $(ARGS)

tests:
	$(call switch_build_mode,prod,debug)
	@$(MAKE) tests-run \
		CFLAGS="$(CFLAGS) -g3" \
		SRCS="$(SRCS) $(TEST_SRCS)" \
		INCLUDES="$(INCLUDES) -I tests/_core" \
		--no-print-directory

check-tests:
	$(call switch_build_mode,prod,debug)
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
			if [ "$(TEST_VERBOSE)" != "1" ]; then \
				printf "%s\n" "$$out"; \
			fi; \
			printf "\033[1;31m✖ failure in $$name\033[0m\n\n"; \
			failed=$$((failed + 1)); \
		fi; \
	done; \
	if [ $$failed -eq 0 ]; then \
		printf "\033[1;32m✔ all tests passed successfully\033[0m\n"; \
	else \
		printf "\033[1;31m✖ $$failed test(s) failed\033[0m\n"; \
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
			failed=$$((failed + 1)); \
		fi; \
	done; \
	if [ $$failed -eq 0 ]; then \
		printf "\033[1;32m✔ all memory checks passed\033[0m\n"; \
	else \
		printf "\033[1;31m✖ $$failed memory checks failed\033[0m\n"; \
		exit 1; \
	fi

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.o $(CORE_OBJS)
	$(CC) -o $@ $< $(CORE_OBJS)

.PHONY: tests-run check-tests-run
.PRECIOUS: $(BUILD_DIR)/%.o

endif

-include $(DEPS) $(TEST_DEPS)
