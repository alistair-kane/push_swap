/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:09:53 by alistair          #+#    #+#             */
/*   Updated: 2022/01/16 18:50:17 by alkane           ###   ########.fr       */
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

t_list *print_gne(t_list *node, int *holder)
{
	t_list	*empty;

	empty = malloc(sizeof(t_list));
	empty->content = 0;
	empty->next = NULL;
	if (node == NULL)
	{
		*holder = 0;
		return(empty);
	}
	else
		*holder = node->content;
	return(node);
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

void	merge_sort(t_list **stack, t_list **stack_a, t_list **stack_b)
{
	int	a_size;
	int	b_size;
	
	a_size = 0;
	b_size = 0;
	if (!ft_lstsize(*stack))
		return ;
	while (a_size++ < ft_lstsize(*stack))
		push_b(stack_a, stack_b);
	while (ft_lstsize(*stack))
	{
		push_a(stack_a, stack_b);
		b_size++;
	}
	
	merge_sort(stack_a, stack_a, stack_b);
	merge_sort(stack_b, stack_a, stack_b);

	
	printf("----------IN RECURSION:----------\n");
	print_ll(*stack_a, *stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	// int		cluster_size;
	// int		i;

	if (argc <= 1)
		return (0);
	stack_a = list_builder(argc, argv);
	if (!stack_a)
		return (return_error());
	stack_b = malloc(sizeof(t_list));
	printf("---------ENTRY STACK:-----------\n");
	print_ll(*stack_a, *stack_b);
	
	while (ft_lstsize(*stack_a) > ft_lstsize(*stack_b))
		push_b(stack_a, stack_b);
		
	merge_sort(stack_a, stack_a, stack_b);
	merge_sort(stack_b, stack_a, stack_b);
	// cluster_size = 1;
	// while(ft_lstsize(*stack_a) > 1)
	// {
	// 	if (((*stack_a)->content) > ((*stack_a)->next->content))
	// 	{
	// 		swap_a(stack_a, 0);
	// 		push_b(stack_a, stack_b);
	// 		push_b(stack_a, stack_b);
	// 	}
	// 	else
	// 	{
	// 		// swap_a(stack_a, 0);
	// 		push_b(stack_a, stack_b);
	// 		push_b(stack_a, stack_b);
	// 	}
	// 	// cluster_size += 2;
	// }
	// // clusters++;

	
	// while(ft_lstsize(*stack_b) > 1)
	// {
	// 	if (((*stack_b)->next->content) < ((*stack_b)->next->next->next->content))
	// 	{
	// 		swap_b(stack_b, 0);
	// 		push_a(stack_a, stack_b);
	// 	}
	// 	else
	// 	{
	// 		reverse_rotate_b(stack_b, 0);
	// 		push_a(stack_a, stack_b);
	// 	}
	// }	
	// 	// if (((*stack_a)->content) < ((*stack_b)->content))
	// 	// {
	// 	// 	rotate_a(stack_a, 0);
	// 	// 	push_a(stack_a, stack_b);
	// 	// }
	// 	clusters++;
	// }
	// printf("----------SECOND SORT:---------\n");
	// print_ll(*stack_a, *stack_b);

	delete_list(*stack_a);
	delete_list(*stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}

// gcc -Wall -Werror -Wextra -g list_instructions_1.c list_instructions_2.c list_instructions_3.c libft/libft.a push_swap.c -o push_swap

// t_list*	SortedMerge(t_list* a, t_list* b);
// void	FrontBackSplit(t_list* source, t_list** frontRef, t_list** backRef);

// /* sorts the linked list by changing next pointers (not data) */
// void	MergeSort(t_list** headRef)
// {
// 	t_list* head = *headRef;
// 	t_list* a;
// 	t_list* b;

// 	/* Base case -- length 0 or 1 */
// 	if ((head == NULL) || (head->next == NULL)) {
// 		return;
// 	}

// 	/* Split head into 'a' and 'b' sublists */
// 	FrontBackSplit(head, &a, &b);

// 	/* Recursively sort the sublists */
// 	MergeSort(&a);
// 	MergeSort(&b);

// 	/* answer = merge the two sorted lists together */
// 	*headRef = SortedMerge(a, b);
// }

// /* See https:// www.geeksforgeeks.org/?p=3622 for details of this 
// function */
// // takes 2 elements
// // the moving happens here
// t_list*	SortedMerge(t_list* a, t_list* b)
// {
// 	t_list* result = NULL;

// 	/* Base cases */
// 	if (a == NULL)
// 		return (b);
// 	else if (b == NULL)
// 		return (a);

// 	/* Pick either a or b, and recur */
// 	if (a->content <= b->content)
// 	{
// 		result = a;
// 		result->next = SortedMerge(a->next, b);
// 	}
// 	else
// 	{
// 		result = b;
// 		result->next = SortedMerge(a, b->next);
// 	}
// 	return (result);
// }

// /* Split the nodes of the given list into front and back halves,
// 	and return the two lists using the reference parameters.
// 	If the length is odd, the extra node should go in the front list.
// 	Uses the fast/slow pointer strategy. */
// void	FrontBackSplit(t_list* source, t_list** frontRef, t_list** backRef)
// {
// 	t_list* fast;
// 	t_list* slow;

// 	slow = source;
// 	fast = source -> next;
// 	/* Advance 'fast' two nodes, and advance 'slow' one node */
// 	while (fast != NULL) {
// 		fast = fast -> next;
// 		if (fast != NULL) {
// 			slow = slow -> next;
// 			fast = fast -> next;
// 		}
// 	}
// 	/* 'slow' is before the midpoint in the list, so split it in two
// 	at that point. */
// 	*frontRef = source;
// 	*backRef = slow -> next;
// 	slow -> next = NULL;
// }