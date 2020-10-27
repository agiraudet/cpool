/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 21:07:37 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/26 19:15:04 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alphanum(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	make_low(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

char	make_upp(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
			str[i] = make_upp(str[i]);
		else if (is_alphanum(str[i - 1]))
			str[i] = make_low(str[i]);
		else
			str[i] = make_upp(str[i]);
		i++;
	}
	return (str);
}
