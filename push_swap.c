/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkedida <rkedida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 02:47:51 by rkedida           #+#    #+#             */
/*   Updated: 2022/06/11 20:52:49 by rkedida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printer(t_list *tmp)
{
	t_list	*a;

	a = tmp;
	while (a)
	{
		printf("[%d] -> [%d] || ", a->num, a->i);
		a = a->next;
	}
	printf("\n");
}

int	mod_atoi(char *str)
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
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	// if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i]))
	// 	ft_error();
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - 48;
		i++;
		if ((n == 1 && res > 2147483647) || (n == -1 && res > -2147483648))
			ft_error();
	}
	if (n == -1)
		return ((int)(-res * n));
	return ((int)(res * n));
}

int	get_index(int num, t_list *node)
{
	t_list		*tmp;
	int			index;

	tmp = node;
	index = 0;
	while (node)
	{
		if (num > node->num)
		{
			index++;
		}
		node = node->next;
	}
	return (index);
}

t_list	*ft_create_stack(int *indexarr, int count)
{
	int			i;
	t_list		*new_node;
	t_list		*curr;

	i = 0;
	new_node = malloc(sizeof(t_list));
	curr = new_node;
	while (i < count)
	{
		if (i < count - 1)
			new_node->next = malloc(sizeof(t_list));
		new_node->num = indexarr[i];
		new_node->i = 0;
		if (i == (count - 1))
			new_node->next = NULL;
		else
			new_node = new_node->next;
		i++;
	}
	new_node = curr;
	while (new_node)
	{
		new_node->i = get_index(new_node->num, curr);
		new_node = new_node->next;
	}
	return (curr);
}

void	ft_init_stacks(t_struct *stacks)
{
	stacks->l_a = ft_create_stack(stacks->nbr, stacks->max_size);
	stacks->l_b = NULL;
}

int		ft_strcmp(char *s1, char *s2)
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

void	check_doubles(char **av, int ac)
{
	int			i;
	int			j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				ft_error();
			j++;
		}
		i++;
	}
}

int	parsing(t_struct *data, int ac, char **av)
{
	int		i;
	int		j;
	int		*tmp;

	i = 1;
	j = 0;
	check_doubles(av, ac);
	tmp = malloc((sizeof(int) * (ac - 1)));
	while (i < ac)
	{
		if (!ft_isdigit(av[i][j]) && av[i][j] != '+'
				&& av[i][j] != '-')
			ft_error();
		tmp[i - 1] = mod_atoi(av[i]);
		if (tmp[i - 1] == 0 && ft_strlen(av[i]) != 1)
			return (0);
		i++;
	}
	data->max_size = ac - 1;
	data->nbr = tmp;
	return (TRUE);
}

int main(int ac, char **av)
{
	t_struct	*type;

	type = malloc(sizeof(t_struct));
	if (ac > 1)
	{
		if (!parsing(type, ac, av))
			ft_error();
		ft_init_stacks(type);
		if (ac == 4)
			sorting_algo_3n(type, type->max_size);
		push_to_b(type);
		// if (ac == 6)
		// 	sorting_algo_5n(type, type->max_size);
		printer(type->l_a);
	}
	return (0);
}