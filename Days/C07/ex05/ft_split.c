/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:58:28 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/22 19:05:42 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_char_in_charset(char *charset, char c)
{
	int i;

	i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (1);
	return (0);
}

int		ft_count_strs(char *str, char *charset)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_char_in_charset(charset, str[i]))
			i++;
		if (str[i] && !ft_char_in_charset(charset, str[i]))
		{
			count++;
			while (str[i] && !ft_char_in_charset(charset, str[i]))
				i++;
		}
	}
	return (count);
}

char	*ft_ndup(char *str, int start, int end)
{
	char	*dup;
	int		i;

	dup = (char *)malloc((end - start + 1) * sizeof(char));
	i = 0;
	while (start + i < end)
	{
		dup[i] = str[start + i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		start;
	int		s;
	int		i;

	i = 0;
	s = 0;
	tab = (char **)malloc((ft_count_strs(str, charset) + 1) * sizeof(char *));
	while (str[i])
	{
		while (str[i] && ft_char_in_charset(charset, str[i]))
			i++;
		if (str[i] && !ft_char_in_charset(charset, str[i]))
		{
			start = i;
			while (str[i] && !ft_char_in_charset(charset, str[i]))
				i++;
			tab[s++] = ft_ndup(str, start, i);
		}
	}
	tab[s] = 0;
	return (tab);
}
