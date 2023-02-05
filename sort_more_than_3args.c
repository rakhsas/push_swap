/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_3args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:54:34 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/05 12:05:12 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	transfer_to_b(t_stack **stack, t_stack **stack_b, t_tab *c)
{
	while (*stack)
	{
		if (in_range((*stack)->content, c->arr, c->start, c->end) >= 0)
		{
			if ((*stack)->content >= c->arr[c->middle])
				push_2(stack, stack_b, 1);
			else
			{
				push_2(stack, stack_b, 1);
				r_a_b(stack_b, 1);
			}
		}
		else
			r_a_b(stack, 0);
		if (ft_lstsize(*stack_b) == c->end - c->start)
		{
			c->start -= c->offset;
			c->end += c->offset;
		}
		if (ft_lstsize(*stack) == 1)
			push_2(stack, stack_b, 1);
	}
}

void	next_sort(t_tab *c, t_stack **stack, t_stack **stack_b)
{
	c->size = ft_lstsize(*stack);
	c->array_size = c->size;
	c->middle = c->array_size / 2;
	if (c->array_size < 8)
		c->n = 2;
	else if (c->array_size <= 150)
		c->n = 8;
	else if (c->array_size > 150)
		c->n = 18;
	c->offset = c->array_size / c->n;
	c->start = c->middle - c->offset;
	c->end = c->middle + c->offset + 1;
	transfer_to_b(stack, stack_b, c);
	c->size_copy = ft_lstsize(*stack_b);
	c->size_copy--;
	c->down = 0;
}

void	helper(t_tab *c, t_stack **stack, t_stack **stack_b)
{
	if (c->down == 0
		|| (*stack && (*stack_b)->content > ft_lstlast(*stack)->content))
	{
		push_2(stack_b, stack, 0);
		r_a_b(stack, 0);
		c->down++;
	}
	else
	{
		if (returnwhere(c, stack_b) > c->size_copy / 2)
			rr_a_b(stack_b, 1);
		else
			r_a_b(stack_b, 1);
	}
}

void	next_next_sort(t_stack **stack, t_stack **stack_b, t_tab *c)
{
	while (*stack_b || c->down)
	{
		c->max = c->arr[c->size_copy];
		if (ft_exist(*stack_b, c->max))
		{
			if ((*stack_b)->content == c->max)
			{
				push_2(stack_b, stack, 0);
				c->size_copy--;
			}
			else
			{
				helper(c, stack, stack_b);
			}
		}
		else
		{
			rr_a_b(stack, 0);
			c->size_copy--;
			c->down--;
		}
	}
}

void	sort_more_than_five_args(t_stack **stack, t_stack **stack_b)
{
	t_stack	*a;
	t_tab	*c;
	int		i;

	i = 0;
	a = *stack;
	c = malloc(sizeof(t_tab));
	c->arr = malloc(sizeof(int) * ft_lstsize(*stack));
	ft_fill_tab(stack, c);
	sort_array(c->arr, ft_lstsize(*stack));
	while (a)
	{
		while (c->arr[i])
		{
			if ((a)->content == c->arr[i])
				(a)->index = i;
			i++;
		}
		a = a->next;
	}
	next_sort(c, stack, stack_b);
	next_next_sort(stack, stack_b, c);
}
