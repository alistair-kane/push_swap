/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 05:25:45 by alistair          #+#    #+#             */
/*   Updated: 2023/06/25 18:30:18 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static void	swap(t_list *a, t_list *b)
// {
// 	int	temp;

// 	temp = a->content;
// 	a->content = b->content;
// 	b->content = temp;
// }

// static void	bubble_sort(t_list *start)
// {
// 	int		swapped;
// 	t_list	*ptr_1;
// 	t_list	*l_ptr;

// 	ptr_1 = NULL;
// 	l_ptr = NULL;
// 	if (start == NULL)
// 		return ;
// 	swapped = 1;
// 	while (swapped)
// 	{
// 		swapped = 0;
// 		ptr_1 = start;
// 		while (ptr_1->next != l_ptr)
// 		{
// 			if (ptr_1->content > ptr_1->next->content)
// 			{
// 				swap(ptr_1, ptr_1->next);
// 				swapped = 1;
// 			}
// 			ptr_1 = ptr_1->next;
// 		}
// 		l_ptr = ptr_1;
// 	}
// }

// static	t_list	*copy(t_list *head)
// {
// 	t_list	*current;
// 	t_list	*new_list;
// 	t_list	*tail;

// 	current = head;
// 	new_list = NULL;
// 	while (current != NULL)
// 	{
// 		if (new_list == NULL)
// 		{
// 			new_list = ft_lstnew(current->content);
// 			new_list->index = current->index;
// 			tail = new_list;
// 		}
// 		else
// 		{
// 			tail->next = (t_list *)malloc(sizeof(t_list));
// 			tail = tail->next;
// 			tail->index = current->index;
// 			tail->content = current->content;
// 			tail->next = NULL;
// 		}
// 		current = current->next;
// 	}
// 	return (new_list);
// }

int* copyAndSortArray(const int* arr, int size) {
    // Create a new array to store the copied elements
    int* copiedArray = (int*)malloc(size * sizeof(int));
    if (copiedArray == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Copy the elements from the original array to the copied array
    for (int i = 0; i < size; i++) {
        copiedArray[i] = arr[i];
    }

    // Sort the copied array using any sorting algorithm (e.g., bubble sort)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (copiedArray[j] > copiedArray[j + 1]) {
                int temp = copiedArray[j];
                copiedArray[j] = copiedArray[j + 1];
                copiedArray[j + 1] = temp;
            }
        }
    }

    return copiedArray;
}

void	indexer(int *stack_a)
{
	int	*sorted;
	int	i;
	int j;
	int size;

	size = lstsize(stack_a);
    printf("SIZE 1: %d\n", size);
	sorted = copyAndSortArray(stack_a, size);
    int indexes[size];
    i = 0;
    // Create an array of indexes based on the sorted array
    while (i < size) 
    {
        j = 0;
        while (j < size) {
            if (stack_a[i] == sorted[j])
            {
                indexes[i] = j;
                break;
            }
            j++;
        }
        i++;
    }
    

	// size = lstsize(indexes);
    // printf("SIZE 2: %d\n", size);
    // Overwrite the values in the stack_a array with their indexes
    i = 0;
    while (i < size) {
        stack_a[i] = (indexes[i]);
        i++;
    }
    for (int i = 0; i < size; i++)
		printf("val in stack_a: %d\n", stack_a[i]);
	free(sorted);
}
