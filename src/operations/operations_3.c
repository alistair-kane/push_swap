/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:49:34 by alkane            #+#    #+#             */
/*   Updated: 2022/02/20 07:07:23 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reverse_rotate_a(t_list **head_a, int supress)
{
	t_list	*second_last;
	t_list	*last;

	if (!*head_a || !(*head_a)->next)
		return ;
	second_last = NULL;
	last = *head_a;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *head_a;
	*head_a = last;
	if (!supress)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **head_b, int supress)
{
	t_list	*second_last;
	t_list	*last;

	if (!*head_b || !(*head_b)->next)
		return ;
	second_last = NULL;
	last = *head_b;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *head_b;
	*head_b = last;
	if (!supress)
		write(1, "rrb\n", 4);
}

void	double_reverse_rotate(t_list **head_a, t_list **head_b, int supress)
{
	reverse_rotate_a(head_a, 1);
	reverse_rotate_b(head_b, 1);
	if (!supress)
		write(1, "rrr\n", 4);
}
