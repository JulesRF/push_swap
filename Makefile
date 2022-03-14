# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 14:49:20 by jroux-fo          #+#    #+#              #
#    Updated: 2022/03/14 18:21:13 by jroux-fo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

##PRINTF = libftprintf.a

##PRINTF_PATH = ft_printf

SRCS_FILES	=	main.c			\
				ft_atoi.c		\
				ft_sort.c		\
				ft_init.c		\
				ft_error.c		\
				ft_split.c 		\
				ft_utils.c		\
				ft_replace.c	\
				ft_lst_utils.c	\
				ft_operation.c	\
				ft_operation2.c	\

##FT_PRINTF	=	ft_printf/libftprintf.a

FLAGS = -Wall -Werror -Wextra

INCLUDES = header

PATH = srcs

OBJ_DIR = obj

OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRCS_FILES:.c=.o))

all: $(NAME)

##$(PRINTF): 
##	@printf "Compiling $@ ...\n"
##	@(cd $(PRINTF_PATH) && $(shell make))
##	@$(shell cp $(PRINTF_PATH)/$(PRINTF) .)

$(OBJ_DIR)/%.o: $(PATH)/%.c
	@$(shell mkdir -p $(OBJ_DIR))
	@printf "Compiling $< ...\n"
	@$(shell gcc $(FLAGS) -g3 -I $(INCLUDES) -c $< -o $@)

$(NAME): $(OBJ_FILES)
	@$(shell gcc $(FLAGS) -I $(INCLUDES) $(OBJ_FILES) -g3 -o $(NAME))
	@printf "Executable $@ created !\n"

clean:
	@printf "Deleting objects\n"
	@$(shell rm -rf $(OBJ_DIR))

fclean: clean
	@printf "Deleting executable\n"
	@$(shell rm -rf $(NAME))
#	@cd $(PRINTF_PATH) && $(MAKE) $@

re: fclean all

.PHONY:		all clean fclean re