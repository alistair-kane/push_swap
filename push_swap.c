/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:09:53 by alistair          #+#    #+#             */
/*   Updated: 2022/01/14 02:02:23 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <unistd.h>

void	push(t_list **head_ref, int new_data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	new_node -> content = new_data;
	new_node -> next = (*head_ref);
	(*head_ref) = new_node;
}

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

t_list **list_builder(int argc, char **argv)
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
			return(NULL);
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

void	print_ll(t_list *head_ref)
{
	t_list	*new_node;

	new_node = head_ref;
	printf("Iterating through the elements of the linked list : \n");
	while (new_node != NULL)
	{
		printf("%i \n", new_node->content);
		new_node = new_node->next;
	}
}

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
  struct Node* result = NULL;
 
  /* Base cases */
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
 
  /* Pick either a or b, and recur */
  if (a->data <= b->data)
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}

void delete_list(t_list *head_ref)
{
	if (head_ref == NULL)
		return ;
	delete_list(head_ref -> next);
	free(head_ref);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;

	if (argc <= 1)
		return (0);
	stack_a = list_builder(argc, argv);
	if (!stack_a)
		return (return_error());
	print_ll(*stack_a);
	
	delete_list(*stack_a);
	free(stack_a);
	return (0);
}
