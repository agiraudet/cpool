/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seek.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:01:11 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/28 08:49:23 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_print.c"

# define BUF_SIZE 4096

int		ft_mesure_file(char *path)
{
	int size;
	int fd;
	int rd;
	char buf[BUF_SIZE];

	size = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((rd = read(fd, buf, BUF_SIZE)))
		size += rd;
	if (close(fd) == -1)
		return (-1);
	return (size);
}

int		ft_file_allowed(char *path)
{
	int fd;

	fd = open(path, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (0);
	if (close(fd) == -1)
		return (-1);
	return (1);
}

int		ft_mini_atoi(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		res = (str[i++] - '0') + res * 10;
	}
	return (res);
}

int		main(int argc, char **argv)
{
	int offset;

	if (argc < 2)
		ft_print_err_msg(argv[0], argv[1], "illegal offset -- ");
	offset = ft_mini_atoi(argv[1]);
	if (offset < 0)
		ft_print_err_msg(argv[0], argv[1], "illegal offset -- ");
}
