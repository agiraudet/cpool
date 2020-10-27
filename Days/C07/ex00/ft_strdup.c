/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:27:43 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/22 10:12:28 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, char *src)
{
	int size;
	int i;

	size = ft_strlen(src);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		size;

	copy = 0;
	size = ft_strlen(src) + 1;
	if (!(copy = malloc(size * sizeof(char))))
		return (0);
	ft_strcpy(copy, src);
	return (copy);
}
