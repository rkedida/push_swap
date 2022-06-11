/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:47:15 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/11 17:06:08 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_struct *head)
{
	swap_a_or_b(&(head->l_a));
	ft_putstr("sa\n");
}

void	swap_b(t_struct *head)
{
	swap_a_or_b(&(head->l_b));
	ft_putstr("sb\n");
}

void	swap_a_b(t_struct *head)
{
	swap_a_or_b(&(head->l_a));
	swap_a_or_b(&(head->l_b));
	ft_putstr("ss\n");
}
