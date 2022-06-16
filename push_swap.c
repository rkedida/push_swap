/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 02:47:51 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/16 04:19:18 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printer(t_list *tmp)
{
	t_list	*a;

	a = tmp;
	while (a)
	{
		printf("[%d] -> [%d] || ", a->num, a->i);
		a = a->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_struct	*type;

	type = malloc(sizeof(t_struct));
	if (ac > 1)
	{
		if (!parsing(type, ac, av))
			ft_error();
		ft_init_stacks(type);
		if (ac == 3)
			call_algo_2n(type, type->max_size);
		else if (ac == 4)
			call_algo_3n(type, 3);
		if (ac == 5)
			call_algo_4n(type, type->max_size);
		else if (ac == 6)
			call_algo_5n(type, type->max_size);
		else if (ac >= 7)
			call_sorting_algo(type);
		free(type->nbr);
		free_everything(type);
		free(type);
	}
	return (0);
}
