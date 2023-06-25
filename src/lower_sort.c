/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 05:22:39 by alistair          #+#    #+#             */
/*   Updated: 2023/06/25 18:50:46 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_lowest(int *stack_a)
{
	int	i;
	int	val;

	i = 1;
	val = stack_a[0];
	while (stack_a[i] != -1)
	{
		if (stack_a[i] < val)
			val = stack_a[i];
		i++;
	}
	return (val);
}

static void	align_stack(int low, int *stack_a)
{
	int	i;

	i = 0;
	while (stack_a[i] != low)
		i++;
	int len = lstsize(stack_a);
	i -= len;
	if (i > 2)
	{
		while (stack_a[len - 1] != low)
			reverse_rotate_a(stack_a, 0);
	}
	else
	{
		while (stack_a[len - 1] != low)
			rotate_a(stack_a, 0);
	}
}

void	sort_three(int *stack_a)
{
	if (!(stack_a[0] < stack_a[1] && \
		stack_a[1] < stack_a[2]))
	{
		if (stack_a[0] > stack_a[1] && \
			stack_a[1] < stack_a[2] && \
			stack_a[2] < stack_a[0])
			rotate_a(stack_a, 0);
		else if (stack_a[0] > stack_a[1] && \
			stack_a[1] > stack_a[2])
		{
			rotate_a(stack_a, 0);
			swap_a(stack_a, 0);
		}
		else if (stack_a[0] < stack_a[1] && \
			stack_a[0] > stack_a[2])
			reverse_rotate_a(stack_a, 0);
		else if (stack_a[0] > stack_a[1] && \
			stack_a[2] > stack_a[0])
			swap_a(stack_a, 0);
		else
		{
			reverse_rotate_a(stack_a, 0);
			swap_a(stack_a, 0);
		}
	}
}

void	sort_four(int *stack_a, int *stack_b)
{
	int	low;

	low = get_lowest(stack_a);
	while (stack_a[0] != low)
		rotate_a(stack_a, 0);
	push_b(stack_a, stack_b, 0);
	sort_three(stack_a);
	push_a(stack_a, stack_b, 0);
}

void	sort_five(int *stack_a, int *stack_b)
{
	int	low;
	int	len;

	low = get_lowest(stack_a);
	// len = ft_lstsize(*stack_a);
	len = 0;
	while(stack_a[len] != -1)
		len++;
	
	printf("sort five low:[%d]\n", low);
	
	align_stack(low, stack_a);
	push_b(stack_a, stack_b, 0);
	low = get_lowest(stack_a);
	if (low == stack_a[len - 1])
		reverse_rotate_a(stack_a, 0);
	else
	{
		while (stack_a[0] != low)
			rotate_a(stack_a, 0);
	}
	push_b(stack_a, stack_b, 0);
	sort_three(stack_a);
	push_a(stack_a, stack_b, 0);
	push_a(stack_a, stack_b, 0);
}
