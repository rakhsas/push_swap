/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:48:37 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/07 19:00:53 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			ft_swap(&arr[i], &arr[min]);
			i++;
		}
	}
}

void	ft_swap(int *i, int *j)
{
	int	help;

	help = *i;
	*i = *j;
	*j = help;
}

void	rrr(t_stack *a, t_stack *b, int n)
{
	rr_a_b(&a, n);
	rr_a_b(&b, n);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
