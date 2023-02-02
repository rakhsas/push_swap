/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_next_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:49:22 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/31 19:33:48 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *tab, int p1, int p2)
{
	int	tmp;

	tmp = tab[p1];
	tab[p1] = tab[p2];
	tab[p2] = tmp;
}

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(tab, j, j + 1);
			j++;
		}
		i++;
	}
}

void	ft_fill_tab(t_stack **b, t_tab *c)
{
	t_stack	*a;
	int		i;

	i = 0;
	a = *b;
	while (a)
	{
		c->arr[i++] = (a)->content;
		a = (a)->next;
	}
	bubble_sort(c->arr, ft_lstsize(*b));
}

int	in_range(t_tab *data, int c)
{
	int	i;

	i = data->start;
	while (i <= data->end)
	{
		if (c == data->arr[i])
			return (1);
		i++;
	}
	return (0);
}

int	function(t_tab *c, t_stack *stack_b)
{
	t_stack	*start;
	int		d;

	start = stack_b;
	d = 1;
	while (start)
	{
		if (c->arr[c->size - 1] == start->content)
		{
			c->size--;
			return (d);
		}
		d++;
		start = start->next;
	}
	return (0);
}
