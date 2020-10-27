/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 09:43:36 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/20 10:20:15 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

long	ft_strlen(char *str)
{
	long i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_check_error(char *base, long base_size)
{
	int i;
	int j;

	i = 0;
	if (base_size <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_convert_base(long nbr, char *base, long base_size)
{
	if (nbr >= base_size)
	{
		ft_convert_base(nbr / base_size, base, base_size);
		ft_putchar(base[(nbr % base_size)]);
	}
	else
	{
		ft_putchar(base[nbr]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long base_size;
	long nb;

	nb = (long)nbr;
	base_size = ft_strlen(base);
	if (ft_check_error(base, base_size))
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		ft_convert_base(nb, base, base_size);
	}
}
