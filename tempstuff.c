/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tempstuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:11:23 by alkane            #+#    #+#             */
/*   Updated: 2022/02/19 19:44:46 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	find_lowest(int temp, t_state *state)
{
	state->move_thresh = temp;
	state->val_holder
	// return (state->move_thresh);
}

void	find_lowest_move(int i, t_list **stack_a, t_list **stack_b, t_state *state)
{
	int	unshared;
	int	forward;
	int	reverse;
	int	lowest_val;

	lowest_val = -1;
	state->val_holder = get_nth_idx(*stack_a, i);
	unshared = min(i, ft_lstsize(*stack_a) - i) + \
		min(find_bin(state->val_holder, stack_b), ft_lstsize(*stack_b) - \
		find_bin(state->val_holder, stack_b));
	forward = find_forward_shared(i, find_bin(state->val_holder, stack_b));
	reverse = find_reverse_shared(ft_lstsize(*stack_a) - i, \
		ft_lstsize(*stack_b) - find_bin(state->val_holder, stack_b));
	if (!(i >= state->run_start && i <= state->run_end))
	{
		if (unshared <= min(forward, reverse) && unshared < state->move_thresh)
			find_lowest(unshared, state);
		else if (forward < reverse && forward < state->move_thresh)
			find_lowest(forward, state);
		else if (reverse < state->move_thresh)
			find_lowest(reverse, state);
	}
	// return (lowest_val);
}

