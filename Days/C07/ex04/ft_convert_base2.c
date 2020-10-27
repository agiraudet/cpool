/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 08:28:19 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/22 12:14:33 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_get_index(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	if (power)
		return (nb * ft_pow(nb, power - 1));
	return (1);
}

long	ft_base_to_dec(char *str, char *base)
{
	int		basesize;
	long	res;
	int		i;
	int		nbrsize;

	res = 0;
	basesize = 0;
	i = 0;
	nbrsize = 0;
	while (str[nbrsize])
		nbrsize++;
	while (base[basesize])
		basesize++;
	while (str[i])
	{
		res += ft_get_index(base, str[i]) * ft_pow(basesize, nbrsize - i - 1);
		i++;
	}
	res = res < 0 ? -res : res;
	return (res);
}

void	ft_dec_to_base(long nbr, int sign, char *base, char *result)
{
	int	basesize;
	int nbr_is_zero;
	int i;

	basesize = 0;
	nbr_is_zero = nbr == 0 ? 1 : 0;
	while (base[basesize])
		basesize++;
	i = 0;
	while (nbr >= basesize)
	{
		result[i++] = base[nbr % basesize];
		nbr /= basesize;
	}
	result[i++] = base[nbr % basesize];
	if (sign < 0 && !nbr_is_zero)
		result[i++] = '-';
	result[i] = '\0';
}

int		ft_atoi_base(char *str, char *base, char *nbrclean)
{
	int i;
	int start;
	int sign;

	i = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		sign = str[i++] == '-' ? sign * -1 : sign;
	start = i;
	while (ft_get_index(base, str[i]) >= 0)
	{
		nbrclean[i - start] = str[i];
		i++;
	}
	nbrclean[i - start] = '\0';
	return (sign);
}
