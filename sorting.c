/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:26:00 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/11 21:11:41 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_struct *head)
{
	int		i;
	t_list	*l;

	i = 0;
	l = head->l_a;
	while (l && l->next)
	{	
		if (l->i == l->next->i - 1)
			i++;
		l = l->next;
	}
	if (i == head->max_size - 1)
		return (1);
	return (0);
}

void	sorting_algo_3n(t_struct *head, int size)
{
	t_list	*tmp;

	tmp = head->l_a;
	if (is_sorted(head))
		return ;
	if (size == 3)
	{
		if (tmp->i > tmp->next->i && tmp->i == tmp->next->next->i - 1)
			swap_a(head);
		else if (tmp->i > tmp->next->i && tmp->i == tmp->next->next->i + 2)
		{
			swap_a(head);
			reverse_rotate_a(head);
		}
		else if (tmp->i > tmp->next->i && tmp->next->i < tmp->next->next->i)
			rotate_a(head);
		else if (tmp->i +2 == tmp->next->i && tmp->i +1 == tmp->next->next->i)
		{
			swap_a(head);
			rotate_a(head);
		}
		else if (tmp->i < tmp->next->i && tmp->next->i > tmp->next->next->i +1)
			reverse_rotate_a(head);
	}
}

int	find_small_n(int size)
{
	t_list		*list;
	int			find;
	int			j;

	find = 0;
	j = 0;
	while (j < size -1 && list)
	{
		if (find == list->i)
			break ;
		j++;
		list = list->next;
	}
	return (j);
}

int	find_big_n(int size)
{
	t_list		*list;
	int			find;
	int			j;

	find = 4;
	j = 0;
	while (j < size -1 && list)
	{
		if (find == list->i)
			break ;
		j++;
		list = list->next;
	}
	return (j);
}

void	push_to_b(t_struct *head)
{
	int	small;
	int	big;

	small = find_small_n(head->max_size);
	big = find_big_n(head->max_size);
	printf("%d -- %d\n", small, big);
	if (big <= 2 || small <= 2)
	{
		rotate_a(head);
		swap_a(head);
	}
	if (small > 2 || big > 2)
	{
		reverse_rotate_a(head);
		reverse_rotate_a(head);
	}
	// if (small == head->l_a->i && big == head->l_a->i)
	// {
	// 	push_b(head);
	// 	push_b(head);
	// }
	
}

// void	sorting_algo_5n(t_struct *head, int size)
// {
// 	t_list	*tmp;

// 	tmp = head->l_a;
// 	if (is_sorted(head))
// 		return ;
// 	if (size == 5)
// 	{
// 		if (tmp->i < tmp->next->i && tmp->i == tmp->next->i - 4)
// 		{	
// 			push_b(head);
// 			push_b(head);
// 			sorting_algo_3n(head, 3);
// 			push_a(head);
// 			rotate_a(head);
// 			push_a(head);
// 		}
// 		if (tmp->i > tmp->next->i && tmp->i == tmp->next->i + 4)
// 		{
// 			swap_a(head);
// 			push_b(head);
// 			push_b(head);
// 			sorting_algo_3n(head, 3);
// 			push_a(head);
// 			rotate_a(head);
// 			push_a(head);
// 		}
// 	}
// }
