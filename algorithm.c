/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:12:25 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/18 21:14:46 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_struct *type, char *str)
{
	if (ft_get_nb_strs(str, ' ') == 2)
		call_algo_2n(type, type->max_size);
	else if (ft_get_nb_strs(str, ' ') == 3)
		call_algo_3n(type, 3);
	else if (ft_get_nb_strs(str, ' ') == 4)
		call_algo_4n(type, type->max_size);
	else if (ft_get_nb_strs(str, ' ') == 5)
		call_algo_5n(type, type->max_size);
	else if (ft_get_nb_strs(str, ' ') >= 6)
		call_sorting_algo(type);
}
