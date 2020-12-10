/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:52:54 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/27 13:35:39 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_ptr(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int i;

	if (!tab[0] || !tab[1])
		return ;
	i = 1;
	while (tab[i])
	{
		if (ft_strcmp(tab[i - 1], tab[i]) > 0)
		{
			ft_swap_ptr(&tab[i - 1], &tab[i]);
			i = 0;
		}
		i++;
	}
}
