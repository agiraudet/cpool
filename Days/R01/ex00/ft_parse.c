/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 07:10:36 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/25 08:39:43 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"

int		ft_is_num(char c)
{
	return ((c >= '0' && c <= '9'));
}

int		ft_count_arg(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && ft_is_num(str[i]))
		{
			count++;
			while (str[i] && ft_is_num(str[i]))
				i++;
		}
	}
	return (count);
}

int		ft_small_atoi(char *str, int start, int end)
{
	int res;

	res = 0;
	if (start >= end)
		return (0);
	while (start < end)
	{
		if (ft_is_num(str[start]))
			res = res * 10 + (str[start] - '0');
		start++;
	}
	return (res);
}

int		*ft_parse_arg(char *str, int set_pos, int set_size)
{
	int	i;
	int j;
	int start;
	int count;
	int *tab;

	tab = (int *)malloc(set_size * (sizeof(int)));
	start = 0;
	count = 0;
	i = set_pos * (set_size * 2);
	j = 0;
	while (str[i] && count < set_size)
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && ft_is_num(str[i]))
		{
			start = i;
			count++;
			while (str[i] && ft_is_num(str[i]))
				i++;
			tab[j++] = ft_small_atoi(str, start, i);
		}
	}
	return (tab);
}

t_rules	ft_set_rules(char *str)
{
	int		start;
	int		set_size;
	int		total_size;
	t_rules	rule;

	start = 0;
	total_size = ft_count_arg(str);
	set_size = total_size / 4;
	rule.colup = ft_parse_arg(str, 0, set_size);
	rule.coldown = ft_parse_arg(str, 1, set_size);
	rule.rowleft = ft_parse_arg(str, 2, set_size);
	rule.rowright = ft_parse_arg(str, 3, set_size);
	rule.size = set_size;
	return (rule);
}
