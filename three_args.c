/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:31:10 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/27 16:14:05 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 3  2 instructions
void	check_for_3_args(t_stack **ab)
{
	t_stack **a;
	int	min;
	int	max;

	a = ab;
	min = check_for_min(*a);
	max = check_for_max(*a);
		while (ft_not_sorted(*a))
		{
			if (min == ft_lstlast(*a)->content)
			{
				rr_a_b(a, 0);

			}
			else if (max == (*a)->content)
			{
				r_a_b(a, 0);
			}
			else if (min != (*a)->content || max != (*a)->content)
			{
				swap_2(*a, 0);
			}
		}
		// while (*a)
		// 	{
		// 		printf("%d\n", (*a)->content);
		// 		(*a) = (*a)->next;
		// 	}
}
int	 check_for_max(t_stack *a)
{
	t_stack	*b;
	int		n;

	b = a;
	n = b->content;
	while (b->next)
	{
		if (n < b->next->content)
			n = b->next->content;
		b = b->next;
	}
	return (n);
}
int	check_for_min(t_stack *a)
{
	t_stack	*b;
	int		n;

	b = a;
	n = b->content;
	while (b->next)
	{
		if (n > b->next->content)
			n = b->next->content;
		b = b->next;
	}
	return (n);
}



void	check_for_5_args(t_stack **a, t_stack **b, int len, int min)
{
	// t_stack **c;
	// c = a;
	// while (ft_not_sorted(*a))
	// {
		if (len == 3)
		{
			check_for_3_args(a);
			while (*b)
				push_2(a, b, 0);

		}else if (ft_lstlast(*a)->content == min)
			r_a_b(a, 0);
		else if ((*a)->content == min)
			push_2(b, a, 1);
		else
			rr_a_b(a, 0);
		min = check_for_min(*a);
		len = ft_lstsize(*a);
	// }
	// while (*a)
	// {
	// 	printf("%d\n", (*a)->content);
	// 	(*a) = (*a)->next;
	// }
}
