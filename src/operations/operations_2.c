/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:49:34 by alkane            #+#    #+#             */
/*   Updated: 2023/06/25 18:27:02 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate_a(int *arr, int supress)
{
	int i;

	i = 0;
	while (arr[i] != -1)
		i++;
	if (i <= 1)
        return;
    int last = arr[i - 1];
	i -= 1;
	while(i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
    arr[0] = last;
	if (!supress)
		write(1, "ra\n", 3);
}

void	rotate_b(int *arr, int supress)
{
	int i;

	i = 0;
	while (arr[i] != -1)
		i++;
	if (i <= 1)
        return;
    int last = arr[i - 1];
	i -= 1;
	while(i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
    arr[0] = last;
	if (!supress)
		write(1, "rb\n", 3);
}

void	double_rotate(int *head_a, int *head_b, int supress)
{
	rotate_a(head_a, 1);
	rotate_b(head_b, 1);
	if (!supress)
		write(1, "rr\n", 3);
}
