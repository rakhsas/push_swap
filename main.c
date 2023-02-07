/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:05:26 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/07 18:58:28 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_exist(t_stack *b, int max)
{
	while (b)
	{
		if (b->content == max)
			return (1);
		b = b->next;
	}
	return (0);
}

void	ft_next_main(t_stack **stack, t_stack **stack_b)
{
	ft_duplicate(*stack);
	if (ft_not_sorted(*stack))
	{
		if (ft_lstsize(*stack) == 2)
		{
			if ((*stack)->next->content < (*stack)->content)
				swap_2(*stack, 0);
		}
		else if (ft_lstsize(*stack) == 3)
			check_for_3_args(stack);
		else if (ft_lstsize(*stack) > 3 && ft_lstsize(*stack) <= 5)
		{
			check_for_5_args(stack, stack_b, ft_lstsize(*stack),
				check_for_min(*stack));
		}
		else if (ft_lstsize(*stack) > 5)
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
			content = ft_split(av[i], ' ');
			j = 0;
			while (content[j])
			{
				opener(content[j]);
				ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(content[j])));
				free(content[j++]);
			}
			free(content);
			i++;
		}
		ft_next_main(&stack_a, &b);
	}
}
