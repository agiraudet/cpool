/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:45:52 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/20 12:23:57 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	char c;

	while (*str)
	{
		c = *str++;
		write(1, &c, 1);
	}
	c = '\n';
	write(1, &c, 1);
}

int		ft_biggest(char **tab, int size)
{
	int i;
	int j;
	int biggest;

	i = 1;
	biggest = 1;
	while (i < size)
	{
		j = 0;
		while (tab[i][j] == tab[biggest][j])
		{
			if (!tab[i][j] || !tab[biggest][j])
				break ;
			j++;
		}
		biggest = tab[i][j] > tab[biggest][j] ? i : biggest;
		i++;
	}
	return (biggest);
}

void	ft_swap(char **tab, int index_a, int index_b)
{
	char *c;

	c = tab[index_a];
	tab[index_a] = tab[index_b];
	tab[index_b] = c;
}

void	ft_sort_tab(char **tab, int size)
{
	int biggest;

	while (size > 2)
	{
		biggest = ft_biggest(tab, size);
		if (biggest != size - 1)
			ft_swap(tab, biggest, size - 1);
		size--;
	}
}

int		main(int argc, char **argv)
{
	int i;

	if (argc > 1)
		ft_sort_tab(argv, argc);
	i = 1;
	while (i < argc)
		ft_putstr(argv[i++]);
}
