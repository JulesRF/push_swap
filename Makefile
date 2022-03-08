# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 14:49:20 by jroux-fo          #+#    #+#              #
#    Updated: 2022/03/08 14:30:32 by jroux-fo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PRINTF = libftprintf.a

PRINTF_PATH = ft_printf

SRCS_FILES	=	main.c		\
				ft_split.c 	\

FT_PRINTF	=	ft_printf/libftprintf.a

FLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

INCLUDES = header

PATH = srcs

OBJ_DIR = obj

OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRCS_FILES:.c=.o))

all: $(NAME)

$(PRINTF): 
	@printf "Compiling $@ ...\n"
	@(cd $(PRINTF_PATH) && $(MAKE))
	@cp $(PRINTF_PATH)/$(PRINTF) .

$(OBJ_DIR)/%.o: $(PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "Compiling $< ...\n"
	@gcc $(FLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ_FILES) $(PRINTF)
	@gcc $(FLAGS) -I $(INCLUDES) $(OBJ_FILES) $(FT_PRINTF) -o $(NAME)
	@printf "Executable $@ created !\n"

clean:
	@printf "Deleting objects\n"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "Deleting executable\n"
	@rm -rf $(NAME) $(PRINTF)
	@cd $(PRINTF_PATH) && $(MAKE) $@

re: fclean all

.PHONY:		all clean fclean re
