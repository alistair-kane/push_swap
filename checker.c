/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:46:12 by alistair          #+#    #+#             */
/*   Updated: 2022/02/02 23:03:56 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_dup(t_list *head_ref)
{
	int		count;
	t_list	*ptr;

	count = 0;
	while (head_ref -> next != NULL)
	{
		ptr = head_ref -> next;
		while (ptr != NULL)
		{
			if (head_ref -> content == ptr -> content)
			{
				count++;
				break ;
			}
			ptr = ptr -> next;
		}
		head_ref = head_ref -> next;
	}
	return (count);
}

t_list	**list_builder(int argc, char **argv)
{
	t_list	**stack_a;
	int		i;
	long	val;

	stack_a = malloc(sizeof(t_list));
	i = 1;
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		if (val >= 2147483648 || val < -2147483648)
			return (NULL);
		else
		{
			if (i++ == 1)
				*stack_a = ft_lstnew(val);
			else
			{
				ft_lstadd_back(stack_a, ft_lstnew(val));
				if (count_dup(*stack_a))
					return (NULL);
			}
		}
	}
	return (stack_a);
}

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
		push_b(stack_a, stack_b);
	else if (!ft_strncmp("pa\n", command, 3))
		push_a(stack_a, stack_b);
	else if (!ft_strncmp("sa\n", command, 3))
		swap_a(stack_a, 0);
	else if (!ft_strncmp("sb\n", command, 3))
		swap_b(stack_b, 0);
	else if (!ft_strncmp("ss\n", command, 3))
		double_swap(stack_a, stack_b);
	else if (!ft_strncmp("ra\n", command, 3))
		rotate_a(stack_a, 0);
	else if (!ft_strncmp("rb\n", command, 3))
		rotate_b(stack_a, 0);
	else if (!ft_strncmp("rr\n", command, 3))
		double_rotate(stack_a, stack_b);
	else if (!ft_strncmp("rra\n", command, 4))
		reverse_rotate_a(stack_a, 0);
	else if (!ft_strncmp("rrb\n", command, 4))
		reverse_rotate_b(stack_b, 0);
	else if (!ft_strncmp("rrr\n", command, 4))
		double_reverse_rotate(stack_a, stack_b);
	else
		return (-1);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_list	**stack_a;
// 	t_list	**stack_b;

// 	if (argc <= 1)
// 		return (0);
// 	stack_a = list_builder(argc, argv);
// 	if (!stack_a)
// 		return (return_error());
// 	stack_b = malloc(sizeof(t_list));
// 	// printf("---------ENTRY STACK:-----------\n");
// 	// print_ll(*stack_a, *stack_b);
// 	indexer(stack_a);
// 	// char	*instruction;
// 	// while (1)
// 	// {

// 	// sortver(stack_a, stack_b);

// 	// instruction = get_next_line(0);
// 	// if (instruction == NULL)
// 	// 	break ;
// 	// if(apply_instructions(instruction, stack_a, stack_b))
// 	// 	return(return_error());
// 	// }
// 	printf("\n---------- done ----------\n");
// 	print_ll(*stack_a, *stack_b);

// 	delete_list(*stack_a);
// 	delete_list(*stack_b);
// 	free(stack_a);
// 	free(stack_b);
// 	return (0);
// }
