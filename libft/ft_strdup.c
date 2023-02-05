/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:02:45 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/05 17:51:07 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strdup(char *s)
{
	int		i;
	int		len_of_s;
	char	*str;

	i = 0;
	len_of_s = ft_strlen(s);
	str = malloc(len_of_s + 1);
	if (!str)
		return (NULL);
	while (i[s])
	{
		i[str] = i[s];
		i++;
	}
	i[str] = '\0';
	return (str);
}
