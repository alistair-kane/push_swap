/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:49:34 by alkane            #+#    #+#             */
/*   Updated: 2022/03/22 00:55:15 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate_a(t_list **head_a, int supress)
{
	t_list	*last;
	t_list	*second;

	if (!*head_a || !(*head_a)->next)
		return ;
	last = *head_a;
	second = (*head_a)->next;
	while (last->next != NULL)
		last = last->next;
	(*head_a)->next = NULL;
	last->next = *head_a;
	*head_a = second;
	if (!supress)
		write(1, "ra\n", 3);
}

void	rotate_b(t_list **head_b, int supress)
{
	t_list	*last;
	t_list	*second;

	if (!*head_b || !(*head_b)->next)
		return ;
	last = *head_b;
	second = (*head_b)->next;
	while (last->next != NULL)
		last = last->next;
	(*head_b)->next = NULL;
	last->next = *head_b;
	*head_b = second;
	if (!supress)
		write(1, "rb\n", 3);
}

void	double_rotate(t_list **head_a, t_list **head_b, int supress)
{
	rotate_a(head_a, 1);
	rotate_b(head_b, 1);
	if (!supress)
		write(1, "rr\n", 3);
}
