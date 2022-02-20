/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 05:25:45 by alistair          #+#    #+#             */
/*   Updated: 2022/02/20 20:46:04 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_list *a, t_list *b)
{
	int	temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

static void	bubble_sort(t_list *start)
{
	int		swapped;
	t_list	*ptr_1;
	t_list	*l_ptr;

	ptr_1 = NULL;
	l_ptr = NULL;
	if (start == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr_1 = start;
		while (ptr_1->next != l_ptr)
		{
			if (ptr_1->content > ptr_1->next->content)
			{
				swap(ptr_1, ptr_1->next);
				swapped = 1;
			}
			ptr_1 = ptr_1->next;
		}
		l_ptr = ptr_1;
	}
}

static	t_list	*copy(t_list *head)
{
	t_list	*current;
	t_list	*new_list;
	t_list	*tail;

	current = head;
	new_list = NULL;
	while (current != NULL)
	{
		if (new_list == NULL)
		{
			new_list = ft_lstnew(current->content);
			new_list->index = current->index;
			tail = new_list;
		}
		else
		{
			tail->next = (t_list *)malloc(sizeof(t_list));
			tail = tail->next;
			tail->index = current->index;
			tail->content = current->content;
			tail->next = NULL;
		}
		current = current->next;
	}
	return (new_list);
}

void	indexer(t_list *stack_a)
{
	t_list	*sorted;
	t_list	*next;
	int		i;

	sorted = copy(stack_a);
	bubble_sort(sorted);
	while (stack_a != NULL)
	{
		i = 1;
		while (i < ft_lstsize(sorted))
		{
			if (stack_a->content == get_nth(sorted, i))
				stack_a->index = i;
			i++;
		}
		stack_a = stack_a->next;
	}
	while (sorted)
	{
		next = sorted->next;
		free(sorted);
		sorted = next;
	}
}
