/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 07:15:49 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/25 08:33:54 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKS_H
# define FT_CHECKS_H

void	ft_check_dir(int dir, int i, int *x, int *y);
int		ft_check_view(int **map, int dir, int start);
int		ft_check_col(int **map, t_rules rule);
int		ft_check_double(int **map, int value, t_point point);
int		ft_check_argv(char *arg);

#endif
