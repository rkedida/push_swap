/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 03:00:38 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/17 17:43:30 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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

// functions in clear_error_functions_bonus.c

void			ft_free_node(t_list **node);
void			free_everything(t_struct *type);
void			ft_putstr(char *str);
void			error(t_struct *type, int n);
void			deletestr(char	**a);

// functions in parsing_utils_bonus.c

void			helper_atoi(int *i, int *n, char *s, t_struct *head);
void			helper_atoi_2(char *str, int *i, t_struct *head);
void			helper_atoi_3(char *str, int *i, t_struct *head);
int				mod_atoi(char *str, t_struct *head);
int				ft_strcmp(char *s1, char *s2);

// functions in parsing_utils_2_bonus.c

char			*parseme(char **argv, int argc);
unsigned int	ft_get_nb_strs(char const *s, char c);
int				check_char(char **av);

// function in parsing_bonus.c

int				get_index(int num, t_list *node);
t_list			*ft_create_stack(int *indexarr, int count);
void			ft_init_stacks(t_struct *stacks);
void			check_doubles(char **av, int ac, t_struct *head);
int				parsing(t_struct *data, int ac, char **av);

// functions in stack_commands_bonus.c

void			swap_a_or_b(t_list **a);
void			push_a_or_b(t_list	**n1, t_list **n2);
void			rotate_top_becomes_last(t_list **head);
void			reverse_rotate_last_becomes_first(t_list **head);

//functions in sa_sb_ss_operations_bonus.c

void			swap_a(t_struct *head);
void			swap_b(t_struct *head);
void			swap_a_b(t_struct *head);

// functions in rra_rrb_rrr_operations_bonus.c

void			reverse_rotate_a(t_struct *head);
void			reverse_rotate_b(t_struct *head);
void			reverse_rotate_a_b(t_struct *head);

// functions in ra_rb_rr_operations_bonus.c

void			rotate_a(t_struct *head);
void			rotate_b(t_struct *head);
void			rotate_a_b(t_struct *head);

// functions in pa_pb_operations_bonus.c

void			push_a(t_struct *head);
void			push_b(t_struct *head);

// function in checker_bonus.c

int				is_sorted(t_struct *head);
void			checker(t_struct *head);
void			actions(char *tmp, t_struct *head);
void			ft_read_action(t_list *head);

#endif
