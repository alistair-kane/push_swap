/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:46:47 by alkane            #+#    #+#             */
/*   Updated: 2022/01/20 20:42:36 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*temp;
	t_list	*current;

	current = *lst;
	while (current && del)
	{	
		temp = current -> next;
		del(current->content);
		free(current);
		current = temp;
	}
	*lst = NULL;
}
