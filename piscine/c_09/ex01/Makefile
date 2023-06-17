HEADERS = -I./includes
SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c 
OBJS = $(SRCS:%.c=%.o)
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
ARCHIVE = ar rcs

all: libft.a

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} libft.a

re: fclean all

%.o: %.c
	${CC} ${FLAGS} ${HEADERS} -c $< -o $@

libft.a: ${OBJS}
	${ARCHIVE} libft.a $^

