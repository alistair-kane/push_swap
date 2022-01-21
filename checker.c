/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:46:12 by alistair          #+#    #+#             */
/*   Updated: 2022/01/21 16:39:42 by alkane           ###   ########.fr       */
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

t_list	*print_gne(t_list *node, int *holder)
{
	t_list	*empty;

	empty = malloc(sizeof(t_list));
	empty->content = 0;
	empty->next = NULL;
	if (node == NULL)
	{
		*holder = 0;
		return (empty);
	}
	else
		*holder = node->content;
	return (node);
}

void	print_ll(t_list *head_a, t_list *head_b)
{
	t_list	*new_node_a;
	t_list	*new_node_b;
	int		a_holder;
	int		b_holder;

	new_node_a = head_a;
	new_node_b = head_b;
	a_holder = 0;
	b_holder = 0;
	while (new_node_a != NULL || new_node_b != NULL)
	{
		new_node_a = print_gne(new_node_a, &a_holder);
		new_node_b = print_gne(new_node_b, &b_holder);
		printf("| %i \t\t %i |\n", a_holder, b_holder);
		new_node_a = new_node_a->next;
		new_node_b = new_node_b->next;
	}
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
	static	int	counter = 0;
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
	printf("---------- %.2s ----------\n", command);
	printf("Counter: %d\n", counter++);
	print_ll(*stack_a, *stack_b);
	return (0);
}

int	max_val(t_list *head)
{
	int max = 0;
  
	while (head != NULL)
	{
		if (max < head->data)
			max = head->data;
		head = head->next;
	}
	return (max);
}

t_list	**solver(t_list **stack_a, t_list **stack_b)
{
	int	stack_len;
	int	max;
	
	stack_len = ft_lstsize(*stack_a);
	max = max_val(*stack_a);
	// stack_len = ft_lstsize(*stack_b);
	if ((ft_lstsize(*stack_b) <= (stack_len / 2)))
	{
		if (((*stack_a)->content) <= (stack_len / 2))
		{
			push_b(stack_a, stack_b);
			printf("---------- Automove ----------\n");
			print_ll(*stack_a, *stack_b);
		}
		else
			reverse_rotate_a(stack_a, 0);
	}
	return(stack_a);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	// char	*instruction;

	if (argc <= 1)
		return (0);
	stack_a = list_builder(argc, argv);
	if (!stack_a)
		return (return_error());
	stack_b = malloc(sizeof(t_list));
	printf("---------ENTRY STACK:-----------\n");
	print_ll(*stack_a, *stack_b);
	int i = 0;
	while (i++ < 30)
	{
		
		stack_a = solver(stack_a, stack_b);
		
		// instruction = get_next_line(0);
		// if (instruction == NULL)
		// 	break ;
		// if(apply_instructions(instruction, stack_a, stack_b))
		// 	return(return_error());
	}
	// super_cool_merge_stack_sort(stack_a, stack_b);
	// MergeSort(stack_a);
	printf("\n---------- done ----------\n");
	
	delete_list(*stack_a);
	delete_list(*stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
