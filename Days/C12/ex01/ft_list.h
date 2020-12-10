/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:31:25 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/27 16:52:32 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
# define FT_LIST_H

typedef struct 	s_list
{
	struct	s_list *next;
	void	*data;
} 				t_list;

t_list	*ft_create_elem(void *data);

#endif
