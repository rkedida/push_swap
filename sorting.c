/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:26:00 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/11 00:54:45 by rkedida          ###   ########.fr       */
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

// int	check_if_sorted(t_struct **head)
// {
// 	t_list	*tmp;
// 	int		i;

// 	i = 0;
// 	tmp = (*head)->l_a;
// 	while (tmp && tmp->next)
// 	{
// 		if (tmp->num < tmp->next->num)
// 			return (0);
// 		tmp = tmp->next;
// 	}
// 	return (1);
// }

void	sorting_algo(t_struct *head, int size)
{
	t_list	*tmp;

	tmp = head->l_a;
	if (is_sorted(head))
		return ;
	if (size == 3)
	{
		if (tmp->i > tmp->next->i && tmp->i == tmp->next->next->i - 1)
			swap_a(head);
		// else if (tmp->i > tmp->next && )
		else if (tmp->i > tmp->next->i && tmp->next->i < tmp->next->next->i)
			rotate_a(head);
		else if (tmp->i < tmp->next->i && tmp->next->i > tmp->next->next->i +1)
			reverse_rotate_a(head);
	}
}