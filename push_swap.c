/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:09:53 by alistair          #+#    #+#             */
/*   Updated: 2022/02/05 16:28:11 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <unistd.h>

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
	write(1, "Error\n", 6);
	return (0);
}

t_list	*print_gne(t_list *node, int *holder)
{
	t_list	*empty;

	empty = malloc(sizeof(t_list));
	// empty->content = 0;
	empty->index = 0;
	empty->next = NULL;
	if (node == NULL)
	{
		*holder = 0;
		return (empty);
	}
	else
		// *holder = node->content;
		*holder = node->index;
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

void swap(t_list *a, t_list *b)
{
	int temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

void bubble_sort(t_list *start)
{
	int swapped;
	t_list *ptr1;
	t_list *lptr;
	
	ptr1 = NULL;
	lptr = NULL;
	if (start == NULL)
		return;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr1 = start;
		while (ptr1->next != lptr)
		{
			if (ptr1->content > ptr1->next->content)
			{ 
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}

static	t_list	*copy(t_list *head)
{
	t_list	*current;
	t_list	*new_list;
	t_list	*tail;

	current = head;
	new_list = NULL;
	while (current != NULL)
	{
		if (new_list == NULL)
		{
			new_list = ft_lstnew(current->content);
			new_list->index = current->index;
			tail = new_list;
		}
		else
		{
			tail->next = (t_list *)malloc(sizeof(t_list));
			tail = tail->next;
			tail->index = current->index;
			tail->content = current->content;
			tail->next = NULL;
		}
		current = current->next;
	}
	return (new_list);
}

int	get_nth(t_list *head, int index)
{
	t_list	*current;
	int		count;

	current = head;
	count = 0;
	while (current != NULL)
	{
		if (count == index)
			return (current->content);
		count++;
		current = current->next;
	}
	return (-1);
}

void	indexer(t_list *stack_a)
{
	t_list	*sorted;
	int		i;

	sorted = copy(stack_a);
	// merge_sort(sorted);
	bubble_sort(sorted);
	while (stack_a != NULL)
	{
		i = 1;
		while (i < ft_lstsize(sorted))
		{
			if (stack_a->content == get_nth(sorted, i))
				stack_a->index = i;
			i++;
		}
		stack_a = stack_a->next;
	}
}




int	max_run(t_list **head, t_state *state)
{
	t_list	*temp;
	int		temp_len;
	int		i;
	
	temp = copy(*head);
	ft_lstadd_back(&temp, copy(*head));
	i = 0;
	temp_len = 1;
	state->len = 1;
	while ((temp)->next != NULL)
	{
		// if ((temp)->next->content > (temp)->content)
		if ((temp)->next->index > (temp)->index)
			temp_len++;
		else
		{
			if (state->len <= temp_len)
			{
				state->len = temp_len;
				state->run_start = i - state->len + 1;
				state->run_end = i;
			}
			temp_len = 1;
		}
		i++;
		temp = (temp)->next;
	}
	// circular
	if (state->run_end >= ft_lstsize(*head))
		state->run_end = state->run_end - ft_lstsize(*head);
	if (state->run_start >= ft_lstsize(*head))
		state->run_start = state->run_start - ft_lstsize(*head);
	// printf("Lower idx:%d | Upper idx:%d\n", state->run_start, state->run_end);
	// printf("Run lower:%d | Run upper:%d", get_nth(*head, state->run_start), get_nth(*head, state->run_end));
	// printf("\nLen: %d\n", state->len);
	return (state->len);
}

void	solver(t_list **stack_a, t_list **stack_b)
{
	t_state	*state;
	// t_list	*current;

	// current = *stack_a;
	state = malloc(sizeof(t_state));
	// max_run(stack_a, state);
	
	printf("----------b4:---------\n");
	print_ll(*stack_a, *stack_b);
	// while (max_run(stack_a, state) < (ft_lstsize(*stack_a) || ft_lstsize(*stack_b))
	int i = 0;
	while (i < 100)
	{
		printf("run len %d\n", max_run(stack_a, state));
		// state is updated each while loop iteration
		// if the run starts at the first index should be shifted down
		if (state->run_start == 0)
		{
			reverse_rotate_a(stack_a, 0);
		}
		// if the run end is less than the len run is "looped"
		else if (state->run_end < state->len)
		{
			if (state->run_end > (ft_lstsize(*stack_a) - state->run_start))
				reverse_rotate_a(stack_a, 0);
			else
				rotate_a(stack_a, 0);
		}
		// else if ((*stack_a)->index > (*stack_a)->next->index && state->run_end > 2)
		// 	swap_a(stack_a, 0);
		// only if the value isnt part of the run and
		else if (ft_lstsize(*stack_a) > 2)
		{
			if (((*stack_a)->next->next->index - (*stack_a)->index) == 1)
				swap_a(stack_a, 0);
			else
				push_b(stack_a, stack_b);
		}

		// else if (state->run_start > 0)
		// 	push_b(stack_a, stack_b);
		printf("----------dannach:---------\n");
		print_ll(*stack_a, *stack_b);
		// if

		i++;
	}
}

// if a value fits into the range given by the run lowest and greater element of stack_b, push into stack b

// for value in stack b, check the moves to put in the right positon in the run

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
	solver(stack_a, stack_b);
	
	printf("----------\"solved\":---------\n");
	print_ll(*stack_a, *stack_b);

	delete_list(*stack_a);
	delete_list(*stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
