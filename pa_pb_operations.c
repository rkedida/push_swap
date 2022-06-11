/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:01:50 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/11 17:07:39 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_struct *head)
{
	push_a_or_b(&(head->l_b), &(head->l_a));
	ft_putstr("pa\n");
}

void	push_b(t_struct *head)
{
	push_a_or_b(&(head->l_a), &(head->l_b));
	ft_putstr("pb\n");
}