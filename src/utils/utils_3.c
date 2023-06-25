/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 05:37:44 by alistair          #+#    #+#             */
/*   Updated: 2023/06/23 15:29:28 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// returns the __position__ of the highest value in the stack 
int	max_idx(int len, int *head)
{
	int	i;
	int	max_val;
	int	max_idx;

	i = 0;
	max_val = 0;
	while (i < len)
	{
		if (head[i] > max_val)
		{
			max_val = head[i];
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}

int	find_bin(int val, int *stack_b)
{
	int	len;
	int	i;
	int	j;

	len = lstsize(stack_b);
	if (len == 0 || len == 1)
		return (0);
	i = max_idx(len, stack_b);
	j = 0;
	while (j < len)
	{
		// if the value we are testing is larger than the current value this is the index
		// to be selected
		if (val > stack_b[i])
			return (i);
		j++;
		i++;
		if (i == len)
			i = 0;
	}
	return (max_idx(len, stack_b));
}

// aligns the two stacks in the lowest moves possible 
void	move_lowest(int lowest, int *stack_a, int *stack_b)
{
	int	a_rotate;
	int	a_reverse;
	int	b_rotate;
	int	b_reverse;
	int	unshared;

	a_rotate = 0;
	while (lowest != stack_a[a_rotate])
		a_rotate++;
	b_rotate = find_bin(lowest, stack_b);
	a_reverse = lstsize(stack_a) - a_rotate;
	b_reverse = lstsize(stack_b) - b_rotate;
	unshared = min(a_rotate, a_reverse) + min(b_rotate, b_reverse);

	if (unshared < forward_shared(a_rotate, b_rotate) && unshared < reverse_shared(a_reverse, b_reverse))
	{
		a_moves(a_rotate, a_reverse, stack_a);
		b_moves(b_rotate, b_reverse, stack_b);
		push_b(stack_a, stack_b, 0);
	}
	else if (forward_shared(a_rotate, b_rotate) < reverse_shared(a_reverse, b_reverse))
		fwd_rotates(a_rotate, b_rotate, stack_a, stack_b);
	else
		rev_rotates(a_reverse, b_reverse, stack_a, stack_b);
}

void	find_lowest(int unshared, int forward, int reverse, t_state *state)
{
	if (unshared <= min(forward, reverse) && unshared < state->move_thresh)
	{
		state->move_thresh = unshared;
		state->lowest_val = state->val_holder;
	}
	else if (forward < reverse && forward < state->move_thresh)
	{
		state->move_thresh = forward;
		state->lowest_val = state->val_holder;
	}
	else if (reverse < state->move_thresh)
	{
		state->move_thresh = reverse;
		state->lowest_val = state->val_holder;
	}
}
