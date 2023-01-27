/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:05:48 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/27 15:21:35 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
typedef struct s_stack
{
	int	content;
	struct s_stack *next;
}	t_stack;

void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
// libft
char	**ft_split(char const *s, char c);
char	*ft_itoa(int num);
int		ft_isdigit(int c);
long	ft_atoi(const char *str);
int		ft_lstsize(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst);
int		ft_specific_len(char *str, char c);
int		ft_strlen(char *str);
// rules
void	ss(t_stack *A, t_stack *B);
void	push_2(t_stack **head_to, t_stack **head_from, int n);
void	r_a_b(t_stack **a, int i);
void	rr(t_stack *a, t_stack *b);
void	rr_a_b(t_stack **head, int i);
void	swap_2(t_stack *a, int i);
// checker
void	check(char *str);
void	check_for_3_args(t_stack **a);
void	check_for_5_args(t_stack **a, t_stack **b, int len, int min);
int		ft_not_sorted(t_stack *stack_a);
int		check_for_min(t_stack *a);
int		check_for_max(t_stack *a);
#endif