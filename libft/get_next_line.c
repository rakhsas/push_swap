/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:42:10 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/05 20:21:02 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*rdsv(int fd, char *str)
{
	int			reader;
	char		*buff;

	reader = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while ((!check_newline(str) && reader != 0))
	{
		reader = (int)read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		reader[buff] = '\0';
		str = str_join(str, buff);
	}
	free (buff);
	return (str);
}

char	*free_it(char *str)
{
	free(str);
	return (NULL);
}

char	*get_l(char *str)
{
	int		i;
	char	*rts;

	i = 0;
	if (!str[i])
		return (NULL);
	while (i[str] && i[str] != '\n')
		i++;
	rts = malloc(i + 2);
	if (!rts)
		return (NULL);
	i = 0;
	while (i[str] && i[str] != '\n')
	{
		i[rts] = i[str];
		i++;
	}
	if (i[str] == '\n')
		rts[i++] = '\n';
	rts[i] = '\0';
	return (rts);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = rdsv(fd, line);
	if (!line)
		return (NULL);
	buff = get_l(line);
	line = save(line);
	return (buff);
}
