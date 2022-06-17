/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:26:00 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/16 04:54:07 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_struct *head)
{
	t_list	*list;

	list = head->l_a;
	while (list && list->next)
	{
		if (list->num > list->next->num)
			return (FALSE);
		list = list->next;
	}
	return (TRUE);
}

void	sorting_algo_2n(t_struct *head)
{
	t_list	*tmp;

	tmp = head->l_a;
	if (is_sorted(head) == TRUE)
		return ;
	else if (tmp->num > tmp->next->num)
		swap_a(head);
}

void	sorting_algo_3n(t_struct *head)
{
	t_list	*tmp;

	tmp = head->l_a;
	if (is_sorted(head) == TRUE)
		return ;
	if (tmp->num > tmp->next->num && tmp->num < tmp->next->next->num)
		swap_a(head);
	else if (tmp->num > tmp->next->num
		&& tmp->next->num > tmp->next->next->num)
	{
		swap_a(head);
		reverse_rotate_a(head);
	}
	else if (tmp->num > tmp->next->num && tmp->num > tmp->next->next->num)
		rotate_a(head);
	else if (tmp->num < tmp->next->num && tmp->num < tmp->next->next->num)
	{
		swap_a(head);
		rotate_a(head);
	}
	else if (tmp->num < tmp->next->num && tmp->num > tmp->next->next->num)
		reverse_rotate_a(head);
}

void	sorting_algo_4n(t_struct *head)
{
	t_list	*tmp;
	int		count;

	count = 0;
	if (is_sorted(head) == TRUE)
		return ;
	while (count < 4)
	{
		tmp = head->l_a;
		if (tmp->i == 0)
			push_b(head);
		else if (tmp->i != 0)
			rotate_a(head);
		count++;
	}
	sorting_algo_3n(head);
	push_a(head);
}

void	sorting_algo_5n(t_struct *head)
{
	int	len_b;

	len_b = 0;
	if (is_sorted(head) == TRUE)
		return ;
	while (len_b < 2)
	{
		if (head->l_a->i < 2)
		{
			push_b(head);
			len_b++;
		}
		else
			rotate_a(head);
	}
	if (is_sorted(head) == FALSE)
		sorting_algo_3n(head);
	if (head->l_b->num < head->l_b->next->num)
		swap_b(head);
	push_a(head);
	push_a(head);
}
