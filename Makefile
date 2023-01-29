# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 13:51:26 by rakhsas           #+#    #+#              #
#    Updated: 2023/01/29 17:24:07 by rakhsas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
DIR = libft
DIR1 = printf/src
DIR_UTILS = printf/utils
SRC =	main.c rules.c rules_next.c three_args.c\
		$(DIR)/ft_lstadd_back.c $(DIR)/ft_lstnew.c $(DIR)/ft_split.c $(DIR)/ft_itoa.c $(DIR)/ft_atoi.c \
		$(DIR)/ft_isdigit.c $(DIR)/ft_lstsize.c $(DIR)/ft_lstadd_front.c $(DIR)/ft_lstdelone.c	\
		$(DIR)/ft_specific_len.c $(DIR)/ft_strlen.c $(DIR)/ft_lstlast.c

GCC = gcc


CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS)

# -fsanitize=address
clean :
	$(RM) $(OBJS)

fclean : clean
			$(RM) $(NAME)
re : fclean all
