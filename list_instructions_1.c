/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:03:38 by alistair          #+#    #+#             */
/*   Updated: 2022/02/05 15:14:29 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap the first 2 elements at the top of stack a. Do nothing if there
// is only one or no elements
void	swap_a(t_list **head_a, int double_flag)
{
	t_list	*temp;
	int		val_holder;
	int		indx_holder;

	temp = *head_a;
	if (temp != NULL && temp->next != NULL)
	{
		val_holder = temp->content;
		indx_holder = temp->index;
		temp->content = temp->next->content;
		temp->index = temp->next->index;
		temp->next->content = val_holder;
		temp->next->index = indx_holder;
		if (!double_flag)
			write(1, "sa\n", 3);
	}
}

void	swap_b(t_list **head_b, int double_flag)
{
	t_list	*temp;
	int		val_holder;
	int		indx_holder;

	temp = *head_b;
	if (temp != NULL && temp->next != NULL)
	{
		val_holder = temp->content;
		indx_holder = temp->index;
		temp->content = temp->next->content;
		temp->index = temp->next->index;
		temp->next->content = val_holder;
		temp->next->index = indx_holder;
		if (!double_flag)
			write(1, "sb\n", 3);
	}
}

void	double_swap(t_list **head_a, t_list **head_b)
{
	swap_a(head_a, 1);
	swap_b(head_b, 1);
	write(1, "ss\n", 3);
}

void	push_a(t_list **head_a, t_list **head_b)
{
	t_list	*new_node;

	if (*head_b == NULL)
		return ;
	new_node = *head_b;
	*head_b = (*head_b)->next;
	new_node->next = *head_a;
	*head_a = new_node;
	write(1, "pa\n", 3);
}

void	push_b(t_list **head_a, t_list **head_b)
{
	t_list	*new_node;

	if (*head_a == NULL)
		return ;
	new_node = *head_a;
	*head_a = (*head_a)->next;
	new_node->next = *head_b;
	*head_b = new_node;
	write(1, "pb\n", 3);
}
