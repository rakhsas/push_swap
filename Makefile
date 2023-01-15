# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 13:51:26 by rakhsas           #+#    #+#              #
#    Updated: 2023/01/14 15:15:37 by rakhsas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
DIR = libft
DIR1 = printf/src
DIR_UTILS = printf/utils
SRC =	main.c ft_lstadd_back.c ft_lstnew.c ft_split.c ft_itoa.c ft_atoi.c ft_isdigit.c

GCC = gcc


CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS)
clean :
	$(RM) $(OBJS)

fclean : clean
			$(RM) $(NAME)
re : fclean all
