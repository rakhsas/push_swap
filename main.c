/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:05:26 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/27 15:56:23 by rakhsas          ###   ########.fr       */
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

void	check(char *str)
{
	if (ft_specific_len(str, ' ') == ft_strlen(str))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	ft_duplicate(t_stack *stack_a)
{
	t_stack	*c;
	int		array[100];
	int		da;
	int		y;
	int		b;

	c = stack_a;
	da = 0;
	y = 0;
	b = 0;
	while (c != NULL)
	{
		array[da++] = c->content;
		c = c->next;
	}
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

void	ft_next_main(t_stack **stack, t_stack **b)
{
	t_stack	*a;

	a = *stack;
	if (ft_lstsize(a) == 2)
		swap_2(a, 0);
	else if (ft_lstsize(a) == 3)
	{
		check_for_3_args(&a);
		exit(0);
	}
	else if (ft_lstsize(a) > 3)
		check_for_5_args(&a, b, ft_lstsize(a), check_for_min(a));
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	// t_stack	*st;
	t_stack	*b;
	int		i;
	char	**content;
	int		j;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			check(av[i]);
			content = ft_split(av[i], ' ');
			j = 0;
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
		ft_duplicate(stack_a);
		if (ft_not_sorted(stack_a))
		{
			ft_next_main(&stack_a, &b);
		}
		// 	// st = stack_a;

		// 	// while (stack_a->next)
		// 	// {
		// 	// 	stack_a = stack_a->next;
		// 	// }
		// rr_a_b(&stack_a, 0);
		// printf("%d->\n", stack_a->content);

		system("leaks push_swap");
	}

}
