/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:05:39 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/05 22:15:26 by rakhsas          ###   ########.fr       */
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

void	ft_next_next(t_stack *a, t_stack *b, char *str)
{
	if (ft_lstsize(b) >= 1 || ft_lstsize(a) >= 1)
	{
		if (ft_strcmp("sa\n", str) == 0)
			swap_2(a, 2);
		else if (ft_strcmp("sb\n", str) == 0)
			swap_2(b, 2);
		else if (ft_strcmp("pa\n", str) == 0)
			push_2(&b, &a, 2);
		else if (ft_strcmp("pb\n", str) == 0)
			push_2(&a, &b, 2);
		if (ft_strcmp("ra\n", str) == 0)
			r_a_b(&a, 2);
		else if (ft_strcmp("rb\n", str) == 0)
			r_a_b(&b, 2);
		else if (ft_strcmp("rrb\n", str) == 0)
			rr_a_b(&b, 2);
		else if (ft_strcmp("rra\n", str) == 0)
			rr_a_b(&a, 2);
	}
	else
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	ft_next(t_stack *a, t_stack *b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		ft_next_next(a, b, str);
	}
	if (!ft_not_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	helper_next(t_stack *a, t_stack *b)
{
	ft_duplicate(a);
	ft_next(a, b);
}

int	main(int ac, char **av)
{
	char	**content;
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		j;

	if (ac > 1)
	{
		b = NULL;
		i = 1;
		while (i < ac)
		{
			content = ft_split(av[i], ' ');
			j = 0;
			while (content[j])
			{
				opener(content[j]);
				ft_lstadd_back(&a, ft_lstnew(ft_atoi(content[j])));
				free(content[j++]);
			}
			free(content);
			i++;
		}
		helper_next(a, b);
	}
}
