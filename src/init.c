/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 05:43:28 by alistair          #+#    #+#             */
/*   Updated: 2023/06/23 06:22:33 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_dup(int *intarray)
{
	int	count;
	int	size;
	int	i;
	int j;

	size = sizeof(intarray) / sizeof(intarray[0]);
	count = 0;
	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (intarray[i] == intarray[j])
			{
				count++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (count);
}

static void	*return_free(t_list **stack_a)
{
	delete_list(*stack_a);
	free(stack_a);
	return (NULL);
}

int	*list_builder(int argc, char **argv)
{
	int	*stack_a;
	int		i;
	long	val;
	
	// !!!!!!
	stack_a = malloc(argc - 1 * sizeof(int));
	i = 1;
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		if (val >= 2147483648 || val < -2147483648 || *argv[i] == '\0')
			return (return_free(stack_a));
		else
		{
			// if (i++ == 1)
			// 	*stack_a = ft_lstnew(val);
			// else
			// {
			stack_a[i - 1] = val;
				// ft_lstadd_back(stack_a, ft_lstnew(val));
			if (count_dup(*stack_a))
				return (return_free(stack_a));
		// }
		}
	}
	return (stack_a);
}
