/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:43:14 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/14 16:22:11 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sym;
	long	res;

	i = 0;
	sym = 1;
	res = 0;
	while ((i[str] == ' ') || (i[str] >= '\t' && i[str] <= '\r'))
		i++;
	if (i[str] == '-')
		sym *= -1;
	if (i[str] == '+' || i[str] == '-')
		i++;
	while (i[str] && i[str] >= '0' && i[str] <= '9')
	{
		if (res * sym > 2147483647)
			return (-1);
		else if (res * sym < -2147483648)
			return (0);
		else
			res = res * 10 + (i[str] - '0');
		i++;
	}
	return (sym * res);
}
