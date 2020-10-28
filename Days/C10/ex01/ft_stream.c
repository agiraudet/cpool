/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:59:40 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/28 08:40:41 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 4096

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

int		ft_read_file(char *path)
{
	char	buf[BUF_SIZE + 1];
	int		fd;
	int		rd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((rd = read(fd, buf, BUF_SIZE)))
	{
		buf[rd] = '\0';
		ft_putstr_fd(1, buf);
	}
	if (close(fd) == -1)
		return (0);
	return (1);
}

int		ft_read_stdin(void)
{
	char	buf[BUF_SIZE + 1];
	int		rd;

	while ((rd = read(0, buf, BUF_SIZE)))
	{
		buf[rd] = '\0';
		ft_putstr_fd(1, buf);
	}
	return (1);
}

int		ft_file_allowed(char *path)
{
	int fd;

	fd = open(path, O_RDONLY | O_DIRECTORY);
	if (fd != -1)
	{
		errno = 21;
		close(fd);
		return (0);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	if (close(fd) == -1)
		return (-1);
	return (1);
}
