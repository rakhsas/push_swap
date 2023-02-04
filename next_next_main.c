/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_next_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:49:22 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/04 22:33:30 by rakhsas          ###   ########.fr       */
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
	while (i <= size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (tab[i] > tab[j])
				ft_swap(tab, i,j);
			j++;
		}
		i++;
	}
}

void	ft_fill_tab(t_stack **b, t_tab *c)
{
	t_stack	*a;
	int		i, x;

	i = 0;
	x = 0;
	a = *b;
	while (a)
	{
		c->arr[i] = (a)->content;
		i++;
		a = (a)->next;
	}
}

// int	in_range(t_tab *data, int c)
// {
// 	int	i;

// 	i = data->start;
// 	while (i <= data->end)
// 	{
// 		if (c == data->arr[i])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

int	in_range(int content, int *arr, int start, int end)
{
	// printf("%d\t%d", start, end);
	int	i;

	i = 0;
	while (i <= end - start)
	{
		if (content == arr[start + i])
			return (i);
		i++;
	}
	return (-1);
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
