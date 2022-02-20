/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 05:33:48 by alistair          #+#    #+#             */
/*   Updated: 2022/02/20 06:40:00 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	reset_temp(int temp_len, int i, t_state *state)
{
	if (state->len < temp_len)
	{
		state->len = temp_len;
		state->run_start = i - (state->len - 1);
		state->run_end = i;
	}
	temp_len = 1;
	return (temp_len);
}

static void	count_consec(t_list **head, t_state *state, int len)
{
	int	i;
	int	j;
	int	k;
	int	temp_len;

	i = -1;
	j = 0;
	k = 1;
	temp_len = 1;
	state->len = 1;
	while (++i < (len * 2))
	{
		if (get_nth_idx(*head, j++) < get_nth_idx(*head, k++))
			temp_len++;
		else
			temp_len = reset_temp(temp_len, i, state);
		if (k == len)
			k = 0;
		if (j == len)
			j = 0;
	}
}

int	max_run(t_list **head, t_state *state)
{
	int	len;

	len = ft_lstsize(*head);
	count_consec(head, state, len);
	if (state->run_end >= len)
		state->run_end = state->run_end - len;
	if (state->run_start >= len)
		state->run_start = state->run_start - len;
	return (state->len);
}

static int	slot_in_run(int val, t_list **stack_a, t_state *state)
{
	int	fits;
	int	i;

	fits = 0;
	i = state->run_start;
	while (fits != 2)
	{
		fits = 0;
		if (val > get_nth_idx(*stack_a, i))
			fits++;
		if (i == ft_lstsize(*stack_a))
			i = -1;
		if (val < get_nth_idx(*stack_a, i + 1))
			fits++;
		i++;
	}
	return (i);
}

void	insert_pos(int val, t_list **stack_a, t_list **stack_b, t_state *state)
{
	int	moves;
	int	i;

	max_run(stack_a, state);
	if (val < get_nth_idx(*stack_a, state->run_start))
		moves = state->run_start;
	else if (val > get_nth_idx(*stack_a, state->run_end))
		moves = state->run_end;
	else
		moves = slot_in_run(val, stack_a, state);
	state->a_moves = moves;
	i = 0;
	while (get_nth_idx(*stack_b, i) != val)
		i++;
	state->b_moves = i;
}
