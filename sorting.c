/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:26:00 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/15 00:48:48 by rkedida          ###   ########.fr       */
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

void	sorting_algo_5n(t_struct *head)
{
	int	len_b;

	len_b = 0;
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

// void	sorting_algo_500n(t_struct *head)
// {
// 	t_struct	*tmp;
// 	t_sort		*sort;
// 	tmp = head;
// 	sort = NULL;

// 	init_stack_var(sort, head);
// 	printf("hi\n");
// 	prepare_push_to_b(head, sort, tmp);
// 	(sort)->j = (sort)->total - 1;
// 	find_biggest_element_j(head, sort, tmp);
// 	push_b_to_a(head, sort);
// }

t_sort	*init_stack_var(t_struct *head)
{
	t_sort	*sort;

	sort = malloc(sizeof(t_sort));
	if (!(sort))
		exit(EXIT_FAILURE);
	(sort)->total = (head)->max_size;
	(sort)->j = (sort)->total / 19;
	(sort)->l = 19;
	(sort)->k = 0;
	(sort)->i = 0;
	(sort)->m = 1;
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

void	sorting_part_1(t_struct *head, t_sort *sort, t_struct tmp)
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
}


void	sorting_algo_500n(t_struct *head)
{
	t_sort	*sort;
	t_struct	tmp;

	tmp = *head;
	sort = init_stack_var(head);
	prepare_push_to_b(head, sort, tmp);
	sort->j = sort->total - 1;
	sorting_part_1(head, sort, tmp);
	// printf("A: ");
	// printer(head->l_a);
	// printf("\nB: ");
	// printer(head->l_b);
}



// void	sorting_algo_500n(t_struct *head)
// {
// 	int		total;
// 	t_struct	tmp;
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		l;
// 	int		m;

// 	total = head->max_size;
// 	j = total / 19;
// 	l = 19;
// 	k = 0;
// 	i = 0;
// 	m = 1;
// 	while (m <= l && head->l_a)
// 	{
// 		while (i <= total && head->l_a)
// 		{
// 			if (head->l_a && head->l_a->i < m * j)
// 			{
// 				push_b(head);
// 				k++;
// 			}
// 			else if (head->l_a && head->l_a->i < (m + 1) * j)
// 			{
// 				push_b(head);
// 				rotate_b(head);
// 				k++;
// 			}
// 			else if (head->l_a->next)
// 			{
// 				tmp = *head;
// 				while (tmp.l_a->next != NULL && tmp.l_a->i >= (m + 1) * j)
// 					tmp.l_a = tmp.l_a->next;
// 				if (tmp.l_a->next == NULL && tmp.l_a->i >= (m + 1) * j)
// 					break ;
// 				rotate_a(head);
// 			}
// 			if (k == total)
// 				break ;
// 			i++;
// 		}
// 		i = k;
// 		m = m + 2;
// 	}
// 	j = total - 1;
// 	while (head->l_b && j >= 0)
// 	{
// 		tmp = *head;
// 		i = 0;
// 		while (tmp.l_b->next != NULL && tmp.l_b->i != j)
// 		{
// 			tmp.l_b = tmp.l_b->next;
// 			i++;
// 		}
// 		if (i > j / 2 && tmp.l_b->i == j)
// 		{
// 			while (head->l_b && head->l_b->i != j)
// 			{
// 				if (head->l_b && head->l_b->i == j - 2)
// 				{
// 					push_a(head);
// 					rotate_a(head);
// 				}
// 				else if (head->l_b && head->l_b->i == j -1)
// 					push_a(head);
// 				else if (head->l_b->next && head->l_b->i != j)
// 					reverse_rotate_b(head);
// 			}
// 		}
// 		else if (i <= j - j / 2 && tmp.l_b->i == j)
// 		{
// 			while (head->l_b && head->l_b->i != j)
// 			{
// 				if (head->l_b && head->l_a && head->l_b->i == j - 2)
// 				{
// 					push_a(head);
// 					rotate_a(head);
// 				}
// 				else if (head->l_b && head->l_a && head->l_b->i == j -1)
// 					push_a(head);
// 				else if (head->l_b->next && head->l_b->i != j)
// 					rotate_b(head);
// 			}
// 		}
// 		tmp = *head;
// 		while (tmp.l_a && tmp.l_a->next)
// 			tmp.l_a = tmp.l_a->next;
// 		if (head->l_b && head->l_b->i == j)
// 		{
// 			push_a(head);
// 			j--;
// 		}
// 		if (head->l_a && tmp.l_a && tmp.l_a->i == j - 1 && head->l_a->next->i != j)
// 		{
// 			reverse_rotate_a(head);
// 			// swap_b(head);
// 		}
// 		if (head->l_a && head->l_a->next && head->l_a->next->i == j)
// 		{
// 			swap_a(head);
// 			j--;
// 		}
// 		if (head->l_a && tmp.l_a && tmp.l_a->i == j)
// 		{
// 			reverse_rotate_a(head);
// 			j--;
// 		}
// 	}
// 	// printf("A: ");
// 	// printer(head->l_a);
// 	// printf("\nB: ");
// 	// printer(head->l_b);
// }

void	call_algo_5n(t_struct *head, int size)
{
	if (is_sorted(head) == TRUE)
		return ;
	if (size == 5)
		sorting_algo_5n(head);
	printer(head->l_a);
}

void	call_algo_3n(t_struct *head, int size)
{
	if (is_sorted(head) == TRUE)
		return ;
	if (size == 3)
		sorting_algo_3n(head);
	printer(head->l_a);
}