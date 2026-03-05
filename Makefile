NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
INCLUDES    = -Iinclude -Ilibft -Ilibftprintf

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

LIBFTPRINTF_DIR = libft/printf
LIBFTPRINTF     = $(LIBFTPRINTF_DIR)/libftprintf.a

SRC_DIR     = src

SRC         = \
$(SRC_DIR)/main.c \
$(SRC_DIR)/operations/push_op.c \
$(SRC_DIR)/operations/swap_op.c \
$(SRC_DIR)/operations/rotate_op.c \
$(SRC_DIR)/operations/reverse_rotate_op.c \
$(SRC_DIR)/parse/parse_input.c \
$(SRC_DIR)/sort/calculate_utils.c \
$(SRC_DIR)/sort/move_utils.c \
$(SRC_DIR)/sort/sort_utils.c \
$(SRC_DIR)/sort/turk_algorithm.c \
$(SRC_DIR)/sort/small_sorts.c \
$(SRC_DIR)/sort/quick_select.c \
$(SRC_DIR)/stack/stack.c

OBJ         = $(SRC:.c=.o)

all: $(LIBFT) $(LIBFTPRINTF) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBFTPRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re