/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:09:19 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/18 15:18:06 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int dstlen;

	dstlen = ft_strlen(dest);
	i = 0;
	if (dstlen < size)
	{
		while (src[i] && (i + dstlen + 1) < size)
		{
			dest[dstlen + i] = src[i];
			i++;
		}
	}
	if (size > 0 && dstlen <= size)
		dest[i + dstlen] = '\0';
	if (dstlen < size)
		return (dstlen + ft_strlen(src));
	else
		return (size + ft_strlen(src));
}
