/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:48:33 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/28 08:41:06 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

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

int		ft_file_allowed(char *path)
{
	int fd;

	fd = open(path, O_RDONLY | O_DIRECTORY);
	if (fd != -1)
	{
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

int		main(int argc, char **argv)
{
	if (argc > 2)
		ft_putstr_fd(2, "Too many arguments.\n");
	else if (argc < 2)
		ft_putstr_fd(2, "File name missing.\n");
	else if (!ft_file_allowed(argv[1]))
		ft_putstr_fd(2, "Cannot read file.\n");
	else
		ft_read_file(argv[1]);
	return (0);
}
