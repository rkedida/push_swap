/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_operations_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:47:15 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/17 03:52:02 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_a(t_struct *head)
{
	swap_a_or_b(&(head->l_a));
}

void	swap_b(t_struct *head)
{
	swap_a_or_b(&(head->l_b));
}

void	swap_a_b(t_struct *head)
{
	swap_a_or_b(&(head->l_a));
	swap_a_or_b(&(head->l_b));
}
