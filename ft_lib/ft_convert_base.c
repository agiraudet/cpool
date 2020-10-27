/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 08:50:42 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/22 12:14:46 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long	ft_base_to_dec(char *str, char *base);
void	ft_dec_to_base(long nbr, int sign, char *base, char *result);
int		ft_atoi_base(char *str, char *base, char *nbrclean);

int		ft_isspace(char c)
{
	return (((c > 8 && c < 14) || c == ' '));
}

void	ft_rev_str(char *str)
{
	int		i;
	int		strlen;
	char	tmp;

	strlen = 0;
	while (str[strlen])
		strlen++;
	i = 0;
	while (i < strlen / 2)
	{
		tmp = str[i];
		str[i] = str[strlen - i - 1];
		str[strlen - i - 1] = tmp;
		i++;
	}
}

int		ft_check_error(char *base)
{
	int basesize;
	int i;
	int j;

	basesize = 0;
	while (base[basesize])
		basesize++;
	if (basesize <= 1)
		return (0);
	i = 0;
	while (i < basesize)
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		j = 0;
		while (j < basesize && j != i)
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	nbr_clean[33];
	char	*nbr_base_to;
	int		sign;
	long	nbr_dec;

	if (!ft_check_error(base_from) || !ft_check_error(base_to))
	{
		nbr_base_to = 0;
		return (nbr_base_to);
	}
	nbr_base_to = (char *)malloc(33 * sizeof(char));
	sign = ft_atoi_base(nbr, base_from, nbr_clean);
	nbr_dec = ft_base_to_dec(nbr_clean, base_from);
	ft_dec_to_base(nbr_dec, sign, base_to, nbr_base_to);
	ft_rev_str(nbr_base_to);
	return (nbr_base_to);
}
