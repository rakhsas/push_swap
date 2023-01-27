/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:05:10 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/27 16:10:50 by rakhsas          ###   ########.fr       */
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

void	push_2(t_stack **head_to, t_stack **head_from, int n)
{
	t_stack	*tmp;
	t_stack	*to;
	t_stack	*from;

	to = *head_to;
	from = *head_from;
	if (!from)
		return ;
	tmp = from;
	from = from->next;
	*head_from = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		*head_to = to;
	}
	else
	{
		tmp->next = to;
		*head_to = tmp;
	}
	if (n == 0)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);

}

// void	r_a_b(t_stack **a, int i)
// {
// 	t_stack	*tmp;
// 	t_stack	*tmp1;

// 	tmp = *a;
// 	tmp1 = (*a)->next;
// 	*a = (*a)->next;
// 	while ((*a)->next)
// 		(*a) = (*a)->next;
// 	tmp->next = NULL;
// 	(*a)->next = tmp;
// 	if (i == 0)
// 		write(1, "ra\n", 3);
// 	else
// 		write(1, "rb\n", 3);
// }

void    r_a_b(t_stack **head, int i)
{
    t_stack    *stack_a;
    t_stack    *current;

    if (head == NULL)
        return ;
    stack_a = *head;
    *head = (*head)->next;
    stack_a->next = NULL;
    current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = stack_a;
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
