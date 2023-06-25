/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 05:41:02 by alistair          #+#    #+#             */
/*   Updated: 2023/06/23 21:38:21 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	lstsize(int *stack)
{
	int size;

	// printf("lstsize called\n");
	size = 0;

	while (stack[size] != -1)
	{
		// printf("va	lue in lstsize: %d\n", stack[size]);
		size++;
	}
	return size;
	// while (stack[size] && stack[size] != -1)
	// {
	// 	// printf("value in lstsize: %d\n", stack[size]);
	// 	size++;
	// }
	// return(size);
}

static void	set_state(t_state *state)
{
	state->move_thresh = 1000;
	state->lowest_val = -1;
}

void	push_to_b(int *stack_a, int *stack_b, t_state *state)
{
	int	i;
	int	limit;
	int	unshared;

	i = -1;
	limit = lstsize(stack_a);
	if (state->run_end < state->run_start)
	{
		i = state->run_end - 1;
		limit = state->run_start;
	}
	set_state(state);
	while (++i < limit)
	{
		state->val_holder = stack_a[i];
		unshared = min(i, lstsize(stack_a) - i) \
			+ min(find_bin(state->val_holder, stack_b), lstsize(stack_b) \
			- find_bin(state->val_holder, stack_b));
		// if i is not after the run start and i is not below the run end
		if (!(i >= state->run_start && i <= state->run_end))
			find_lowest(unshared, \
				forward_shared(i, find_bin(state->val_holder, stack_b)), \
				reverse_shared(lstsize(stack_a) - i, \
				lstsize(stack_b) - find_bin(state->val_holder, stack_b)), \
				state);
	}
	move_lowest(state->lowest_val, stack_a, stack_b);
}

int	push_to_a(int *stack_a, int *stack_b, t_state *state)
{
	insert_pos(stack_b[0], stack_a, state);
	if (state->a_moves == 0)
		return (push_a(stack_a, stack_b, 0));
	return (0);
}

void	end_correction(int *stack_a, t_state *state)
{
	max_run(stack_a, state);
	insert_pos(-1, stack_a, state);
	while (stack_a[0] != 0)
	{
		if ((lstsize(stack_a) - state->a_moves) > state->a_moves)
			rotate_a(stack_a, 0);
		else
			reverse_rotate_a(stack_a, 0);
	}
}
