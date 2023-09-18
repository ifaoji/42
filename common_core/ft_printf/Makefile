SRCS_DIR = src
SRCS = $(SRCS_DIR)/ft_printf.c \
		$(SRCS_DIR)/number.c \
		$(SRCS_DIR)/params.c \
		$(SRCS_DIR)/string.c \
		$(SRCS_DIR)/hex.c

OBJS_DIR = obj
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME := libftprintf.a
HEADER := ft_printf.h

RM := rm -rf
MKDIR := mkdir -p

ARCHIVE := ar -rs
CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKE_LIB = $(MAKE) -C $(LIBFT_DIR)

.PHONY: all bonus clean fclean libft re

all: libft $(NAME)

bonus: all

clean:
	$(MAKE_LIB) clean
	$(RM) $(OBJS_DIR)

fclean: clean
	$(MAKE_LIB) fclean
	$(RM) $(NAME)

libft:
	$(MAKE) -C libft

re: fclean all

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I. -c $^ -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

$(NAME): $(OBJS) $(HEADER)
	cp $(LIBFT) $(NAME)
	$(ARCHIVE) $(NAME) $^
