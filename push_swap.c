/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:09:53 by alistair          #+#    #+#             */
/*   Updated: 2022/02/20 06:41:26 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	return_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

static void	delete_list(t_list *head_ref)
{
	if (head_ref == NULL)
		return ;
	delete_list(head_ref -> next);
	free(head_ref);
}

void	solve_upper(t_list **stack_a, t_list **stack_b)
{
	t_state	*state;

	state = malloc(sizeof(t_state));
	while ((max_run(stack_a, state) < ft_lstsize(*stack_a)) \
		|| ft_lstsize(*stack_b))
	{
		if (ft_lstsize(*stack_b) && push_to_a(stack_a, stack_b, state))
			continue ;
		if ((ft_lstsize(*stack_a) == max_run(stack_a, state) \
			&& ft_lstsize(*stack_b)) || state->run_start == 0)
			reverse_rotate_a(stack_a, 0);
		else if (state->run_end < state->len)
		{
			if (state->run_end > (ft_lstsize(*stack_a) - state->run_start))
				reverse_rotate_a(stack_a, 0);
			else
				rotate_a(stack_a, 0);
		}
		else if (ft_lstsize(*stack_a) > 2)
			push_to_b(stack_a, stack_b, state);
	}
	end_correction(stack_a, stack_b, state);
	free(state);
}

void	solve_lower(t_list **stack_a, t_list **stack_b)
{
	int		len;
	t_state	*state;

	state = malloc(sizeof(t_state));
	max_run(stack_a, state);
	len = ft_lstsize(*stack_a);
	if (state->len == len && get_lowest(*stack_a) == get_nth_idx(*stack_a, 0))
		return ;
	else if (len == 2 && get_nth_idx(*stack_a, 0) > get_nth_idx(*stack_a, 1))
		swap_a(stack_a, 0);
	else if (len == 3)
		sort_three(*stack_a);
	else if (len == 4)
		sort_four(*stack_a, *stack_b);
	else if (len == 5)
		sort_five(*stack_a, *stack_b);
	free(state);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc <= 1)
		return (0);
	stack_a = list_builder(argc, argv);
	if (!stack_a)
		return (return_error());
	stack_b = malloc(sizeof(t_list));
	indexer(*stack_a);
	if (ft_lstsize(*stack_a) < 6)
		solve_lower(stack_a, stack_b);
	else
		solve_upper(stack_a, stack_b);
	// printf("----------\"solved\":---------\n");
	// print_ll(*stack_a, *stack_b);
	delete_list(*stack_a);
	delete_list(*stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}

// t_list	*print_gne(t_list *node, int *holder)
// {
// 	t_list	*empty;

// 	empty = malloc(sizeof(t_list));
// 	empty->index = 0;
// 	empty->next = NULL;
// 	if (node == NULL)
// 	{
// 		*holder = 0;
// 		return (empty);
// 	}
// 	else
// 		*holder = node->index;
// 	free(empty);
// 	return (node);
// }

// void	print_ll(t_list *head_a, t_list *head_b)
// {
// 	t_list	*new_node_a;
// 	t_list	*new_node_b;
// 	int		a_holder;
// 	int		b_holder;

// 	new_node_a = head_a;
// 	new_node_b = head_b;
// 	a_holder = 0;
// 	b_holder = 0;
// 	while (new_node_a != NULL || new_node_b != NULL)
// 	{
// 		new_node_a = print_gne(new_node_a, &a_holder);
// 		new_node_b = print_gne(new_node_b, &b_holder);
// 		printf("| %i \t\t %i |\n", a_holder, b_holder);
// 		new_node_a = new_node_a->next;
// 		new_node_b = new_node_b->next;
// 	}
// }