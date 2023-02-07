/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:22:47 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/02/07 18:58:41 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_stack **lst)
{
	if (lst)
	{
		while (*lst != NULL)
		{
			free(*lst);
			*lst = (*lst)->next;
		}
		free(*lst);
		*lst = NULL;
	}
}
