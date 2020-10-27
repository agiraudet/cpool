/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 09:22:27 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/17 13:24:16 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	int_to_hex(int x)
{
	if (x <= 9)
	{
		return (x + 48);
	}
	return (x + 87);
}

void	ft_char_to_hex(char c)
{
	char	str[4];
	int		i;

	str[1] = '0';
	str[3] = '\0';
	str[0] = '\\';
	i = 3;
	while (c > 0)
	{
		str[--i] = int_to_hex(c % 16);
		c /= 16;
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i++]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 32 && str[i] <= 126))
		{
			ft_putchar(str[i]);
		}
		else
		{
			ft_char_to_hex(str[i]);
		}
		i++;
	}
}
