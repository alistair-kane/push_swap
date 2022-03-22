/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:42:14 by alkane            #+#    #+#             */
/*   Updated: 2022/03/22 22:33:24 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*list;

	list = ft_calloc(1, sizeof(t_list));
	if (!list)	
		return (0);
	list -> content = content;
	list -> next = NULL;
	return (list);
}
