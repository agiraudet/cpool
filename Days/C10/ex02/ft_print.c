/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:26:05 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/26 19:21:39 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

void	ft_print_err_msg(char *agv0, char *agvi, char *msg)
{
	ft_putstr_fd(2, agv0);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, msg);
	ft_putstr_fd(2, agvi);
	ft_putstr_fd(2, "\n");
}
