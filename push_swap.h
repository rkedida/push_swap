/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 02:48:02 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/10 23:16:09 by rkedida          ###   ########.fr       */
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
	int				index;			//used in func ordered
	struct s_list	*next;
}						t_list;

typedef struct s_struct
{
	t_list	*l_a;
	t_list	*l_b;
	int		print;
	int		*nbr;
	// int		*indexing;
	int		max_size;
	int		value;
	// int		data;
}				t_struct;

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
void	sorting_algo(t_struct *head, int n);
int		is_sorted(t_struct *head);

#endif