/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 08:45:02 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/19 13:23:18 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnumber(char c)
{
	return ((c >= '0' && c <= '9'));
}

int	ft_isspace(char c)
{
	return (((c > 8 && c < 14) || c == ' '));
}

int	ft_atoi(char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isnumber(str[i]))
	{
		result = (str[i] - '0') + result * 10;
		i++;
	}
	return (result * sign);
}
