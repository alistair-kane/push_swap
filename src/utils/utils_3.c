/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 05:37:44 by alistair          #+#    #+#             */
/*   Updated: 2022/02/20 07:44:14 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	max_idx(int len, t_list **head)
{
	int	i;
	int	max_val;
	int	max_idx;

	i = 0;
	max_val = 0;
	while (i < len)
	{
		if (get_nth_idx(*head, i) > max_val)
		{
			max_val = get_nth_idx(*head, i);
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}

int	find_bin(int val, t_list **stack_b)
{
	int	len;
	int	i;
	int	j;

	len = ft_lstsize(*stack_b);
	if (len == 0 || len == 1)
		return (0);
	i = max_idx(len, stack_b);
	j = 0;
	while (j < len)
	{
		if (val > get_nth_idx(*stack_b, i))
			return (i);
		j++;
		i++;
		if (i == len)
			i = 0;
	}
	return (max_idx(len, stack_b));
}

void	move_lowest(int lowest, t_list **stack_a, t_list **stack_b)
{
	int	a_rotate;
	int	a_reverse;
	int	b_rotate;
	int	b_reverse;
	int	unshared;

	a_rotate = 0;
	while (lowest != get_nth_idx(*stack_a, a_rotate))
		a_rotate++;
	b_rotate = find_bin(lowest, stack_b);
	a_reverse = ft_lstsize(*stack_a) - a_rotate;
	b_reverse = ft_lstsize(*stack_b) - b_rotate;
	unshared = min(a_rotate, a_reverse) + min(b_rotate, b_reverse);
	if (unshared < forward_shared(a_rotate, b_rotate) && unshared
		< reverse_shared(a_reverse, b_reverse))
	{
		a_moves(a_rotate, a_reverse, stack_a);
		b_moves(b_rotate, b_reverse, stack_b);
		push_b(stack_a, stack_b, 0);
	}
	else if (forward_shared(a_rotate, b_rotate)
		< reverse_shared(a_reverse, b_reverse))
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
