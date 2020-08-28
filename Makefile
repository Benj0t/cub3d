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
			./sources/parsing/error\
			./sources/parsing/parsing_utils\
			./sources/parsing/null\
			./sources/parsing/rgb\
			./sources/parsing/arg_1\
			./sources/parsing/arg_2\
			./sources/parsing/utils\
			./sources/parsing/gnl/get_next_line\
			./sources/parsing/gnl/get_next_line_utils\
			./sources/parsing/utils/ft_putchars\
			./sources/parsing/utils/ft_strdup\
			./sources/parsing/utils/ft_split\
			./sources/parsing/utils/ft_strjoin_n\
			./sources/parsing/utils/ft_substr\
			./sources/parsing/utils/ft_strcmp\
			./sources/parsing/valid_map\
			./sources/parsing/init\
			./sources/parsing/utils/ft_atoi\
			./sources/parsing/map\
			./sources/parsing/pos\
			./sources/screenshot\


SRCS = $(addsuffix .c, $(FILES))
OBJ = $(SRCS:.c=.o)

CC = gcc
L_CC = clang
LINUX = 0
FLAGS = -Wall -Wextra -Werror
L_LIB = -L $(INC_PATH)minilibx_linux/minilibx/ -lmlx -L%%%%/../lib -lXext -lX11 -lm
MAC_LIB = -L $(INC_PATH)minilibx/ -lmlx -framework OpenGL -framework Appkit

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
			@echo "$(CYAN)Constructing executable:$(NOC) $@"
			@$(L_CC) -o $(NAME) $(OBJ) $(MAC_LIB)

.c.o:		${SRCS}
			@echo " $(VIOLET)[$(L_CC)] $(GREEN)[$(FLAGS)]$(NOC) $(YELLOW)in progress ...:$(NOC) $< $(RED)->$(NOC) $@"
			@$(L_CC) -c -I$(INC_PATH) $< -o ${<:.c=.o}
clean:
	@echo "\n$(RED)Removing '.o' objects: $(NOC) $@"
	@rm -f $(OBJ)

fclean: clean
	@echo "\n$(RED)Removing executable: $(NOC) $@"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean