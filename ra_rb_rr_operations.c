/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:09:34 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/10 20:01:14 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_struct *head)
{
	rotate_top_becomes_last(&(head->l_a));
	if (head->print)
		ft_putstr("ra\n");
}

void	rotate_b(t_struct *head)
{
	rotate_top_becomes_last(&(head->l_b));
	if (head->print)
		ft_putstr("rb\n");
}

void	rotate_a_b(t_struct *head)
{
	rotate_top_becomes_last(&(head->l_a));
	rotate_top_becomes_last(&(head->l_b));
	if (head->print)
		ft_putstr("rr\n");
}
