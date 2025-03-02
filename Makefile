# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 15:07:37 by ksuebtha          #+#    #+#              #
#    Updated: 2025/03/01 08:48:58 by ksuebtha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Directories
LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a
INC= include/
OBJ_DIR = obj/

# Complier and Cflag
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC)
RM = rm -f

# Source Files
COMMANDS_SRCS = commands/push.c \
				commands/rev_rotate.c \
				commands/rotate.c \
				commands/sort_three.c \
				commands/swap.c

PUSH_SWAP_UTILS_SRCS = push_swap_utils/str_to_ll.c \
					push_swap_utils/ll_utils.c \
					push_swap_utils/init_stack.c \
					push_swap_utils/stack_utils.c \
					push_swap_utils/atoi.c \
					push_swap_utils/sort_stack.c \
					push_swap_utils/prepare_a_stack_node.c \
					push_swap_utils/sort_stack_utils.c \
					push_swap_utils/prepare_b_stack_node.c 
					
# All source files
SRCS = $(COMMANDS_SRCS) $(PUSH_SWAP_UTILS_SRCS) push_swap.c


# Converts SRCS file paths from .c to .o and places them inside OBJ_DIR/
OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))


# Build rules
start: 
	@make all

# Ensures libft.a is built by running make inside the libft/ directory
$(LIBFT):
	@make -C ./libft

# $(PRINTF)
	@make -C ./printf

all: $(NAME) $(LIBFT) $(PRINTF)

$(NAME): $(OBJ) $(LIBFT)	
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

# Rule to compile object files	
$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)  
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libft
	@make clean -C ./printf

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(PRINTF)

re: fclean all

# Prevents Make from mistaking these names for real files.
.PHONY: start all clean fclean re
	