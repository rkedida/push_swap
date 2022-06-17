/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr_operations_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:30:08 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/17 03:52:10 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	reverse_rotate_a(t_struct *head)
{
	reverse_rotate_last_becomes_first(&(head->l_a));
}

void	reverse_rotate_b(t_struct *head)
{
	reverse_rotate_last_becomes_first(&(head->l_b));
}

void	reverse_rotate_a_b(t_struct *head)
{
	reverse_rotate_last_becomes_first(&(head->l_b));
	reverse_rotate_last_becomes_first(&(head->l_a));
}
