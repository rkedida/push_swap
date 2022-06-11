/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:30:08 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/11 17:07:13 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_struct *head)
{
	reverse_rotate_last_becomes_first(&(head->l_a));
	ft_putstr("rra\n");
}

void	reverse_rotate_b(t_struct *head)
{
	reverse_rotate_last_becomes_first(&(head->l_b));
	ft_putstr("rrb\n");
}

void	reverse_rotate_a_b(t_struct *head)
{
	reverse_rotate_last_becomes_first(&(head->l_b));
	reverse_rotate_last_becomes_first(&(head->l_a));
	ft_putstr("rrr\n");
}
