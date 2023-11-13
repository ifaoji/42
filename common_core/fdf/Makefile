CC = clang-12
COMPILER_FLAGS = -Wall -Wextra -Werror -g
# -gdwarf-4 -g
LIBS = -lXext -lX11 -lm -lz -lmlx
RM = rm -rf
MKDIR = mkdir -p
ARCHIVE = ar rcs

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
NC := \033[0m # No color

LIBFT_DIR := lib/libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_MAKE := $(MAKE) -C $(LIBFT_DIR) --no-print-directory

RAW_SRC :=	args \
			args2 \
			close \
			dimensions \
			draw_line \
			handle_key \
			handle_mouse \
			img \
			main \
			pm2a \
			point \
			project \
			render \
			render_text \
			rgb \
			rotate \
			scale \
			set_pixel \
			translate

RAW_BONUS_SRC :=

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

NAME = fdf
# BONUS_NAME = checker
INC = inc
HEADER = fdf.h
# BONUS_HEADER = push_swap_bonus.h

.PHONY: all bonus clean fclean libft re

all: $(LIBFT) $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)Deleted objects$(NC)\n"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS_NAME)
	@$(LIBFT_MAKE) fclean
	@printf "$(RED)Deleted $(NAME)$(NC)\n"

$(LIBFT):
	@$(LIBFT_MAKE)

re:
	@printf "$(YELLOW)Rebuilding...$(NC)\n"
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)/$(HEADER) | $(OBJ_DIRS)
	@printf "\r\033[K"
	@printf "$(YELLOW)Compiling $(GREEN)$$(($(COUNT) * 100 / $(TOTAL_FILES)))%%$(NC) - $<\r"
	@$(CC) $(COMPILER_FLAGS) -I$(INC) -c $< -o $@
	@$(eval COUNT=$(shell echo $$(($(COUNT) + 1))))

$(NAME): $(LIBFT) $(OBJ) $(INC)/$(HEADER)
	@printf "\r\033[K"
	@printf "$(YELLOW)$(NAME)!\n"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(LIBS)
	@printf "$(GREEN)$(NAME) created.$(NC)\n"
	@printf "$(GREEN)$(NAME) done$(NC)\n"

bonus: $(NAME)

$(OBJ_DIRS):
	@mkdir -p $@
