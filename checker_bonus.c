/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:18:02 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/19 03:06:33 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	checker(t_struct *head)
{
	char	*tmp;

	tmp = get_next_line(0);
	while (tmp)
	{
		actions(tmp, head);
		free(tmp);
		tmp = get_next_line(0);
	}
	free(tmp);
	if (is_sorted(head) == TRUE)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	actions(char *tmp, t_struct *head)
{
	if (ft_strncmp(tmp, "sa\n", 3) == 0)
		swap_a(head);
	else if (ft_strncmp(tmp, "sb\n", 3) == 0)
		swap_b(head);
	else if (ft_strncmp(tmp, "ss\n", 3) == 0)
		swap_a_or_b(&head->l_a);
	else if (ft_strncmp(tmp, "ra\n", 3) == 0)
		rotate_a(head);
	else if (ft_strncmp(tmp, "rb\n", 3) == 0)
		rotate_b(head);
	else if (ft_strncmp(tmp, "rr\n", 3) == 0)
		rotate_a_b(head);
	else if (ft_strncmp(tmp, "rra\n", 4) == 0)
		reverse_rotate_a(head);
	else if (ft_strncmp(tmp, "rrb\n", 4) == 0)
		reverse_rotate_b(head);
	else if (ft_strncmp(tmp, "rrr\n", 4) == 0)
		reverse_rotate_a_b(head);
	else if (ft_strncmp(tmp, "pa\n", 3) == 0)
		push_a(head);
	else if (ft_strncmp(tmp, "pb\n", 3) == 0)
		push_b(head);
	else
		error(head, 1);
}

int	main(int ac, char **av)
{
	t_struct	*type;
	char		**strs;
	char		*str;

	type = malloc(sizeof(t_struct));
	if (ac > 1)
	{
		if (check_char(av) == FALSE)
			error(type, 1);
		str = parseme(av, ac);
		check_string(str, type);
		strs = ft_split(str, ' ');
		if (!parsing(type, ft_get_nb_strs(str, ' '), strs))
			error(type, 1);
		ft_init_stacks(type);
		checker(type);
		free(str);
		deletestr(strs);
		free(type->nbr);
		free_everything(type);
		free(type);
	}
	return (0);
}
