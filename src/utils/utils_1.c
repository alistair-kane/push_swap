/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 05:30:58 by alistair          #+#    #+#             */
/*   Updated: 2022/02/20 06:40:13 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_nth(t_list *head, int index)
{
	t_list	*current;
	int		count;

	current = head;
	count = 0;
	while (current != NULL)
	{
		if (count == index)
			return (current->content);
		count++;
		current = current->next;
	}
	return (-1);
}

int	get_nth_idx(t_list *head, int index)
{
	t_list	*current;
	int		count;

	current = head;
	count = 0;
	while (current != NULL)
	{
		if (count == index)
			return (current->index);
		count++;
		current = current->next;
	}
	return (-1);
}

int	forward_shared(int a_rotate, int b_rotate)
{
	int	i;

	i = 0;
	while (a_rotate && b_rotate)
	{
		a_rotate--;
		b_rotate--;
		i++;
	}
	if (a_rotate > 0)
	{
		while (a_rotate--)
			i++;
	}
	if (b_rotate > 0)
	{
		while (b_rotate--)
			i++;
	}
	return (i);
}

int	reverse_shared(int a_reverse, int b_reverse)
{
	int	i;

	i = 0;
	while (a_reverse && b_reverse)
	{
		a_reverse--;
		b_reverse--;
		i++;
	}
	if (a_reverse > 0)
	{
		while (a_reverse--)
			i++;
	}
	if (b_reverse > 0)
	{
		while (b_reverse--)
			i++;
	}
	return (i);
}

int	min(int x, int y)
{
	if (x > y)
		return (y);
	else
		return (x);
}
