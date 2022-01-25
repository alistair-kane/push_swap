/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:49:34 by alkane            #+#    #+#             */
/*   Updated: 2022/01/23 22:18:37 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list **head_a, int double_flag)
{
	t_list	*second_last;
	t_list	*last;

	if (!*head_a)
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
	if (!double_flag)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **head_b, int double_flag)
{
	t_list	*second_last;
	t_list	*last;
	
	if (!*head_b)
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
	if (!double_flag)
		write(1, "rrb\n", 4);
}

void	double_reverse_rotate(t_list **head_a, t_list **head_b)
{
	reverse_rotate_a(head_a, 1);
	reverse_rotate_b(head_b, 1);
	write(1, "rrr\n", 4);
}
