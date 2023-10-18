CC = clang
COMPILER_FLAGS = -Wall -Wextra -Werror
RM = rm -rf
MKDIR = mkdir -p
ARCHIVE = ar rcs

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
NC := \033[0m # No color

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_MAKE := $(MAKE) -C $(LIBFT_DIR) --no-print-directory

RAW_SRC :=	args \
			biggest_smallest \
			calculate_distance create_stack \
			final_rotate free \
			is_sorted \
			main merge min moves_for moves_to_top move_unsorted \
			panic push \
			reverse_rotate \
			rotate \
			sort_5 stack_size swap

RAW_BONUS_SRC :=	bonus_main \
					args \
					create_stack \
					free \
					is_sorted \
					panic push \
					reverse_rotate \
					rotate \
					swap

SRC_DIR = src
OBJ_DIR = obj

SRC = $(RAW_SRC:%=$(SRC_DIR)/%.c)
OBJ = $(RAW_SRC:%=$(OBJ_DIR)/%.o)

BONUS_SRC := $(RAW_BONUS_SRC:%=$(SRC_DIR)/%.c)
BONUS_OBJ := $(RAW_BONUS_SRC:%=$(OBJ_DIR)/%.o)

OBJ_DIRS := $(sort $(dir $(OBJ)))

COUNT = 1
TOTAL_FILES := $(words $(RAW_SRC))
TOTAL_BONUS_FILES := $(words $(RAW_BONUS_SRC))

NAME = push_swap
BONUS_NAME = checker
INC = inc
HEADER = push_swap.h
BONUS_HEADER = push_swap_bonus.h

# .SILENT:

.PHONY: all bonus clean fclean libft re

all: $(LIBFT) $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)Deleted objects$(NC)\n"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS_NAME)
	@$(LIBFT_MAKE) fclean
	@printf "$(RED)Deleted $(NAME) & $(BONUS_NAME)$(NC)\n"

$(LIBFT):
	@$(LIBFT_MAKE)

re:
	@printf "$(YELLOW)Rebuilding...$(NC)\n"
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIRS)
	@printf "\r\033[K"
	@printf "$(YELLOW)Compiling $(GREEN)$$(($(COUNT) * 100 / $(TOTAL_FILES)))%%$(NC) - $<\r"
	@$(CC) $(COMPILER_FLAGS) -I$(INC) -c $< -o $@
	@$(eval COUNT=$(shell echo $$(($(COUNT) + 1))))

$(NAME): $(LIBFT) $(OBJ) $(INC)/$(HEADER)
	@printf "\r\033[K"
	@printf "$(YELLOW)$(NAME)!\n"
	@$(CC) $(CFLAGS) -L$(LIBFT_DIR) $(OBJ) -o $(NAME) -lft
	@printf "$(GREEN)$(NAME) created.$(NC)\n"
	@printf "$(GREEN)$(NAME) done$(NC)\n"

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJ) $(INC)/$(BONUS_HEADER) | $(OBJ_DIR)
	@printf "\r\033[K"
	@printf "$(YELLOW)BONUS!\n"
	@$(CC) $(CFLAGS) -L$(LIBFT_DIR) $(BONUS_OBJ) -o $(BONUS_NAME) -lft
	@printf "$(GREEN)$(BONUS_NAME) created.$(NC)\n"
	@printf "$(GREEN)bonus done$(NC)\n"

$(OBJ_DIRS):
	@mkdir -p $@
