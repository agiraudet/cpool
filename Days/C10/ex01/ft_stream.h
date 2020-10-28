/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 11:01:47 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/28 08:13:45 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STREAM_H
# define FT_STREAM_H

void	ft_putstr_fd(int fd, char *str);
int		ft_read_file(char *path);
int		ft_read_stdin();
int		ft_file_allowed(char *path);

#endif
