/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 02:47:51 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/17 17:48:44 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		strs = ft_split(str, ' ');
		if (!parsing(type, ft_get_nb_strs(str, ' '), strs))
			error(type, 1);
		ft_init_stacks(type);
		algorithm(type, str);
		free(str);
		deletestr(strs);
		free(type->nbr);
		free_everything(type);
		free(type);
	}
	return (0);
}
