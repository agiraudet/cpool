/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:36:42 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/28 08:56:25 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <libstd.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	if(!(elem = (elem *)malloc(sizeof(t_list))))
		return (0);
	elem->data = data;
	elem->next = 0;
}
