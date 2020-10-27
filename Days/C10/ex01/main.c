/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 11:00:35 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/26 17:47:21 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stream.h"
#include <string.h>
#include <errno.h>

void	ft_print_error(char *agv0, char *agvi)
{
	ft_putstr_fd(2, agv0);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, agvi);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, strerror(errno));
	ft_putstr_fd(2, "\n");
}

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		ft_read_stdin();
	if (argc >= 2)
		while (i < argc)
		{
			if (argv[i][0] == '-' && !argv[i][1])
				ft_read_stdin();
			else if (!ft_file_allowed(argv[i]))
				ft_print_error(argv[0], argv[i]);
			else
				ft_read_file(argv[i]);
			i++;
		}
	return (0);
}		
