/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:49:34 by alkane            #+#    #+#             */
/*   Updated: 2022/02/13 20:51:44 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list **head_a, int double_flag)
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
	if (!double_flag)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **head_b, int double_flag)
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
	if (!double_flag)
		write(1, "rrb\n", 4);
}

void	double_reverse_rotate(t_list **head_a, t_list **head_b)
{
	reverse_rotate_a(head_a, 1);
	reverse_rotate_b(head_b, 1);
	write(1, "rrr\n", 4);
}



	// if ((min(b_rotate, b_reverse) + min(a_rotate, a_reverse)) < 15)
	// {
	// 	if (a_rotate < a_reverse && b_rotate < b_reverse)
	// 	{
	// 		while (a_rotate && b_rotate)
	// 		{
	// 			a_rotate--;
	// 			b_rotate--;
	// 			double_rotate(stack_a, stack_b);
	// 		}
	// 		while (a_rotate--)
	// 			rotate_a(stack_a, 0);
	// 		while (b_rotate--)
	// 			rotate_b(stack_b, 0);
	// 	}
	// 	else if (a_reverse < a_rotate && b_reverse < b_rotate)
	// 	{
	// 		while (a_reverse && b_reverse)
	// 		{
	// 			a_reverse--;
	// 			b_reverse--;
	// 			double_reverse_rotate(stack_a, stack_b);
	// 		}
	// 		while (a_reverse--)
	// 			reverse_rotate_a(stack_a, 0);
	// 		while (b_reverse--)
	// 			reverse_rotate_b(stack_b, 0);
	// 	}
	// 	else
	// 	{
	// 		if (a_rotate < a_reverse)
	// 		{
	// 			while (a_rotate--)
	// 				rotate_a(stack_a, 0);
	// 		}
	// 		else
	// 		{
	// 			while (a_reverse--)
	// 				reverse_rotate_a(stack_a, 0);
	// 		}
	// 		if (b_rotate < b_reverse)
	// 		{
	// 			while (b_rotate--)
	// 				rotate_b(stack_b, 0);
	// 		}
	// 		else
	// 		{
	// 			while (b_reverse--)
	// 				reverse_rotate_b(stack_b, 0);
	// 		}
	// 	}
	// 	push_a(stack_a, stack_b);
	// }
	// lowest_moves = min(shared_forward, shared_reverse);
// 	else
// 	// do the work for reverse shared
// 	{
// 		while (a_reverse && b_reverse)
// 		{
// 			a_reverse--;
// 			b_reverse--;
// 			double_reverse_rotate(stack_a, stack_b);
// 		}
// 		while (a_reverse--)
// 			reverse_rotate_a(stack_a, 0);
// 		while (b_reverse--)
// 			reverse_rotate_b(stack_b, 0);
// 		push_a(stack_a, stack_b);
// 	}
// 	}

// 	while (a_rotate && b_rotate)
// 	{
// 		a_rotate--;
// 		b_rotate--;
// 		double_rotate(stack_a, stack_b);
// 	}
// 	while (a_rotate--)
// 		rotate_a(stack_a, 0);
// 	while (b_rotate--)
// 		rotate_b(stack_b, 0);
// 	push_a(stack_a, stack_b);
// }


// 	// lowest_moves = min(shared_forward, shared_reverse);
// 	else
// 	// do the work for reverse shared
// 	{
// 		while (a_reverse && b_reverse)
// 		{
// 			a_reverse--;
// 			b_reverse--;
// 			double_reverse_rotate(stack_a, stack_b);
// 		}
// 		while (a_reverse--)
// 			reverse_rotate_a(stack_a, 0);
// 		while (b_reverse--)
// 			reverse_rotate_b(stack_b, 0);
// 		push_a(stack_a, stack_b);
// 	}