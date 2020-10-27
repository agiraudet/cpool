/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 07:49:48 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/19 11:02:02 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_index(char *str, char c)
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

int	pwr(int base, int exp)
{
	int res;

	res = 1;
	while (exp > 1)
	{
		res *= base;
		exp--;
	}
	return (res);
}

int	ft_check_error(char *base)
{
	int sane;
	int basesize;
	int i;
	int index;

	sane = 1;
	i = 0;
	basesize = 0;
	while (base[basesize] && basesize < 2)
		basesize++;
	if (basesize <= 1)
		sane = 0;
	while (base[i])
	{
		if (((base[i] > 8 && base[i] < 14) || base[i] == ' '))
			sane = 0;
		if (base[i] == '+' || base[i] == '-')
			sane = 0;
		index = get_index(base, base[i]);
		if (index != i)
			sane = 0;
		i++;
	}
	return (sane);
}

int	ft_convert_base(char *str, char *base, int i, int end)
{
	int basesize;
	int res;
	int strlen;

	res = 0;
	basesize = 0;
	strlen = 0;
	while (base[basesize])
		basesize++;
	while (str[i] && i < end)
	{
		res += get_index(base, str[i]) * pwr(basesize, end - i);
		i++;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int	start;
	int res;

	i = 0;
	sign = 1;
	if (!ft_check_error(base))
		return (0);
	while (((str[i] > 8 && str[i] < 14) || str[i] == ' '))
		i++;
	while (str[i] == '-' || str[i] == '+')
		sign = str[i++] == '-' ? sign *= -1 : sign;
	start = i;
	while (get_index(base, str[i]) >= 0)
	{
		i++;
	}
	res = ft_convert_base(str, base, start, i);
	return (res * sign);
}
