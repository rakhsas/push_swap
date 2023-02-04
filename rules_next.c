/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:11:19 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/04 23:15:48 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_a_b(t_stack **head, int i)
{
	t_stack	*lastone;
	t_stack	*dd;

	if (ft_lstsize(*head) == 1)
		return ;
	dd = *head;
	while (dd->next->next)
		dd = dd->next;
	lastone = dd->next;
	dd->next = NULL;
	lastone->next = *head;
	*head = lastone;
	if (i == 0)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	check(char *str)
{
	if (ft_specific_len(str, ' ') == ft_strlen(str))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	returnwhere(t_tab *tab, t_stack **stack_b)
{
	t_stack	*stack;
	int		k;

	k = 1;
	stack = *stack_b;
	while (stack != NULL)
	{
		if (tab->arr[tab->size_copy] == stack->content)
			return (k);
		k++;
		stack = stack->next;
	}
	return (1);
}
