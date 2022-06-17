/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:01:37 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/17 17:39:42 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*parseme(char **argv, int argc)
{
	int		i;
	char	*str;
	char	*temp;

	i = 1;
	temp = ft_strdup(" ");
	while (i < argc)
	{
		str = ft_strjoin(temp, argv[i]);
		if (temp)
			free (temp);
		temp = ft_strjoin(str, " ");
		if (str)
			free (str);
		i++;
	}
	return (temp);
}

unsigned int	ft_get_nb_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

int	check_char(char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 1;
	tmp = NULL;
	while (av[j])
	{
		i = 0;
		tmp = ft_strtrim(av[j], " ");
		if (*tmp == '\0')
			return (FALSE);
		while (av[j][i])
		{
			if (!ft_isdigit(av[j][i]) && av[j][i] != '-'
				&& av[j][i] != '+' && !ft_strchr(" \t\n\v\f\r", av[j][i]))
				return (FALSE);
			i++;
		}
		j++;
		free (tmp);
	}
	return (TRUE);
}
