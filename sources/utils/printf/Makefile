# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 19:04:13 by bemoreau          #+#    #+#              #
#    Updated: 2020/01/28 21:23:52 by bemoreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =		./printf.c\
			./printf_args.c\
			./printf_char.c\
			./printf_hexa.c\
			./printf_nbr.c\
			./printf_utils.c\
			./printf_utils2.c\
			./printf_utils3.c\
			./printf_utils4.c\
			./printf_nbr2.c\

CC = gcc

AR = ar -rc

FLAGS = -Wall -Wextra -Werror

OBJ = 		$(SRCS:.c=.o)

.c.o:		${SRCS}
			$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

.PHONY: 	all clean re fclean bonus

all: 		$(NAME)

$(NAME): 	$(OBJ)
			$(AR) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all