/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:46:37 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/18 08:32:15 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_same(char *str, char *to_find, int i)
{
	int ii;
	int same;

	ii = 0;
	same = 1;
	while (to_find[ii])
	{
		if (to_find[ii] != str[i + ii])
		{
			same = 0;
			break ;
		}
		ii++;
	}
	return (same);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			if (ft_same(str, to_find, i))
				return (str + i);
		}
		i++;
	}
	return (0);
}
