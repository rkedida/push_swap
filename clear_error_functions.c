/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_error_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:31:40 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/09 21:02:43 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_node(t_list **node)
{
	t_list	*tmp;
	t_list	*head;

	head = *node;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	*node = NULL;
}

void	free_everything(t_struct *type)
{
	ft_free_node(&(type->l_a));
	ft_free_node(&(type->l_b));
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	error(t_struct *type, int n)
{
	write(2, "Error\n", 6);
	if (n == 1)
		free_everything(type);
	exit(EXIT_FAILURE);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
