/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 08:39:21 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/19 03:04:45 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_string(char *str, t_struct *type)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
			error(type, 1);
		i++;
	}
}

int	string_has_only_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	helper_atoi(int *i, int *n, char *s, t_struct *head)
{
	if (*s == '-' || *s == '+')
		(*i)++;
	if (*s == '-')
		(*n) = -(*n);
	if (*s == '-' && *s++ == '\0')
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
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - 48;
		i++;
		if ((n == 1 && res * n > 2147483647)
			|| (n == -1 && res * n < -2147483648))
			error(head, 1);
	}
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
