/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:33:59 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/05 10:30:57 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_not_sorted(t_stack *stack_a)
{
	int		i;
	t_stack	*a;

	i = 0;
	a = stack_a;
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			i++;
		a = a->next;
	}
	return (i);
}

void	opener(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i[str])
	{
		if (!(i[str] >= '0' && i[str] <= '9'))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (!ft_isdigit(str[i + 1]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	ft_duplicate_next(int *array, int y, int da, int b)
{
	while (y < da)
	{
		b = y + 1;
		while (b < da)
		{
			if (array[y] == array[b])
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			b++;
		}
		y++;
	}
}

void	ft_duplicate(t_stack *stack_a)
{
	t_stack	*c;
	int		*array;
	int		da;
	int		y;
	int		b;

	array = malloc(sizeof(int) * ft_lstsize(stack_a));
	c = stack_a;
	da = 0;
	y = 0;
	b = 0;
	while (c != NULL)
	{
		array[da++] = c->content;
		c = c->next;
	}
	ft_duplicate_next(array, y, da, b);
	free(array);
}
