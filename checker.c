/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:46:12 by alistair          #+#    #+#             */
/*   Updated: 2022/02/20 08:06:13 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

void	delete_list(t_list *head_ref)
{
	if (head_ref == NULL)
		return ;
	delete_list(head_ref -> next);
	free(head_ref);
}

int	apply_instructions(char *command, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp("pb\n", command, 3))
		push_b(stack_a, stack_b, 1);
	else if (!ft_strncmp("pa\n", command, 3))
		push_a(stack_a, stack_b, 1);
	else if (!ft_strncmp("sa\n", command, 3))
		swap_a(stack_a, 1);
	else if (!ft_strncmp("sb\n", command, 3))
		swap_b(stack_b, 1);
	else if (!ft_strncmp("ss\n", command, 3))
		double_swap(stack_a, stack_b, 1);
	else if (!ft_strncmp("ra\n", command, 3))
		rotate_a(stack_a, 1);
	else if (!ft_strncmp("rb\n", command, 3))
		rotate_b(stack_a, 1);
	else if (!ft_strncmp("rr\n", command, 3))
		double_rotate(stack_a, stack_b, 1);
	else if (!ft_strncmp("rra\n", command, 4))
		reverse_rotate_a(stack_a, 1);
	else if (!ft_strncmp("rrb\n", command, 4))
		reverse_rotate_b(stack_b, 1);
	else if (!ft_strncmp("rrr\n", command, 4))
		double_reverse_rotate(stack_a, stack_b, 1);
	else
		return (-1);
	return (0);
}

void	check_result(t_list **stack_a, t_list **stack_b)
{
	t_state	*state;
	int		len;

	state = malloc(sizeof(t_state));
	max_run(stack_a, state);
	len = ft_lstsize(*stack_a);
	if (state->len == len && get_lowest(*stack_a) == get_nth_idx(*stack_a, 0)
		&& !ft_lstsize(*stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(state);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*instruction;

	if (argc <= 1)
		return (0);
	stack_a = list_builder(argc, argv);
	if (!stack_a)
		return (return_error());
	stack_b = malloc(sizeof(t_list));
	indexer(*stack_a);
	while (1)
	{
		instruction = get_next_line(0);
		if (instruction == NULL)
			break ;
		if (apply_instructions(instruction, stack_a, stack_b))
			return (return_error());
	}
	check_result(stack_a, stack_b);
	delete_list(*stack_a);
	delete_list(*stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}

// src/operations/operations_1.c src/operations/operations_2.c 
// src/operations/operations_3.c src/indexer.c src/utils/utils_1.c
// src/utils/utils_2.c src/lower_sort.c src/init.c checker.c 
// libft/libft.a -o checker