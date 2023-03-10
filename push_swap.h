/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:20:49 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/07 19:00:58 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				index;
}	t_stack;
typedef struct s_tab
{
	int	offset;
	int	middle;
	int	start;
	int	end;
	int	*arr;
	int	size;
	int	size_copy;
	int	down;
	int	max;
	int	array_size;
	int	n;
}	t_tab;
void	ft_error(void);
void	ft_lstclear(t_stack **lst);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_exist(t_stack *b, int max);
int		returnwhere(t_tab *tab, t_stack **stack_b);
void	sort_more_than_five_args(t_stack **stack_a, t_stack **stack_b);
char	**ft_split(char *s, char c);
char	*ft_itoa(int num);
void	sort_array(int *arr, int len);
long	ft_atoi(const char *str);
int		ft_not_sorted(t_stack *stack_a);
int		function(t_tab *c, t_stack *stack_b);
int		in_range(int content, int *arr, int start, int end);
int		ft_specific_len(char *str, char c);
int		ft_strlen(char *str);
int		ft_isdigit(int c);
int		ft_lstsize(t_stack *lst);
int		ft_not_sorted(t_stack *stack_a);
int		check_for_min(t_stack *a);
int		check_for_max(t_stack *a);
char	*ft_strdup(char *s);
void	ft_fill_tab(t_stack **b, t_tab *c);
void	bubble_sort(int *tab, int size);
void	ft_duplicate(t_stack *stack_a);
void	opener(char *str);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst);
void	ss(t_stack *A, t_stack *B, int i);
void	push_2(t_stack **a, t_stack **b, int n);
void	r_a_b(t_stack **a, int i);
void	rr(t_stack *a, t_stack *b, int n);
void	rr_a_b(t_stack **head, int i);
void	swap_2(t_stack *a, int i);
void	check(char *str);
void	ft_swap(int *i, int *j);
void	check_for_3_args(t_stack **a);
void	check_for_5_args(t_stack **a, t_stack **b, int len, int min);
void	rrr(t_stack *a, t_stack *b, int n);
// GET NEXT LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

int		check_newline(char *str);

char	*get_next_line(int fd);
char	*free_it(char *str);
char	*free_line(char *str);
char	*str_join(char *str, char *rts);
char	*get_l(char *save);
char	*save(char *save);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
#endif
