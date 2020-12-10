/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 07:28:38 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/27 18:14:13 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort_up(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 1;
	while (i < length)
	{
		if (((*f)(tab[i - 1], tab[i])) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort_down(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 1;
	while (i < length)
	{
		if (((*f)(tab[i - 1], tab[i])) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	return (ft_is_sort_up(tab, length, f) || ft_is_sort_down(tab, length, f));
}
