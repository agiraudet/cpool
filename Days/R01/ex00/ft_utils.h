/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 07:19:58 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/25 09:22:59 by mbenabbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

void	ft_putint(int i);
void	ft_putchar(char c);
void	ft_print_map(int **map, int size, int *solved);
int		**ft_create_map(int size);
void	ft_init_map(int **map, int size);

#endif
