# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 19:04:13 by bemoreau          #+#    #+#              #
#    Updated: 2020/07/06 23:10:44 by mdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
INCLUDE =	cub3d.h\
			parsing.h\
			libftprintf.h\
			get_next_line.h

INC_PATH = ./includes/

vpath %.c sources/parsing
vpath %.c sources/utils
vpath %.c sources/raycasting

FILES =		./sources/raycasting/raycasting\
			./sources/raycasting/color\
			./sources/raycasting/deal_key\
			./sources/raycasting/move\
			./sources/raycasting/sprites\
			./sources/raycasting/texture\
			./sources/parsing/parsing\
			./sources/parsing/arg_1\
			./sources/parsing/arg_2\
			./sources/parsing/utils\
			./sources/parsing/gnl/get_next_line\
			./sources/parsing/gnl/get_next_line_utils\
			./sources/parsing/utils/ft_strdup\
			./sources/parsing/utils/ft_split\
			./sources/parsing/utils/ft_strjoin_N\
			./sources/parsing/utils/ft_substr\
			./sources/parsing/valid_map\
			./sources/parsing/init\
			./sources/parsing/utils/ft_atoi\
			./sources/parsing/map\
			./sources/parsing/pos\


SRCS = $(addsuffix .c, $(FILES))
OBJ = $(SRCS:.c=.o)

CC = gcc
L_CC = clang
LINUX = 0
FLAGS = -Wall -Wextra -Werror
L_LIB = -L $(INC_PATH)minilibx_linux/minilibx/ -lmlx -L%%%%/../lib -lXext -lX11 -lm
MAC_LIB = 

### COLORS ###

NOC = \033[0m
BOLD = \033[1m
UNDERLINE = \033[4m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
VIOLET = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m

all: 		$(NAME)

$(NAME): 	$(OBJ)
			@echo "\n $(VIOLET)[$(CC)] $(CYAN)Constructing executable:$(NOC) $@"
			@$(L_CC) -o $(NAME) $(OBJ) $(L_LIB)

.c.o:		${SRCS}
			@echo " $(VIOLET)[$(L_CC)] $(GREEN)[$(FLAGS)]$(NOC) $(YELLOW)in progress ...:$(NOC) $< $(RED)->$(NOC) $@"
			@$(L_CC) -c -I$(INC_PATH) $< -o ${<:.c=.o}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean