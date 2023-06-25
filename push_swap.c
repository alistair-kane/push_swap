/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:09:53 by alistair          #+#    #+#             */
/*   Updated: 2023/06/25 18:39:53 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	return_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

void	solve_upper(int *stack_a, int *stack_b, t_state *state)
{
	while ((max_run(stack_a, state) < lstsize(stack_a)) \
		|| lstsize(stack_b))
	{
		if (lstsize(stack_b) && push_to_a(stack_a, stack_b, state))
			continue ;
		if ((lstsize(stack_a) == max_run(stack_a, state) \
			&& lstsize(stack_b)) || state->run_start == 0)
			reverse_rotate_a(stack_a, 0);
		else if (state->run_end < state->len)
		{
			if (state->run_end > (lstsize(stack_a) - state->run_start))
				reverse_rotate_a(stack_a, 0);
			else
				rotate_a(stack_a, 0);
		}
		else if (lstsize(stack_a) > 2)
		{
			if (stack_a[0] - stack_a[2] == -1)
				swap_a(stack_a, 0);
			else
				push_to_b(stack_a, stack_b, state);
		}
	}
	end_correction(stack_a, state);
}

void	solve_lower(int *stack_a, int *stack_b, t_state *state)
{
	int len;

	len = lstsize(stack_a);
	printf("solve lower len:[%d]\n", len);
	// len = state->array_a_len;
	max_run(stack_a, state);
	if (state->len == len && stack_a[0] == 0)
		return ;
	else if (len == 2 && stack_a[0] > stack_a[1])
		swap_a(stack_a, 0);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 4)
		sort_four(stack_a, stack_b);
	else if (len == 5)
		sort_five(stack_a, stack_b);
}

void fill_arrays(int *stack_a, int *stack_b)
{
	int	i;

	i = 0;
	while (i < MAX_ARR_SIZE)
	{
		stack_a[i] = -1;
		stack_b[i] = -1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	stack_a[MAX_ARR_SIZE];
	int	stack_b[MAX_ARR_SIZE];
	t_state	*state;
	int size = argc - 1;
	if (argc <= 1)
		return (0);
		
	fill_arrays(stack_a, stack_b);
	if(list_builder(stack_a, argc, argv))
		return (return_error());
	// if (!stack_a)
	// printf("here?\n");
	// stack_b = ft_calloc(size, sizeof(int));
	indexer(stack_a);

	state = malloc(sizeof(t_state));
	// state->array_a_len = size;
	if (size < 6)
		solve_lower(stack_a, stack_b, state);
	else
		solve_upper(stack_a, stack_b, state);
	// delete_list(stack_a);
	// delete_list(stack_b);
	free(state);
	// free(stack_a);
	// free(stack_b);
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