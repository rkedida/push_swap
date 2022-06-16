/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:06:34 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/16 04:18:24 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sort	*init_stack_var(t_struct *head)
{
	t_sort	*sort;

	sort = malloc(sizeof(t_sort));
	if (!sort)
		exit(EXIT_FAILURE);
	sort->total = (head)->max_size;
	sort->j = (sort)->total / 19;
	sort->l = 19;
	sort->k = 0;
	sort->i = 0;
	sort->m = 1;
	return (sort);
}

t_sort	*init_stack_chunks(t_struct *head, t_sort *sort)
{
	int	total;

	total = head->max_size;
	if (total < 10)
	{
		sort->j = sort->total / 3;
		sort->l = 3;
	}
	else if (total < 50)
	{
		sort->j = sort->total / 5;
		sort->l = 5;
	}
	else if (total > 50)
	{
		sort->j = sort->total / 11;
		sort->l = 11;
	}
	else if (total >= 250)
	{
		sort->j = sort->total / 19;
		sort->l = 19;
	}
	return (sort);
}

void	prepare_part_2(t_struct *head, t_sort *sort)
{
	push_b(head);
	sort->k++;
}

void	prepare_part_3(t_struct *head, t_sort *sort)
{
	push_b(head);
	rotate_b(head);
	sort->k++;
}

void	prepare_push_to_b(t_struct *head, t_sort *sort, t_struct tmp)
{
	while (sort->m <= sort->l && head->l_a)
	{
		while (sort->i <= sort->total && head->l_a)
		{
			if (head->l_a && head->l_a->i < sort->m * sort->j)
				prepare_part_2(head, sort);
			else if (head->l_a && head->l_a->i < (sort->m + 1) * sort->j)
				prepare_part_3(head, sort);
			else if (head->l_a->next)
			{
				while (tmp.l_a->next != NULL
					&& tmp.l_a->i >= (sort->m + 1) * sort->j)
					tmp.l_a = tmp.l_a->next;
				if (tmp.l_a->next == NULL
					&& tmp.l_a->i >= (sort->m + 1) * sort->j)
					break ;
				rotate_a(head);
			}
			if (sort->k == sort->total)
				break ;
			sort->i++;
		}
		sort->i = sort->k;
		sort->m = sort->m + 2;
	}
}
