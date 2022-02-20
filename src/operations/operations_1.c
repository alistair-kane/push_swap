/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:03:38 by alistair          #+#    #+#             */
/*   Updated: 2022/02/20 21:57:56 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap_a(t_list **head_a, int supress)
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
		if (!supress)
			write(1, "sa\n", 3);
	}
}

void	swap_b(t_list **head_b, int supress)
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
		if (!supress)
			write(1, "sb\n", 3);
	}
}

void	double_swap(t_list **head_a, t_list **head_b, int supress)
{
	swap_a(head_a, 1);
	swap_b(head_b, 1);
	if (!supress)
		write(1, "ss\n", 3);
}

void	push_a(t_list **head_a, t_list **head_b, int supress)
{
	t_list	*new_node;

	if (*head_b == NULL)
		return ;
	new_node = *head_b;
	*head_b = (*head_b)->next;
	new_node->next = *head_a;
	*head_a = new_node;
	if (!supress)
		write(1, "pa\n", 3);
}

void	push_b(t_list **head_a, t_list **head_b, int supress)
{
	t_list	*new_node;

	if (*head_a == NULL)
		return ;
	new_node = *head_a;
	*head_a = (*head_a)->next;
	new_node->next = *head_b;
	*head_b = new_node;
	if (!supress)
		write(1, "pb\n", 3);
}
