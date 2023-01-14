/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:05:26 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/14 16:43:31 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			exit(0);
		}
		i++;
	}
}
int main(int ac, char **av)
{
	t_stack *stack_a;
	// t_stack *stack_b;
	if (ac > 1)
	{
		int i = 1;
		while (i < ac)
		{
			char **content = ft_split(av[i], ' ');
			int j = 0;
			while (content[j])
			{
				opener(content[j]);
				ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(content[j])));
				free(content[j]);
				j++;
			}
			free(content);
			i++;
		}
		t_stack *a;
		a = stack_a;
		while (a != NULL)
		{
			ft_printf("%d\n", a->content);
			a = a->next;
		}
		// system("leaks push_swap");
	}
}