/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:25:39 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/25 10:48:56 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# define SIZE 4

typedef struct			s_rules
{
	int size;
	int *colup;
	int *coldown;
	int *rowleft;
	int *rowright;
}						t_rules;

typedef	struct			s_point
{
	int x;
	int y;
}						t_point;

#endif
