# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddaniel- <ddaniel-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 01:57:59 by ddaniel-          #+#    #+#              #
#    Updated: 2024/08/08 20:46:46 by ddaniel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INC = -I include/
SRC_DIR = srcs/
OBJ_DIR = obj/

CC =  gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

COMMANDS_DIR		=	$(SRC_DIR)cmd/push.c \
						$(SRC_DIR)cmd/rrotate.c \
						$(SRC_DIR)cmd/rotate.c \
						$(SRC_DIR)cmd/sort_stacks.c \
						$(SRC_DIR)cmd/sort_three.c \
						$(SRC_DIR)cmd/swap.c

PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap/handle_errors.c \
						$(SRC_DIR)push_swap/init_a.c \
						$(SRC_DIR)push_swap/init_b.c \
						$(SRC_DIR)push_swap/push_swap.c \
						$(SRC_DIR)push_swap/ft_split.c \
						$(SRC_DIR)push_swap/stack_init.c \
						$(SRC_DIR)push_swap/stack_utils.c

SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
#start:				
#					@make all


all: 				$(NAME)

$(NAME): 			$(OBJ)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)

fclean: 			clean
					@$(RM) $(NAME)

re: 				fclean all

# Phony targets represent actions not files
.PHONY:				all clean fclean re