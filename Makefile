# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: damian <damian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 17:05:48 by ddania-c          #+#    #+#              #
#    Updated: 2023/10/09 23:39:24 by damian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
#____________________________________________________________________
#_____________________________I͟N͟C͟L͟U͟D͟E͟S͟_______________________________

INC			= -I ./includes/
#____________________________________________________________________
#_____________________________S͟O͟U͟R͟C͟E͟_________________________________

SRC_DIR		= src

SRC_FILES	=	main.c			\
				parsing.c		\
				init.c			\
				thread.c		\
				routine.c		\
				print.c			\
				stop.c			\
				utils.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
#____________________________________________________________________
#_____________________________O͟B͟J͟E͟C͟T͟_________________________________

OBJ_DIR		=	obj
OBJS		=	$(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))
#____________________________________________________________________
#_____________________________F͟L͟A͟G͟S͟__________________________________

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Werror -Wextra -Wall -pthread
#____________________________________________________________________
#_____________________________C͟O͟L͟O͟R͟S͟_________________________________

GREEN	=	\033[0;32m
RED		=	\033[0;31m
WHITE	=	\033[0;97m
RESET	=	\033[0m
YELLOW 	=	\033[0;93m

all: $(NAME)
#____________________________________________________________________
#_____________________________M͟A͟I͟N͟_R͟U͟L͟E͟______________________________

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
#____________________________________________________________________
#_____________________________O͟B͟J͟E͟C͟T͟_R͟U͟L͟E͟____________________________

$(NAME): $(OBJS)
#	@echo -n "Verifying	${WHITE}→	norminette"
#	@if norminette | grep "Error" > /dev/null 2>&1; then echo "$(RED) [Error]✗$(RESET)"; else echo "$(GREEN) [ok]✓$(RESET)"; fi
	@echo -n "$(YELLOW)Compiling	${WHITE}→	$(YELLOW)$(NAME)$(RESET) "
	@$(CC) $(OBJS) -o $@
	@echo "$(GREEN)[ok]✓$(RESET)"
#____________________________________________________________________
#_____________________________C͟L͟E͟A͟N͟_R͟U͟L͟E͟_____________________________

clean:
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) object$(RESET) "
	@$(RM) -r $(OBJ_DIR)
	@echo "$(GREEN)[ok]$(RED)✗$(RESET)"

fclean: clean
	@echo -n "$(RED)Deleting	${WHITE}→	$(RED)$(NAME) executable$(RESET) "
	@$(RM) $(NAME)
	@echo "$(GREEN)[ok]$(RED)✗$(RESET)"

bonus: all

re: fclean all

.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000
