/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:10:07 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/05 20:21:28 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*save(char *str)
{
	int		i;
	int		j;
	char	*rts;

	i = 0;
	while (i[str] && i[str] != '\n')
		i++;
	if (!str[i])
		return (free_it(str));
	rts = malloc(ft_strlen(str) - i + 1);
	if (!rts)
		return (NULL);
	i++;
	j = 0;
	while (i[str])
		rts[j++] = str[i++];
	rts[j] = '\0';
	free(str);
	return (rts);
}

int	check_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (i[str])
	{
		if (i[str] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char	*str_join(char *str, char *rts)
{
	char	*joined_string;
	int		str_len;
	int		rts_len;
	int		total_len;

	if (!str && !rts)
		return (NULL);
	if (str == NULL)
		return (ft_strdup(rts));
	if (rts == NULL)
		return (ft_strdup(str));
	str_len = ft_strlen(str);
	rts_len = ft_strlen(rts);
	total_len = str_len + rts_len + 1;
	joined_string = malloc(total_len);
	if (!joined_string)
		return (NULL);
	ft_memmove(joined_string, str, str_len);
	ft_memmove(joined_string + str_len, rts, rts_len);
	joined_string[total_len - 1] = '\0';
	free(str);
	return (joined_string);
}
