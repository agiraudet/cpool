/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:23:43 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/27 13:36:01 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_ptr(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int i;

	if (!tab[0] || !tab[1])
		return ;
	i = 1;
	while (tab[i])
	{
		if ((*cmp)(tab[i - 1], tab[i]) > 0)
		{
			ft_swap_ptr(&tab[i - 1], &tab[i]);
			i = 0;
		}
		i++;
	}
}
