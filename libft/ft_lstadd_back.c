/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:32:55 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/28 21:50:50 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*nt;

	if (*lst == NULL)
		*lst = new;
	else
	{
		nt = *lst;
		while (nt->next != NULL)
			nt = nt->next;
		nt->next = new;
	}
}
