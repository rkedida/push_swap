/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 08:39:21 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/17 00:20:12 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	helper_atoi(int *i, int *n, char *s, t_struct *head)
{
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			(*n) = -(*n);
		if ((*s == '-' || *s == '+') && *s++ == '\0')
			error(head, 1);
		(*i)++;
		(*s)++;
	}
}

void	helper_atoi_2(char *str, int *i, t_struct *head)
{
	if ((str[*i] == '-' || str[*i] == '+') && !ft_isdigit(str[*i]))
		error(head, 1);
}

void	helper_atoi_3(char *str, int *i, t_struct *head)
{
	if (!ft_isdigit(str[*i]) && str[*i] == '-')
		error(head, 1);
}

int	mod_atoi(char *str, t_struct *head)
{
	int		i;
	int		n;
	long	res;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\v'
		|| str[i] == '\t' || str[i] == '\n' || str[i] == '\r')
			i++;
	helper_atoi(&i, &n, &str[i], head);
	helper_atoi_2(&str[i], &i, head);
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - 48;
		i++;
		if ((n == 1 && res * n > 2147483647)
			|| (n == -1 && res * n < -2147483648))
			error(head, 1);
	}
	helper_atoi_3(str, &i, head);
	if (n == -1)
		return ((int)(res * n));
	return ((int)(res * n));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}
