/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:05:10 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/07 18:54:45 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_2(t_stack *a, int i)
{
	int	n;

	if (ft_lstsize(a) >= 2)
	{
		n = a->content;
		a->content = a->next->content;
		a->next->content = n;
		if (i == 0)
			write(1, "sa\n", 3);
		else if (i == 1)
			write(1, "sb\n", 3);
	}
}

void	ss(t_stack *A, t_stack *B, int n)
{
	swap_2(A, n);
	swap_2(B, n);
}

void	push_2(t_stack **stack_1, t_stack **stack_2, int n)
{
	t_stack	*tmp;

	if (!*stack_1)
		return ;
	tmp = (*stack_1)->next;
	(*stack_1)->next = *stack_2;
	*stack_2 = *stack_1;
	*stack_1 = tmp;
	if (n == 0)
		write(1, "pa\n", 3);
	else if (n == 1)
		write(1, "pb\n", 3);
}

void	r_a_b(t_stack **head, int i)
{
	t_stack	*tmp;

	if (!head || !(ft_lstsize(*head) > 1))
		return ;
	tmp = (*head)->next;
	(*head)->next = NULL;
	ft_lstlast(tmp)->next = *head;
	*head = tmp;
	if (i == 0)
		write(1, "ra\n", 3);
	else if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b, int i)
{
	r_a_b(&a, i);
	r_a_b(&b, i);
}
