/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 05:22:39 by alistair          #+#    #+#             */
/*   Updated: 2022/02/20 07:05:55 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_lowest(t_list *stack_a)
{
	int	i;
	int	val;

	i = 1;
	val = get_nth_idx(stack_a, 0);
	while (i < ft_lstsize(stack_a))
	{
		if (get_nth_idx(stack_a, i) < val)
			val = get_nth_idx(stack_a, i);
		i++;
	}
	return (val);
}

static void	align_stack(int low, t_list **stack_a)
{
	int	i;

	i = 0;
	while (get_nth_idx(*stack_a, i) != low)
		i++;
	if (i > 2)
	{
		while (get_nth_idx(*stack_a, 0) != low)
			reverse_rotate_a(stack_a, 0);
	}
	else
	{
		while (get_nth_idx(*stack_a, 0) != low)
			rotate_a(stack_a, 0);
	}
}

void	sort_three(t_list *stack_a)
{
	if (!(get_nth_idx(stack_a, 0) < get_nth_idx(stack_a, 1) && \
		get_nth_idx(stack_a, 1) < get_nth_idx(stack_a, 2)))
	{
		if (get_nth_idx(stack_a, 0) > get_nth_idx(stack_a, 1) && \
			get_nth_idx(stack_a, 1) < get_nth_idx(stack_a, 2) && \
			get_nth_idx(stack_a, 2) < get_nth_idx(stack_a, 0))
			rotate_a(&stack_a, 0);
		else if (get_nth_idx(stack_a, 0) > get_nth_idx(stack_a, 1) && \
			get_nth_idx(stack_a, 1) > get_nth_idx(stack_a, 2))
		{
			rotate_a(&stack_a, 0);
			swap_a(&stack_a, 0);
		}
		else if (get_nth_idx(stack_a, 0) < get_nth_idx(stack_a, 1) && \
			get_nth_idx(stack_a, 0) > get_nth_idx(stack_a, 2))
			reverse_rotate_a(&stack_a, 0);
		else if (get_nth_idx(stack_a, 0) > get_nth_idx(stack_a, 1) && \
			get_nth_idx(stack_a, 2) > get_nth_idx(stack_a, 0))
			swap_a(&stack_a, 0);
		else
		{
			reverse_rotate_a(&stack_a, 0);
			swap_a(&stack_a, 0);
		}
	}
}

void	sort_four(t_list *stack_a, t_list *stack_b)
{
	int	low;

	low = get_lowest(stack_a);
	while (get_nth_idx(stack_a, 0) != low)
		rotate_a(&stack_a, 0);
	push_b(&stack_a, &stack_b, 0);
	sort_three(stack_a);
	push_a(&stack_a, &stack_b, 0);
}

void	sort_five(t_list *stack_a, t_list *stack_b)
{
	int	low;
	int	len;

	low = get_lowest(stack_a);
	len = ft_lstsize(stack_a);
	align_stack(low, &stack_a);
	push_b(&stack_a, &stack_b, 0);
	low = get_lowest(stack_a);
	if (low == get_nth_idx(stack_a, len - 1))
		reverse_rotate_a(&stack_a, 0);
	else
	{
		while (get_nth_idx(stack_a, 0) != low)
			rotate_a(&stack_a, 0);
	}
	push_b(&stack_a, &stack_b, 0);
	sort_three(stack_a);
	push_a(&stack_a, &stack_b, 0);
	push_a(&stack_a, &stack_b, 0);
}
