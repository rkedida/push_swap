/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 02:48:02 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/17 17:52:19 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define TRUE	1
# define FALSE	0

typedef struct s_list
{
	int				num;
	int				i;
	struct s_list	*next;
}					t_list;

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
}				t_sort;

// functions in clear_error_functions.c

void			ft_free_node(t_list **node);
void			free_everything(t_struct *type);
void			ft_putstr(char *str);
void			error(t_struct *type, int n);
void			deletestr(char	**a);

// functions in parsing_utils.c

void			helper_atoi(int *i, int *n, char *s, t_struct *head);
void			helper_atoi_2(char *str, int *i, t_struct *head);
void			helper_atoi_3(char *str, int *i, t_struct *head);
int				mod_atoi(char *str, t_struct *head);
int				ft_strcmp(char *s1, char *s2);

// functions in parsing_utils_2.c

char			*parseme(char **argv, int argc);
unsigned int	ft_get_nb_strs(char const *s, char c);
int				check_char(char **av);

// function in parsing.c

int				get_index(int num, t_list *node);
t_list			*ft_create_stack(int *indexarr, int count);
void			ft_init_stacks(t_struct *stacks);
void			check_doubles(char **av, int ac, t_struct *head);
int				parsing(t_struct *data, int ac, char **av);

// functions in stack_commands.c

void			swap_a_or_b(t_list **a);
void			push_a_or_b(t_list	**n1, t_list **n2);
void			rotate_top_becomes_last(t_list **head);
void			reverse_rotate_last_becomes_first(t_list **head);

//functions in sa_sb_ss_operations.c

void			swap_a(t_struct *head);
void			swap_b(t_struct *head);
void			swap_a_b(t_struct *head);

// functions in rra_rrb_rrr_operations.c

void			reverse_rotate_a(t_struct *head);
void			reverse_rotate_b(t_struct *head);
void			reverse_rotate_a_b(t_struct *head);

// functions in ra_rb_rr_operations.c

void			rotate_a(t_struct *head);
void			rotate_b(t_struct *head);
void			rotate_a_b(t_struct *head);

// functions in pa_pb_operations.c

void			push_a(t_struct *head);
void			push_b(t_struct *head);

// functions in sorting_1.c

int				is_sorted(t_struct *head);
void			sorting_algo_2n(t_struct *head);
void			sorting_algo_3n(t_struct *head);
void			sorting_algo_4n(t_struct *head);
void			sorting_algo_5n(t_struct *head);

// function in sorting_2.c

t_sort			*init_stack_var(t_struct *head);
t_sort			*init_stack_chunks(t_struct *head, t_sort *sort);
void			prepare_part_2(t_struct *head, t_sort *sort);
void			prepare_part_3(t_struct *head, t_sort *sort);
void			prepare_push_to_b(t_struct *head, t_sort *sort, t_struct tmp);

// function in sorting_3.c

void			sorting_part_2(t_struct *head, t_sort *sort);
void			sorting_part_3(t_struct *head, t_sort *sort);
void			sorting_part_4(t_struct *head, t_sort *sort, t_struct tmp);
void			sorting_part(t_struct *head, t_sort *sort, t_struct tmp);

// function in call_sort_algos.c

void			call_algo_2n(t_struct *head, int size);
void			call_algo_3n(t_struct *head, int size);
void			call_algo_4n(t_struct *head, int size);
void			call_algo_5n(t_struct *head, int size);
void			call_sorting_algo(t_struct *head);

// functions in algorithm.c

void			algorithm(t_struct *type, char *str);

#endif
