/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:05:26 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/02 10:55:48 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(char *str)
{
	if (ft_specific_len(str, ' ') == ft_strlen(str))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	test(t_stack **stack_a, t_stack **stack_b, int position)
{
	int d = ft_lstsize(*stack_b);
	int	h;

	h = 1;
	if (position > d / 2 )
	{
		position = (d + 1) - position;
		// write(1, "Position :: ", 12);
		// printf("%d H:: %d\n", position, h);
		while (position >= h)
		{
			rr_a_b(stack_b, 1);
			h++;
		}
		push_2(stack_b, stack_a, 0);
	}
	else if (position == 1)
		push_2(stack_b, stack_a, 0);
	else if (position <= d / 2)
	{
		position = position - 1;
		while (position >= h)
		{
			r_a_b(stack_b, 1);
			h++;
		}
		push_2(stack_b, stack_a, 0);
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
		// printf("%d****%d\n", tab->arr[tab->size] , stack->content);
		if (tab->arr[tab->size - 1] && tab->arr[tab->size - 1] == stack->content)
		{
			// printf("%d-----\n", tab->size);
			return (k);
		}
		k++;
		stack = stack->next;
	}
	return (1);
}

void	ft_next_main(t_stack **stack, t_stack **stack_b)
{
	t_tab	*c;
	t_stack	*a;

	c = NULL;
	if (ft_lstsize(*stack) == 2)
		swap_2(*stack, 0);
	else if (ft_lstsize(*stack) == 3)
		check_for_3_args(stack);
	else if (ft_lstsize(*stack) > 3 && ft_lstsize(*stack) <= 5)
		check_for_5_args(stack, stack_b, ft_lstsize(*stack), check_for_min(*stack));
	else if (ft_lstsize(*stack) > 5)
	{
		c = malloc(sizeof(t_tab));
		c->arr = malloc(sizeof(int) * ft_lstsize(*stack));
		ft_fill_tab(stack, c);
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
		c->size = ft_lstsize(*stack) + 1;
		c->middle = c->size / 2 - 1;
		if (c->size <= 10)
			c->n = 5;
		else if (c->size > 10 && c->size <= 150)
			c->n = 8;
		else if (c->size > 150)
			c->n = 18;
		c->offset = c->size / c->n;
		c->start = c->middle - c->offset;
		c->end = c->middle + c->offset;
		while (*stack)
		{
			if (in_range(c, (*stack)->content))
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
			if (ft_lstsize(*stack_b) == c->end - c->start + 1)
			{
				c->start -= c->offset;
				c->end += c->offset;
				if (c->start < 0)
					c->start = 0;
				if (c->end >= c->size)
					c->end = c->size - 1;
			}
		}
		while(ft_lstsize(*stack_b))
		{
			c->size--;
			test(stack, stack_b, returnwhere(c, stack_b));
		}

		// while (*stack)
		// {
		// 	printf("%d\n", (*stack)->content);
		// 	*stack = (*stack)->next;
		// }
		// system("leaks push_swap");
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*b;
	int	index;
	int		i;
	char	**content;
	int		j;

	if (ac > 1)
	{
		index = 0;
		i = 1;
		while (i < ac)
		{
			check(av[i]);
			content = ft_split(av[i], ' ');
			j = 0;
			while (content[j])
			{
				opener(content[j]);
				if (ft_atoi(content[j]) > 2147483647)
				{
					write(1, "Error\n", 6);
					exit(1);
				}
				ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(content[j])));
				index++;
				free(content[j]);
				j++;
			}
			free(content);
			i++;
		}
		ft_duplicate(stack_a);
		if (ft_not_sorted(stack_a))
		{
			ft_next_main(&stack_a, &b);
		}
	}
}
