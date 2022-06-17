/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:29:25 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/17 02:06:21 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_part_2(t_struct *head, t_sort *sort)
{
	while (head->l_b && head->l_b->i != sort->j)
	{
		if (head->l_b && head->l_b->i == sort->j - 2)
		{
			push_a(head);
			rotate_a(head);
		}
		else if (head->l_b && head->l_b->i == sort->j -1)
			push_a(head);
		else if (head->l_b->next && head->l_b->i != sort->j)
			reverse_rotate_b(head);
	}
}

void	sorting_part_3(t_struct *head, t_sort *sort)
{
	while (head->l_b && head->l_b->i != sort->j)
	{
		if (head->l_b && head->l_a && head->l_b->i == sort->j - 2)
		{
			push_a(head);
			rotate_a(head);
		}
		else if (head->l_b && head->l_a && head->l_b->i == sort->j -1)
			push_a(head);
		else if (head->l_b->next && head->l_b->i != sort->j)
			rotate_b(head);
	}
}

void	sorting_part_4(t_struct *head, t_sort *sort, t_struct tmp)
{
	if (head->l_b && head->l_b->i == sort->j)
	{
		push_a(head);
		sort->j--;
	}
	if (head->l_a && tmp.l_a && tmp.l_a->i == sort->j - 1
		&& head->l_a->next->i != sort->j)
		reverse_rotate_a(head);
	if (head->l_a && head->l_a->next && head->l_a->next->i == sort->j)
	{
		swap_a(head);
		sort->j--;
	}
	if (head->l_a && tmp.l_a && tmp.l_a->i == sort->j)
	{
		reverse_rotate_a(head);
		sort->j--;
	}
}

void	sorting_part(t_struct *head, t_sort *sort, t_struct tmp)
{
	while (head->l_b && sort->j >= 0)
	{
		tmp = *head;
		sort->i = 0;
		while (tmp.l_b->next != NULL && tmp.l_b->i != sort->j)
		{
			tmp.l_b = tmp.l_b->next;
			sort->i++;
		}
		if (sort->i > sort->j / 2 && tmp.l_b->i == sort->j)
			sorting_part_2(head, sort);
		else if (sort->i <= sort->j - sort->j / 2 && tmp.l_b->i == sort->j)
			sorting_part_3(head, sort);
		tmp = *head;
		while (tmp.l_a && tmp.l_a->next)
			tmp.l_a = tmp.l_a->next;
		sorting_part_4(head, sort, tmp);
	}
	free(sort);
}
