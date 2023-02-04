/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_3args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:54:34 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/04 22:59:50 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more_than_five_args(t_stack **stack, t_stack **stack_b)
{
	t_stack	*a;
	t_tab	*c;

	c = malloc(sizeof(t_tab));
	c->arr = malloc(sizeof(int) * ft_lstsize(*stack));
	ft_fill_tab(stack, c);
	sort_array(c->arr, ft_lstsize(*stack));

	a = *stack;
	int i = 0;
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
	c->size = ft_lstsize(*stack);
	c->array_size = c->size;
	// printf("%d\n", c->size);
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

	while (*stack)
	{
		// printf("%d\t%d\t%d\t\n", c->start, c->end, in_range((*stack)->content, c->arr, c->start , c->end));
		// sleep(5);
		if (in_range((*stack)->content, c->arr, c->start , c->end) >= 0)
		{
			if ((*stack)->content >= c->arr[c->middle])
			{
				push_2(stack, stack_b, 1);

			}
			else
			{
				push_2(stack, stack_b, 1);
				r_a_b(stack_b, 1);
			}
			// if ((*stack)->content < c->arr[c->array_size / 2])
			// {
			// 	r_a_b(stack_b, 1);
			// }
		}

		else
		{
			// printf("%d\t%d\n", c->start, c->end);
			r_a_b(stack, 0);
		}
		if (ft_lstsize(*stack_b) == c->end - c->start)
		{
			c->start -= c->offset;
			c->end += c->offset;
			if (c->start < 0)
				c->start = 0;
			if (c->end >= c->size)
				c->end = c->size - 1;
		}
		if (ft_lstsize(*stack) == 1)
			push_2(stack, stack_b, 1);
	}



	c->size_copy = ft_lstsize(*stack_b);
	c->size_copy--;
	c->down = 0;

	while (*stack_b || c->down)
	{
		c->max = c->arr[c->size_copy];
		if (ft_exist(*stack_b, c->max))
		{
			if ((*stack_b)->content == c->max)
			{
				// printf("%d\n", (*stack_b)->content);
				push_2(stack_b, stack, 0);
				c->size_copy--;
			}
			else
			{
				// printf("1****%d\n", c->down);
				if (c->down == 0 || (*stack && (*stack_b)->content > ft_lstlast(*stack)->content))
				{
					// printf("---%d\n", (*stack_b)->content);
					push_2(stack_b, stack, 0);
					r_a_b(stack, 0);
					c->down++;
					// printf("2****%d\n", c->down);
				}
				else
				{
					if (returnwhere(c, stack_b) > c->size_copy / 2)
						rr_a_b(stack_b, 1);
					else
						r_a_b(stack_b, 1);
				}
			}
		}
		else
		{
			rr_a_b(stack, 0);
			// printf("%d\n", (*stack)->content);
			c->size_copy--;
			c->down--;
			// printf("3****%d\n", c->down);
		}
	}
	system("leaks push_swap");
	// printf("-----------\n");
	// while (*stack)
	// {
	// 	printf("%d ", (*stack)->content);
	// 	*stack = (*stack)->next;
	// }
}