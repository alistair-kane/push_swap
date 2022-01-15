/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:09:53 by alistair          #+#    #+#             */
/*   Updated: 2022/01/15 18:39:56 by alkane           ###   ########.fr       */
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

void	print_ll(t_list *head_ref, char *ref)
{
	t_list	*new_node;

	new_node = head_ref;
	printf("Iterating through the elements of %s linked list : \n", ref);
	while (new_node != NULL)
	{
		printf("%i \n", new_node->content);
		new_node = new_node->next;
	}
}

void	delete_list(t_list *head_ref)
{
	if (head_ref == NULL)
		return ;
	delete_list(head_ref -> next);
	free(head_ref);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	// int		i;
	
	if (argc <= 1)
		return (0);
	stack_a = list_builder(argc, argv);
	if (!stack_a)
		return (return_error());
	print_ll(*stack_a, "a");
	stack_b = malloc(sizeof(t_list));
	// i = -1;
	// printf("stack a size: %i\n",ft_lstsize(*stack_a));
	// while(++i <= (ft_lstsize(*stack_a) / 2))
	// 	push_b(stack_a, stack_b);
	rotate_a(stack_a, 0);
	print_ll(*stack_a, "a");
	// print_ll(*stack_b, "b");
	
	delete_list(*stack_a);
	delete_list(*stack_b);
	
	free(stack_a);
	return (0);
}










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