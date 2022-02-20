/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 05:41:02 by alistair          #+#    #+#             */
/*   Updated: 2022/02/20 07:45:10 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	set_state(t_state *state)
{
	state->move_thresh = 1000;
	state->lowest_val = -1;
}

void	push_to_b(t_list **stack_a, t_list **stack_b, t_state *state)
{
	int	i;
	int	limit;
	int	unshared;

	i = -1;
	limit = ft_lstsize(*stack_a);
	if (state->run_end < state->run_start)
	{
		i = state->run_end - 1;
		limit = state->run_start;
	}
	set_state(state);
	while (++i < limit)
	{
		state->val_holder = get_nth_idx(*stack_a, i);
		unshared = min(i, ft_lstsize(*stack_a) - i) \
			+ min(find_bin(state->val_holder, stack_b), ft_lstsize(*stack_b) \
			- find_bin(state->val_holder, stack_b));
		if (!(i >= state->run_start && i <= state->run_end))
			find_lowest(unshared, \
				forward_shared(i, find_bin(state->val_holder, stack_b)), \
				reverse_shared(ft_lstsize(*stack_a) - i, ft_lstsize(*stack_b) \
				- find_bin(state->val_holder, stack_b)), state);
	}
	move_lowest(state->lowest_val, stack_a, stack_b);
}

int	push_to_a(t_list **stack_a, t_list **stack_b, t_state *state)
{
	int	lowest_val;
	int	val;
	int	unshared;
	int	i;

	i = 0;
	lowest_val = -1;
	while (get_nth_idx(*stack_b, i) != -1)
	{
		val = get_nth_idx(*stack_b, i);
		insert_pos(val, stack_a, stack_b, state);
		unshared = min(state->a_moves, ft_lstsize(*stack_a) - state->a_moves) \
			+ min(state->b_moves, ft_lstsize(*stack_b) - state->b_moves);
		if (unshared < 1 || forward_shared(state->a_moves, state->b_moves) < 1 \
			|| reverse_shared(ft_lstsize(*stack_a) - state->a_moves, \
			ft_lstsize(*stack_b) - state->b_moves) < 1)
			lowest_val = val;
		i++;
	}
	if (lowest_val != -1)
	{
		push_a(stack_a, stack_b, 0);
		return (1);
	}
	return (0);
}

void	end_correction(t_list **stack_a, t_list **stack_b, t_state *state)
{
	insert_pos(-1, stack_a, stack_b, state);
	while (get_nth_idx(*stack_a, 0) != 0)
	{
		if ((ft_lstsize(*stack_a) - state->a_moves) > state->a_moves)
			rotate_a(stack_a, 0);
		else
			reverse_rotate_a(stack_a, 0);
	}
}
