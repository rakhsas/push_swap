/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:05:10 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/28 18:18:30 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_2(t_stack *a, int i)
{
	int	n;

	n = a->content;
	a->content = a->next->content;
	a->next->content = n;
	if (i == 0)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 1);
}

void	ss(t_stack *A, t_stack *B)
{
	swap_2(A, 0);
	swap_2(B, 1);
}

void	push_2(t_stack **stack_1, t_stack **stack_2, int n)
{
	t_stack	*tmp;

	tmp = (*stack_1)->next;
	(*stack_1)->next = *stack_2;
	*stack_2 = *stack_1;
	*stack_1 = tmp;
	if (n == 0)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	r_a_b(t_stack **head, int i)
{
	t_stack	*tmp;

	if (head == NULL)
		return ;
	tmp = (*head)->next;
	ft_lstlast(tmp)->next = *head;
	(*head)->next = NULL;
	*head = tmp;
	if (i == 0)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	r_a_b(&a, 0);
	r_a_b(&b, 1);
}
