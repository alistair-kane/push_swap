/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:03:38 by alistair          #+#    #+#             */
/*   Updated: 2023/06/25 18:40:08 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap_a(int *arr, int supress)
{
	int	temp;
	int i = 0;

	if (arr[0] == -1 || arr[1] == -1)
		return ;	
	while (arr[i] != -1)
		i++;
	temp = arr[i - 1];
	arr[i - 1] = arr[i - 2];
	arr[i - 2] = temp;
	if (!supress)
		write(1, "sa\n", 3);
}

void	swap_b(int *arr, int supress)
{
	int	temp;
	int i = 0;

	if (arr[0] == -1 || arr[1] == -1)
		return ;	
	while (arr[i] != -1)
		i++;
	temp = arr[i - 1];
	arr[i - 1] = arr[i - 2];
	arr[i - 2] = temp;
	if (!supress)
		write(1, "sb\n", 3);
}

void	double_swap(int *head_a, int *head_b, int supress)
{
	swap_a(head_a, 1);
	swap_b(head_b, 1);
	if (!supress)
		write(1, "ss\n", 3);
}

int	push_a(int *head_a, int *head_b, int supress)
{
	int new_node;
	int i;

	if (head_b[0] == -1)
		return (0);
	i = 0;
	while (head_b[i] != -1)
		i++;
	new_node = head_b[i - 1]; // should be last element in array, not first
	// last element is taken so should be replaced with -1
	head_b[i - 1] = -1;
	// now go to the end of stack b to place it in the right place there
	i = 0;
	while (head_a[i] != -1)
		i++;
	head_a[i] = new_node;
	if (!supress)
		write(1, "pa\n", 3);
	return (1);
}

int	push_b(int *head_a, int *head_b, int supress)
{
	int new_node;
	int i;

	if (head_a[0] == -1)
		return (0);	
	i = 0;
	while (head_a[i] != -1)
		i++;
	new_node = head_a[i - 1]; // should be last element in array, not first
	// last element is taken so should be replaced with -1
	head_a[i - 1] = -1;
	// now go to the end of stack b to place it in the right place there
	i = 0;
	while (head_b[i] != -1)
		i++;
	head_b[i] = new_node;
	if (!supress)
		write(1, "pb\n", 3);
	return (1);
}
