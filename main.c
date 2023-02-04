/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:05:26 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/04 22:47:11 by rakhsas          ###   ########.fr       */
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
		// if ((*stack_b)->content > (*stack_b)->next->content)
		// 	swap_2(*stack_b, 1);
		// else
		// 	r_a_b(stack_b, 1);
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
		//  || tab->arr[tab->size - 2] == stack->content
		if (tab->arr[tab->size_copy] == stack->content)
			return (k);
		k++;
		stack = stack->next;
	}
	return (1);
}
int	ft_exist(t_stack *b, int max)
{
	t_stack	*copy;

	copy = b;
	while (b)
	{
		if (b->content == max)
			return (1);
		b = b->next;
	}
	return (0);
}
void	ft_swapo(int *i, int *j)
{
	int help;
	help = *i;
	*i = *j;
	*j = help;
}
void    sort_array(int *arr, int len)
{
	int    i;
	int    j;
	int    min;
	int	x;

	i = 0;
	x = 0;
	if (arr)
	{
		while (i < len)
		{
			min = i;
			j = i + 1;
			while (j < len)
			{
				if (arr[j] < arr[min])
					min = j;
				j++;
			}
			ft_swapo(&arr[i], &arr[min]);
			i++;
		}
	}
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
