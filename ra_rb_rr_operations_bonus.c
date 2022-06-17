/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_operations_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:09:34 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/17 03:44:13 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rotate_a(t_struct *head)
{
	rotate_top_becomes_last(&(head->l_a));
}

void	rotate_b(t_struct *head)
{
	rotate_top_becomes_last(&(head->l_b));
}

void	rotate_a_b(t_struct *head)
{
	rotate_top_becomes_last(&(head->l_a));
	rotate_top_becomes_last(&(head->l_b));
}
