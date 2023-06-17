SRC_DIR := ./src
INCLUDES := -Iincludes
OBJ_DIR := obj

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

CC := cc
COMPILER_FLAGS := -Wall -Wextra -Werror
BINARY := ft_display_file

RM := rm -rf
MKDIR := mkdir -p

.PHONY: all clean fclean

all: build

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(BINARY)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR) $(@D)
	$(CC) $(COMPILER_FLAGS) $(INCLUDES) -c $< -o $@

build: $(OBJS)
	$(CC) ${COMPILER_FLAGS} $(INCLUDES) $^ -o $(BINARY)
