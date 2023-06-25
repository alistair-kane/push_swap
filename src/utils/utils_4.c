/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 05:39:15 by alistair          #+#    #+#             */
/*   Updated: 2023/06/23 15:06:35 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	a_moves(int a_rotate, int a_reverse, int *stack_a)
{
	if (a_reverse < a_rotate)
	{	
		while (a_reverse--)
			reverse_rotate_a(stack_a, 0);
	}
	else
	{
		while (a_rotate--)
			rotate_a(stack_a, 0);
	}
}

void	b_moves(int b_rotate, int b_reverse, int *stack_b)
{
	if (b_reverse < b_rotate)
	{	
		while (b_reverse--)
			reverse_rotate_b(stack_b, 0);
	}
	else
	{
		while (b_rotate--)
			rotate_b(stack_b, 0);
	}
}

void	fwd_rotates(int a, int b, int *stack_a, int *stack_b)
{
	while (a && b)
	{
		a--;
		b--;
		double_rotate(stack_a, stack_b, 0);
	}
	while (a--)
		rotate_a(stack_a, 0);
	while (b--)
		rotate_b(stack_b, 0);
	push_b(stack_a, stack_b, 0);
}

void	rev_rotates(int a, int b, int *stack_a, int *stack_b)
{
	while (a && b)
	{
		a--;
		b--;
		double_reverse_rotate(stack_a, stack_b, 0);
	}
	while (a--)
		reverse_rotate_a(stack_a, 0);
	while (b--)
		reverse_rotate_b(stack_b, 0);
	push_b(stack_a, stack_b, 0);
}
