CC = clang
COMPILER_FLAGS = -Wall -Wextra -Werror
RM = rm -rf
MKDIR = mkdir -p
ARCHIVE = ar rcs

# ANSI colors
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
NC := \033[0m # No color

RAW_SRC_CHAR =	isalnum \
				isalpha \
				isascii \
				isdigit \
				isprint \
				isspace \
				tolower \
				toupper

RAW_SRC_CONV =	atoi \
				atoi_base \
				itoa

RAW_SRC_FILE =	gnl \
				gnl_cache

RAW_SRC_FLOAT =	max \
				min

RAW_SRC_INT =	max \
				min

RAW_SRC_LST = 	lstadd_back \
				lstadd_front \
				lstclear \
				lstdelone \
				lstiter \
				lstlast \
				lstmap \
				lstnew \
				lstsize

RAW_SRC_MEM = 	bzero \
				calloc \
				free_matrix \
				realloc \
				memchr \
				memcmp \
				memcpy \
				memmove \
				memset

RAW_SRC_PUT =	dprintf \
				putbase_fd \
				putchar_fd \
				putendl_fd \
				putnbr_fd \
				putstr_fd \
				putunbr_fd

RAW_SRC_STR =	free_stra \
				split \
				strchr \
				strdup \
				strndup \
				striteri \
				strjoin \
				strlcat \
				strlcpy \
				strlen \
				strmapi \
				strncmp \
				strnstr \
				strrchr \
				strtrim \
				substr

RAW_SRC =	$(RAW_SRC_CHAR:%=char/%) \
			$(RAW_SRC_CONV:%=conv/%) \
			$(RAW_SRC_FILE:%=file/%) \
			$(RAW_SRC_FLOAT:%=float/%) \
			$(RAW_SRC_INT:%=int/%) \
			$(RAW_SRC_LST:%=lst/%) \
			$(RAW_SRC_MEM:%=mem/%) \
			$(RAW_SRC_PUT:%=put/%) \
			$(RAW_SRC_STR:%=str/%)

SRC_DIR = src
OBJ_DIR = obj

SRC = $(RAW_SRC:%=$(SRC_DIR)/%.c)
OBJ = $(RAW_SRC:%=$(OBJ_DIR)/%.o)

OBJ_DIRS := $(sort $(dir $(OBJ)))

COUNT = 1
TOTAL_FILES := $(words $(RAW_SRC))

NAME = libft.a
INC = inc
HEADER = libft.h

# .SILENT:

.PHONY: all clean fclean re

all: $(NAME)

clean:
	@$(RM) $(OBJ_DIR)
	@printf "$(RED)Deleted objects$(NC)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)Deleted $(NAME)$(NC)\n"

re:
	@printf "$(YELLOW)Rebuilding...$(NC)\n"
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIRS)
	@printf "\r\033[K"
	@printf "$(YELLOW)Compiling $(GREEN)$$(($(COUNT) * 100 / $(TOTAL_FILES)))%%$(NC) - $<\r"
	@$(CC) $(COMPILER_FLAGS) -I$(INC) -c $< -o $@
	@$(eval COUNT=$(shell echo $$(($(COUNT) + 1))))

$(NAME): $(OBJ) $(INC)/$(HEADER)
	@printf "\r\033[K"
	@$(ARCHIVE) $(NAME) $^
	@printf "$(GREEN)Archive created.$(NC)\n"
	@printf "$(GREEN)$(NAME) done$(NC)\n"

$(OBJ_DIRS):
	@mkdir -p $@
