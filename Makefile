NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror 
INCLUDES    = -Iinclude -Ilibft

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRC_DIR     = src
OBJ_DIR     = obj

SRC         = \
$(SRC_DIR)/main.c \
$(SRC_DIR)/operations/push_op.c \
$(SRC_DIR)/operations/swap_op.c \
$(SRC_DIR)/operations/rotate_op.c \
$(SRC_DIR)/operations/reverse_rotate_op.c \
$(SRC_DIR)/parse/parse_input.c \
$(SRC_DIR)/utils/prepare_input.c \
$(SRC_DIR)/sort/calculate_utils.c \
$(SRC_DIR)/sort/move_utils.c \
$(SRC_DIR)/sort/sort_utils.c \
$(SRC_DIR)/sort/turk_algorithm.c \
$(SRC_DIR)/sort/small_sorts.c \
$(SRC_DIR)/sort/quick_select.c \
$(SRC_DIR)/stack/stack.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INCLUDES) -o $(NAME)
	@echo "push_swap compiled successfully ✅"

$(OBJ_DIR)/%.o: %.c 
	@mkdir -p $(dir $@)
	@printf "Compiling: %-40s\r" $<
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g3
debug: re

valgrind: debug
	@valgrind --leak-check=full \
	         --show-leak-kinds=all \
	         --track-origins=yes \
	         --verbose \
	         ./$(NAME) $(ARGS)

.PHONY: all clean fclean re debug valgrind