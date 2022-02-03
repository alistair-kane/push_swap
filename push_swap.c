/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:09:53 by alistair          #+#    #+#             */
/*   Updated: 2022/02/03 12:38:34 by alkane           ###   ########.fr       */
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
	empty->content = 0;
	empty->next = NULL;
	if (node == NULL)
	{
		*holder = 0;
		return (empty);
	}
	else
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

t_list	*merge(t_list *a, t_list *b)
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->content <= b->content)
	{
		result = a;
		result->next = merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge(a, b->next);
	}
	return (result);
}

void	split(t_list *source, t_list **front, t_list **back)
{
	t_list	*fast;
	t_list	*slow;

	slow = source;
	fast = source -> next;
	while (fast != NULL)
	{
		fast = fast -> next;
		if (fast != NULL)
		{
			slow = slow -> next;
			fast = fast -> next;
		}
	}
	*front = source;
	*back = slow -> next;
	slow -> next = NULL;
}

void	merge_sort(t_list **stack_a)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *stack_a;
	if ((head == NULL) || (head->next == NULL))
		return ;
	split(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	head = merge(a, b);
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
			tail = new_list;
		}
		else
		{
			tail->next = (t_list *)malloc(sizeof(t_list));
			tail = tail->next;
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
	merge_sort(&sorted);
	while (stack_a != NULL)
	{
		i = 0;
		while (i < ft_lstsize(sorted))
		{
			if (stack_a->content == get_nth(sorted, i))
				stack_a->index = i;
			i++;
		}
		stack_a = stack_a->next;
	}
}

void	max_run(t_list **head)
{
	t_list	*temp;
	int		run_start;
	int		run_end;
	int		len;
	int		max_len;
	int		i;
	
	temp = copy(*head);
	ft_lstadd_back(&temp, copy(*head));
	i = 0;
	len = 1;
	max_len = 1;
	while ((temp)->next != NULL)
	{
		if ((temp)->next->content > (temp)->content)
			len++;
		else
		{
			if (max_len <= len)
			{
				max_len = len;
				run_start = i - max_len + 1;
				run_end = i;
			}
			len = 1;
		}
		i++;
		temp = (temp)->next;
	}
	// circular
	if (run_end >= ft_lstsize(*head))
		run_end = run_end - ft_lstsize(*head);
	if (run_start >= ft_lstsize(*head))
		run_start = run_start - ft_lstsize(*head);
	
	printf("Lower idx:%d | Upper idx:%d\n", run_start, run_end);
	printf("Run lower:%d | Run upper:%d", get_nth(*head, run_start), get_nth(*head, run_end));
	printf("\nLen: %d\n", max_len);
}

void	solver(t_list **stack_a, t_list **stack_b)
{
	while (max_run(stack_a) < ft_lstsize(*stack_a))
	{
		if (*)
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
	max_run(stack_a);
	
	// indexer(*stack_a);
	// printf("----------INDEXED:---------\n");
	// print_ll(*stack_a, *stack_b);

	delete_list(*stack_a);
	delete_list(*stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
