/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 02:48:02 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/15 00:51:02 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

#define TRUE 	1
#define FALSE 	0

// circula linked list NODE

typedef struct s_list
{
	int				num;			//used in func check_string
	int				i;			//used in func ordered
	struct s_list	*next;
}						t_list;

typedef struct s_struct
{
	t_list		*l_a;
	t_list		*l_b;
	int			*nbr;
	int			max_size;
}				t_struct;

typedef struct s_sort
{
	int			total;
	int			i;
	int			j;
	int			k;
	int			l;
	int			m;
	// t_struct	*tmp;
}				t_sort;

// functions in clear_error_functions.c

void	ft_free_node(t_list **node);
void	free_everything(t_struct *type);
void	ft_putstr(char *str);
void	error(t_struct *type, int n);
void	ft_error(void);

// functions in stack_commands.c

void	swap_a_or_b(t_list **a);
void	push_a_or_b(t_list	**n1, t_list **n2);
void	rotate_top_becomes_last(t_list **head);
void	reverse_rotate_last_becomes_first(t_list **head);

//functions in sa_sb_ss_operations.c

void	swap_a(t_struct *head);
void	swap_b(t_struct *head);
void	swap_a_b(t_struct *head);

// functions in rra_rrb_rrr_operations.c

void	reverse_rotate_a(t_struct *head);
void	reverse_rotate_b(t_struct *head);
void	reverse_rotate_a_b(t_struct *head);

// functions in ra_rb_rr_operations.c

void	rotate_a(t_struct *head);
void	rotate_b(t_struct *head);
void	rotate_a_b(t_struct *head);

// functions in pa_pb_operations.c

void	push_a(t_struct *head);
void	push_b(t_struct *head);

// functions in sorting.c

// int		check_if_sorted(t_struct **head);
void	sorting_algo_3n(t_struct *head);
void	call_algo_5n(t_struct *head, int size);
int		is_sorted(t_struct *head);
void	sorting_algo_5n(t_struct *head);
void	call_algo_3n(t_struct *head, int size);
void	printer(t_list *tmp);
// void	sorting_algo_500n(t_struct *head);
void	sorting_algo_500n(t_struct *head);
// void	prepare_push_to_b(t_struct *head, t_sort *sort, t_struct *tmp);
// void	init_stack_var(t_sort *sort, t_struct *head);
// void	find_biggest_element_j(t_struct *head, t_sort *sort);
// void	find_biggest_element_j_2(t_struct *head, t_sort *sort);
// void	push_b_to_a(t_struct *head, t_sort *sort);
// void	push_b_to_a_2(t_struct *head, t_sort *sort);
// void	prepare_part_2(t_struct *head);
// void	prepare_part_3(t_struct *head, t_sort *sort, t_struct *tmp);

t_sort	*init_stack_var(t_struct *head);
void	prepare_push_to_b(t_struct *head, t_sort *sort, t_struct tmp);
void	prepare_part_2(t_struct *head, t_sort *sort);
void	prepare_part_3(t_struct *head, t_sort *sort);
void	sorting_part_1(t_struct *head, t_sort *sort, t_struct tmp);
void	sorting_part_2(t_struct *head, t_sort *sort);
void	sorting_part_3(t_struct *head, t_sort *sort);
void	sorting_part_4(t_struct *head, t_sort *sort, t_struct tmp);

#endif