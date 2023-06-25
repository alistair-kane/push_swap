/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:49:34 by alkane            #+#    #+#             */
/*   Updated: 2023/06/25 18:26:59 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reverse_rotate_a(int *arr, int supress)
{
	int i;

	i = 0;
	while (arr[i] != -1)
		i++;
	if (i <= 1)
        return;
    int first = arr[0];
	i -= 1;
	int j = 0;
	while(j < i)
	{
		arr[j] = arr[j + 1];
		j++;
	}
    arr[i] = first;
	if (!supress)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(int *arr, int supress)
{
	int i;

	i = 0;
	while (arr[i] != -1)
		i++;
	if (i <= 1)
        return;
    int first = arr[0];
	i -= 1;
	int j = 0;
	while(j < i)
	{
		arr[j] = arr[j + 1];
		j++;
	}
    arr[i] = first;
	if (!supress)
		write(1, "rrb\n", 4);
}

void	double_reverse_rotate(int *head_a, int *head_b, int supress)
{
	reverse_rotate_a(head_a, 1);
	reverse_rotate_b(head_b, 1);
	if (!supress)
		write(1, "rrr\n", 4);
}
