/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 07:17:33 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/25 07:51:34 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

int		ft_is_num(char c);
int		ft_small_atoi(char *str, int start, int end);
int		*ft_parse_arg(char *str, int set_pos, int set_size);
t_rules	ft_set_rules(char *str);

#endif
