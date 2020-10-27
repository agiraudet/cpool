/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 09:35:34 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/18 08:18:55 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	int				result;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	c1 = s1[i];
	c2 = s2[i];
	while (c1 == c2)
	{
		if (c1 == '\0')
			return (0);
		i++;
		c1 = s1[i];
		c2 = s2[i];
	}
	result = c1 > c2 ? 1 : -1;
	return (result);
}
