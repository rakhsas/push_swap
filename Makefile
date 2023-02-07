# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 13:51:26 by rakhsas           #+#    #+#              #
#    Updated: 2023/02/07 19:05:26 by rakhsas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME1 = checker
DIR = libft
DIR1 = printf/src
DIR_UTILS = printf/utils
SRC =	main.c rules.c help.c rules_next.c three_args.c next_main.c next_next_main.c sort_more_than_3args.c\
		$(DIR)/ft_lstadd_back.c $(DIR)/ft_lstnew.c $(DIR)/ft_split.c $(DIR)/ft_itoa.c $(DIR)/ft_atoi.c \
		$(DIR)/ft_isdigit.c $(DIR)/ft_lstsize.c $(DIR)/ft_lstadd_front.c $(DIR)/ft_lstdelone.c	\
		$(DIR)/ft_specific_len.c $(DIR)/ft_strlen.c $(DIR)/ft_lstlast.c

GCC = gcc
SRC_BONUS = checker_bonus.c help.c $(DIR)/get_next_line.c $(DIR)/get_next_line_utils.c\
			ft_lstclear.c rules.c rules_next.c three_args.c next_main.c next_next_main.c sort_more_than_3args.c\
		$(DIR)/ft_lstadd_back.c $(DIR)/ft_lstnew.c $(DIR)/ft_split.c $(DIR)/ft_itoa.c $(DIR)/ft_atoi.c \
		$(DIR)/ft_isdigit.c $(DIR)/ft_lstsize.c $(DIR)/ft_lstadd_front.c $(DIR)/ft_lstdelone.c	\
		$(DIR)/ft_specific_len.c $(DIR)/ft_strlen.c $(DIR)/ft_lstlast.c $(DIR)/ft_strdup.c

CFLAGS =  -Wall -Wextra -Werror


BONOBJS = $(SRC_BONUS:.c=.o)
OBJS = $(SRC:.c=.o)

RM = rm -f
all : $(NAME)
bonus: $(NAME1)

$(NAME) : $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS)

$(NAME1) : $(BONOBJS)
	cc $(CFLAGS) -o $(NAME1) $(BONOBJS)
clean :
	$(RM) $(OBJS)

fclean : clean
			$(RM) $(NAME) $(RM) $(BONOBJS)

re : fclean all bonus
