/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:05:48 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/14 15:14:36 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include "printf/ft_printf.h"

typedef struct s_stack
{
	int content;
	struct s_stack *next;
}	t_stack;

void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);
// split
char	**ft_split(char const *s, char c);
char	*ft_itoa(int num);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif