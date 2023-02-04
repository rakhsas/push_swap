/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:05:26 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/04 23:24:29 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	help;

	help = *i;
	*i = *j;
	*j = help;
}

void	sort_array(int *arr, int len)
{
	int	i;
	int	j;
	int	min;

	i = 0;
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
	if (ft_not_sorted(*stack))
		ft_duplicate(*stack);
	if (ft_lstsize(*stack) == 2)
		swap_2(*stack, 0);
	else if (ft_lstsize(*stack) == 3)
		check_for_3_args(stack);
	else if (ft_lstsize(*stack) > 3 && ft_lstsize(*stack) <= 5)
	{
		check_for_5_args(stack, stack_b, ft_lstsize(*stack),
			check_for_min(*stack));
	}
	else if (ft_lstsize(*stack) > 5)
	{
		sort_more_than_five_args(stack, stack_b);
	}
}

int	main(int ac, char **av)
{
	char	**content;
	t_stack	*stack_a;
	t_stack	*b;
	int		i;
	int		j;

	if (ac > 1)
	{
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
				free(content[j]);
				j++;
			}
			free(content);
			i++;
		}
	}
	ft_next_main(&stack_a, &b);
}
