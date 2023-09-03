# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dania <dania@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 17:05:48 by ddania-c          #+#    #+#              #
#    Updated: 2023/09/03 22:28:08 by dania            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

# Includes
INC			= -I ./includes/

# Sources
SRC_DIR 	= src

SRC_FILES	=	main.c		\
				ft_atoi.c	\
				utils.c	
				
SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))	

# Objects
OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

# Compilation info
CC	= gcc
RM = rm -f
CFLAGS = -Werror -Wextra -Wall

# Colors
GREEN	=	\033[0;32m
RED		=	\033[0;31m
WHITE	=	\033[0;97m
RESET	=	\033[0m
YELLOW 	=	\033[0;93m
ORANGE	=	\033[38;5;209m


all: $(NAME)

# Main rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Objects rule
$(NAME): $(OBJS)
	@echo -n "$(YELLOW)Compiling	${WHITE}→	$(GREEN)$(NAME)$(RESET): "
	@$(CC) $(OBJS) -o $@
	@echo "$(GREEN) Ok ✓$(RESET)"

# Clean rules
clean:
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) object$(RESET): "
	@$(RM) -r $(OBJ_DIR)
	@echo "$(GREEN)Ok $(RED)✗$(RESET)"

fclean: clean
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) executable$(RESET): "
	@$(RM) $(NAME)
	@echo "$(GREEN)Ok $(RED)✗$(RESET)"

bonus: all

re: fclean all

.PHONY: all clean fclean re 
