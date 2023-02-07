/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:33:59 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/07 19:01:30 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_not_sorted(t_stack *stack_a)
// {
// 	int		i;
// 	t_stack	*a;

// 	i = 0;
// 	a = stack_a;
// 	while (a)
// 	{
// 		if (a->content > a->next->content)
// 			i++;
// 		a = a->next;
// 	}
// 	return (i);
// }
int	ft_not_sorted(t_stack *stack_a)
{
	t_stack	*a;

	a = stack_a;
	if (!stack_a || ft_lstsize(stack_a) < 1)
		return (0);
	while (a->next)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next;
	}
	return (0);
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
			ft_error();
		i++;
	}
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (!ft_isdigit(str[i + 1]))
			ft_error();
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
				ft_error();
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
