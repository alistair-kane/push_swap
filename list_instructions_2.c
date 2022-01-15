/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:49:34 by alkane            #+#    #+#             */
/*   Updated: 2022/01/15 18:38:48 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **head_a, int double_flag)
{
	t_list	*last;
	t_list	*second;

	last = *head_a;
	second = (*head_a)->next;
	while (last->next != NULL)
		last = last->next;
	(*head_a)->next = NULL;
	last->next = *head_a;
	*head_a = second;
	if (!double_flag)
		write(1, "ra\n", 3);
}

void	rotate_b(t_list **head_b, int double_flag)
{
	t_list	*last;
	t_list	*second;

	last = *head_b;
	second = (*head_b)->next;
	while (last->next != NULL)
		last = last->next;
	(*head_b)->next = NULL;
	last->next = *head_b;
	*head_b = second;
	if (!double_flag)
		write(1, "rb\n", 3);
}

void	double_rotate(t_list **head_a, t_list **head_b)
{
	rotate_a(head_a, 1);
	rotate_b(head_b, 1);
	write(1, "rr\n", 3);
}
