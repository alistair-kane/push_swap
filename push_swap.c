/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:09:53 by alistair          #+#    #+#             */
/*   Updated: 2022/02/18 00:57:51 by alkane           ###   ########.fr       */
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
	// empty->content = 0;
	empty->index = 0;
	empty->next = NULL;
	if (node == NULL)
	{
		*holder = 0;
		return (empty);
	}
	else
		// *holder = node->content;
		*holder = node->index;
	free(empty);
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

void swap(t_list *a, t_list *b)
{
	int temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

void bubble_sort(t_list *start)
{
	int swapped;
	t_list *ptr1;
	t_list *lptr;
	
	ptr1 = NULL;
	lptr = NULL;
	if (start == NULL)
		return;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr1 = start;
		while (ptr1->next != lptr)
		{
			if (ptr1->content > ptr1->next->content)
			{ 
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
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
			new_list->index = current->index;
			tail = new_list;
		}
		else
		{
			tail->next = (t_list *)malloc(sizeof(t_list));
			tail = tail->next;
			tail->index = current->index;
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

int	find_forward_shared(int a_rotate, int b_rotate)
{
	int i = 0;
	
	while (a_rotate && b_rotate)
	{
		a_rotate--;
		b_rotate--;
		i++;
	}
	if (a_rotate > 0)
	{
		while (a_rotate--)
			i++;
	}
	if (b_rotate > 0)
	{
		while (b_rotate--)
			i++;
	}
	return (i);
}

int	find_reverse_shared(int a_reverse, int b_reverse)
{
	int i = 0;
	
	while (a_reverse && b_reverse)
	{
		a_reverse--;
		b_reverse--;
		i++;
	}
	if (a_reverse > 0)
	{
		while (a_reverse--)
			i++;
	}
	if (b_reverse > 0)
	{
		while (b_reverse--)
			i++;
	}
	return (i);
}

int	get_nth_idx(t_list *head, int index)
{
	t_list	*current;
	int		count;

	current = head;
	count = 0;
	while (current != NULL)
	{
		if (count == index)
			return (current->index);
		count++;
		current = current->next;
	}
	return (-1);
}

int	min(int x, int y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

int	max_of(int x, int y)
{
	if (x < y)
		return (y);
	else
		return (x);
}

void	indexer(t_list *stack_a)
{
	t_list	*sorted;
	int		i;

	sorted = copy(stack_a);
	bubble_sort(sorted);
	while (stack_a != NULL)
	{
		i = 1;
		while (i < ft_lstsize(sorted))
		{
			if (stack_a->content == get_nth(sorted, i))
				stack_a->index = i;
			i++;
		}
		stack_a = stack_a->next;
	}
	free(sorted);
}

int	max_run(t_list **head, t_state *state)
{
	int	i;
	int	j;
	int	k;
	int	n;
	int	temp_len;

	i = -1;
	j = 0;
	k = 1;
	n = ft_lstsize(*head);
	temp_len = 1;
	state->len = 1;
	while (++i < (n * 2))
	{
		if (get_nth_idx(*head, j++) < get_nth_idx(*head, k++))
			temp_len++;
		else
		{
			if (state->len < temp_len)
			{
				state->len = temp_len;
				state->run_start = i - (state->len - 1);
				state->run_end = i;
			}
			temp_len = 1;
		}
		if (k == n)
			k = 0;
		if (j == n)
			j = 0;
	}
	if (state->run_end >= n)
		state->run_end = state->run_end - n;
	if (state->run_start >= n)
		state->run_start = state->run_start - n;
	return (state->len);
}

void	insert_pos(int val, t_list **stack_a, t_list **stack_b, t_state *state)
{
	int	a_len;
	int m;
	int i;
	int fits;
	
	a_len = ft_lstsize(*stack_a);
	max_run(stack_a, state);
	if (val < get_nth_idx(*stack_a, state->run_start))
		m = state->run_start;
	
	else if (val > get_nth_idx(*stack_a, state->run_end))
		m = state->run_end;
	else
	{
		fits = 0;
		i = state->run_start;
		while (fits != 2)
		{
			fits = 0;
			// printf("Comp Lower: %d", get_nth_idx(*stack_a, i));
			if (val > get_nth_idx(*stack_a, i)) 
				fits++;
			if (i == a_len)
				i = -1;
			// printf(" Comp Upper: %d\n", get_nth_idx(*stack_a, i + 1));
			if (val < get_nth_idx(*stack_a, i + 1))
				fits++;
			i++;
		}
		m = i;
	}
	state->a_moves = m;

	i = 0;
	while (get_nth_idx(*stack_b, i) != val)
		i++;
	// if (i > (ft_lstsize(*stack_b) / 2))
	// 	i = ft_lstsize(*stack_b) - i;
	state->b_moves = i;
}

int	find_bin(int val, t_list **stack_b)
{
	int	len;
	int i;
	int j;
	int temp;
	int min_val;
	int min_idx;
	int bin_size;

	bin_size = 10;
	len = ft_lstsize(*stack_b); 
	if (len == 0 || len == 1)
		return (0);
	i = 0;
	min_val = 1024;
	while (i < len)
	{
		temp = get_nth_idx(*stack_b, i) / bin_size;
		if (temp < min_val)
		{
			min_val = temp;
			min_idx = i;
		}
		i++;
	}
	i = min_idx;
	j = 0;
	while (j < len)
	{
		temp = get_nth_idx(*stack_b, i) / bin_size;
		if (val / bin_size <= temp)
			return(i);
		j++;
		i++;
		if (i == len)
			i = 0;
	}
	return (max_of(0, min_idx - 1));
}

void	stack_b_import(t_list **stack_a, t_list **stack_b, t_state *state)
{
	int i;
	int limit;

	int a_rotate;
	int a_reverse;
	int	b_rotate;
	int	b_reverse;

	int move_thresh;
	int lowest_val;
	int val;

	int unshared;
	int forward;
	int reverse;
	
	//looped
	if (state->run_end < state->run_start)
	{
		i = state->run_end;
		limit = state->run_start;
	}
	else
	{
		i = 0;
		limit = ft_lstsize(*stack_a);
	}
	
	move_thresh = 5;
	lowest_val = -1;
	while (i < limit)
	{
		val = get_nth_idx(*stack_a, i);
		a_rotate = i;
		b_rotate = find_bin(val, stack_b);
		a_reverse = ft_lstsize(*stack_a) - a_rotate;
		b_reverse = ft_lstsize(*stack_b) - b_rotate;
		
		unshared = min(a_rotate, a_reverse) + min(b_rotate, b_reverse);
		forward = find_forward_shared(a_rotate, b_rotate);
		reverse = find_reverse_shared(a_reverse, b_reverse);
		if (!(i >= state->run_start && i <= state->run_end))
		{
			if (unshared <= min(forward, reverse))
			{
				if (unshared < move_thresh)
				{
					move_thresh = unshared;
					lowest_val = val;
				}
			}
			else if (forward < reverse)
			{
				if (forward < move_thresh)
				{
					move_thresh = forward;
					lowest_val = val;
				}
			}
			else
			{
				if (reverse < move_thresh)
				{
					move_thresh = reverse;
					lowest_val = val;
				}
			}
		}
		i++;
	}
	// printf("Lowest Val: %d | Moves: %d\n", lowest_val ,move_thresh);
	i = 0;
	while (lowest_val != get_nth_idx(*stack_a, i))
		i++;
	a_rotate = i;
	b_rotate = find_bin(lowest_val, stack_b);
	
	a_reverse = ft_lstsize(*stack_a) - a_rotate;
	b_reverse = ft_lstsize(*stack_b) - b_rotate;
	
	unshared = min(a_rotate, a_reverse) + min(b_rotate, b_reverse);
	forward = find_forward_shared(a_rotate, b_rotate);
	reverse = find_reverse_shared(a_reverse, b_reverse);
	if (unshared < forward && unshared < reverse)
	{
		if (a_reverse < a_rotate)
		{	
			while (a_reverse--)
				reverse_rotate_a(stack_a, 0);
		}
		else
		{
			while(a_rotate--)
				rotate_a(stack_a, 0);
		}
		if (b_reverse < b_rotate)
		{
			while (b_reverse--)
				reverse_rotate_b(stack_b, 0);
		}
		else
		{
			while (b_rotate--)
				rotate_b(stack_b, 0);
		}
		push_b(stack_a, stack_b);
	}
	else if (forward < reverse)
	{
		while (a_rotate && b_rotate)
		{
			a_rotate--;
			b_rotate--;
			double_rotate(stack_a, stack_b);
		}
		while (a_rotate--)
			rotate_a(stack_a, 0);
		while (b_rotate--)
			rotate_b(stack_b, 0);
		push_b(stack_a, stack_b);
	}
	else
	{
		while (a_reverse && b_reverse)
		{
			a_reverse--;
			b_reverse--;
			double_reverse_rotate(stack_a, stack_b);
		}
		while (a_reverse--)
			reverse_rotate_a(stack_a, 0);
		while (b_reverse--)
			reverse_rotate_b(stack_b, 0);
		push_b(stack_a, stack_b);
	}	
}

void	stack_b_export2(t_list **stack_a, t_list **stack_b, t_state *state)
{
	// t_list	*current;

	int	a_rotate;
	int	b_rotate;
	int	a_reverse;
	int	b_reverse;

	int move_thresh;
	int lowest_val;
	int val;

	int unshared;
	int forward;
	int reverse;

	int i = 0;
	move_thresh = 8;
	lowest_val = -1;
	while (get_nth_idx(*stack_b, i) != -1)
	{
		val = get_nth_idx(*stack_b, i);
		insert_pos(val, stack_a, stack_b, state);
		a_rotate = state->a_moves;
		b_rotate = state->b_moves;
		a_reverse = ft_lstsize(*stack_a) - a_rotate;
		b_reverse = ft_lstsize(*stack_b) - b_rotate;
		
		unshared = min(a_rotate, a_reverse) + min(b_rotate, b_reverse);
		forward = find_forward_shared(a_rotate, b_rotate);
		reverse = find_reverse_shared(a_reverse, b_reverse);

		if (unshared <= min(forward, reverse))
		{
			if (unshared < move_thresh)
			{
				move_thresh = unshared;
				lowest_val = val;
			}
		}
		else if (forward < reverse)
		{
			if (forward < move_thresh)
			{
				move_thresh = forward;
				lowest_val = val;
			}
		}
		else
		{
			if (reverse < move_thresh)
			{
				move_thresh = reverse;
				lowest_val = val;
			}
		}
		i++;
	}
	// printf("Lowest Val: %d | Moves: %d\n", lowest_val ,move_thresh);
	// i = 0;
	// while (lowest_val != get_nth_idx(*stack_b, i))
	// 	i++;
	// if (move_thresh < 3)
	if (lowest_val != -1)
	{
		insert_pos(lowest_val, stack_a, stack_b, state);
		a_rotate = state->a_moves;
		b_rotate = state->b_moves;
		a_reverse = ft_lstsize(*stack_a) - a_rotate;
		b_reverse = ft_lstsize(*stack_b) - b_rotate;
		
		unshared = min(a_rotate, a_reverse) + min(b_rotate, b_reverse);
		forward = find_forward_shared(a_rotate, b_rotate);
		reverse = find_reverse_shared(a_reverse, b_reverse);
		if (unshared < forward && unshared < reverse)
		{
			if (a_reverse < a_rotate)
			{	
				while (a_reverse--)
					reverse_rotate_a(stack_a, 0);
			}
			else
			{
				while(a_rotate--)
					rotate_a(stack_a, 0);
			}
			if (b_reverse < b_rotate)
			{
				while (b_reverse--)
					reverse_rotate_b(stack_b, 0);
			}
			else
			{
				while (b_rotate--)
					rotate_b(stack_b, 0);
			}
			push_a(stack_a, stack_b);
		}
		else if (forward < reverse)
		{
			while (a_rotate && b_rotate)
			{
				a_rotate--;
				b_rotate--;
				double_rotate(stack_a, stack_b);
			}
			while (a_rotate--)
				rotate_a(stack_a, 0);
			while (b_rotate--)
				rotate_b(stack_b, 0);
			push_a(stack_a, stack_b);
		}
		else
		{
			while (a_reverse && b_reverse)
			{
				a_reverse--;
				b_reverse--;
				double_reverse_rotate(stack_a, stack_b);
			}
			while (a_reverse--)
				reverse_rotate_a(stack_a, 0);
			while (b_reverse--)
				reverse_rotate_b(stack_b, 0);
			push_a(stack_a, stack_b);
		}
	}
}

void	solver(t_list **stack_a, t_list **stack_b)
{
	t_state	*state;
	
	state = malloc(sizeof(t_state));
	state->max_idx = ft_lstsize(*stack_a);
	
	max_run(stack_a, state);
	// state->lowest_moves = 5;

	// while ((max_run(stack_a, state) < ft_lstsize(*stack_a)) || ft_lstsize(*stack_b))
	while ((max_run(stack_a, state) + ft_lstsize(*stack_b) < state->max_idx))
	{
		if (ft_lstsize(*stack_b))
		{
			// stack_b_export(stack_a, stack_b, state);
			stack_b_export2(stack_a, stack_b, state);
		}
		if (ft_lstsize(*stack_a) == max_run(stack_a, state) && ft_lstsize(*stack_b))
		{
			reverse_rotate_a(stack_a, 0);
		}
		else if (state->run_start == 0)
			reverse_rotate_a(stack_a, 0);
		else if (state->run_end < state->len)
		{
			if (state->run_end > (ft_lstsize(*stack_a) - state->run_start))
				reverse_rotate_a(stack_a, 0);
			else
				rotate_a(stack_a, 0);
		}
		else if (ft_lstsize(*stack_a) > 2)
		{
			if (((*stack_a)->next->next->index - (*stack_a)->index) == 1)
				swap_a(stack_a, 0);
			else
			{
				stack_b_import(stack_a, stack_b, state);
				// push_b(stack_a, stack_b);
			}
		}
		// printf("----------\"memory leak galore\":---------\n");
		// print_ll(*stack_a, *stack_b);
	}
	
	// end correction
	// insert_pos(-1, stack_a, stack_b, state);
	// while (get_nth_idx(*stack_a, 0) != 0)
	// {
	// 	if ((ft_lstsize(*stack_a) - state->a_moves) > state->a_moves)
	// 		rotate_a(stack_a, 0);
	// 	else
	// 		reverse_rotate_a(stack_a, 0);
	// }
	free(state);
}

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
	
	indexer(*stack_a);
	solver(stack_a, stack_b);
	
	printf("----------\"solved\":---------\n");
	print_ll(*stack_a, *stack_b);

	delete_list(*stack_a);
	delete_list(*stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}

// | awk '{for(i=1;i<=NF;i++)a[$i]++}END{for(o in a) printf "%s %s ",o,a[o]}'

// int	find_fewest_moves(t_list **stack_a, t_list **stack_b, t_state *state)
// {
// 	unsigned int	a_rotate;
// 	unsigned int	b_rotate;
// 	unsigned int	a_reverse;
// 	unsigned int	b_reverse;
// 	int val;
// 	int i = 0;
	
// 	int	unshared = 0;
// 	int shared_forward = 0;
// 	int shared_reverse = 0;
// 	int	lowest_moves = 0;
// 	int	lowest_val = 0;
// 	int	fewest_moves_val = 100;
	
// 	int final_unshared = 0;
// 	int final_shared_forward = 0;
// 	int final_shared_reverse = 0;
// 	while (get_nth_idx(*stack_b, i) != -1)
// 	{
// 		val = get_nth_idx(*stack_b, i);
// 		insert_pos(val, stack_a, stack_b, state);
// 		a_rotate = state->a_moves;
// 		b_rotate = state->b_moves;
// 		a_reverse = ft_lstsize(*stack_a) - a_rotate;
// 		b_reverse = ft_lstsize(*stack_b) - b_rotate;
		
// 		unshared = min(a_rotate, a_reverse) + min(b_rotate, b_reverse);
// 		shared_forward = find_forward_shared(a_rotate, b_rotate);
// 		shared_reverse = findd_reverse_shared(a_reverse, b_reverse);
		
// 		// printf("Val: %d\n", val);
// 		// printf("unshared: %d\n",min(a_rotate, a_reverse) + min(b_rotate, b_reverse));
// 		// printf("forward shared %d\n", find_forward_shared(a_rotate, b_rotate));
// 		// printf("reverse shared %d\n\n", findd_reverse_shared(a_reverse, b_reverse));
		
// 		if (unshared < min(shared_forward, shared_reverse))
// 			lowest_moves = unshared;
// 		else
// 			lowest_moves = min(shared_forward, shared_reverse);
// 		if (lowest_moves < fewest_moves_val)
// 		{
// 			final_unshared = unshared;
// 			final_shared_forward = shared_forward;
// 			final_shared_reverse = shared_reverse;
// 			fewest_moves_val = lowest_moves;
// 			lowest_val = val;
// 		}
// 		// printf("FMV %d\n",lowest_val);
// 		i++;
// 	}
// 	insert_pos(lowest_val, stack_a, stack_b, state);
// 	if (final_unshared < min(final_shared_forward, final_shared_reverse))
// 	// do the work for unshared
// 	{
// 		if (a_rotate < a_reverse)
// 		{
// 			while (a_rotate--)
// 				rotate_a(stack_a, 0);
// 		}
// 		else
// 		{
// 			while (a_reverse--)
// 				reverse_rotate_a(stack_a, 0);
// 		}
// 		if (b_rotate < b_reverse)
// 		{
// 			while (b_rotate--)
// 				rotate_b(stack_b, 0);
// 		}
// 		else
// 		{
// 			while (b_reverse--)
// 				reverse_rotate_b(stack_b, 0);
// 		}
// 		push_a(stack_a, stack_b);
// 	}
// 	// lowest_moves = unshared;
// 	else if (final_shared_forward < final_shared_reverse)
// 	// do the work for forward shared
// 	{
// 		while (a_rotate && b_rotate)
// 		{
// 			a_rotate--;
// 			b_rotate--;
// 			double_rotate(stack_a, stack_b);
// 		}
// 		while (a_rotate--)
// 			rotate_a(stack_a, 0);
// 		while (b_rotate--)
// 			rotate_b(stack_b, 0);
// 		push_a(stack_a, stack_b);
// 	}
// 	// lowest_moves = min(shared_forward, shared_reverse);
// 	else
// 	// do the work for reverse shared
// 	{
// 		while (a_reverse && b_reverse)
// 		{
// 			a_reverse--;
// 			b_reverse--;
// 			double_reverse_rotate(stack_a, stack_b);
// 		}
// 		while (a_reverse--)
// 			reverse_rotate_a(stack_a, 0);
// 		while (b_reverse--)
// 			reverse_rotate_b(stack_b, 0);
// 		push_a(stack_a, stack_b);
// 	}
// 	return (lowest_val);
// }


		// if ((min(b_rotate, b_reverse) + min(a_rotate, a_reverse)) < state->lowest_moves + 1)
		// {
		// 	if (a_rotate < a_reverse && b_rotate < b_reverse)
		// 	{
		// 		while (a_rotate && b_rotate)
		// 		{
		// 			a_rotate--;
		// 			b_rotate--;
		// 			double_rotate(stack_a, stack_b);
		// 		}
		// 		while (a_rotate--)
		// 			rotate_a(stack_a, 0);
		// 		while (b_rotate--)
		// 			rotate_b(stack_b, 0);
		// 	}
		// 	else if (a_reverse < a_rotate && b_reverse < b_rotate)
		// 	{
		// 		while (a_reverse && b_reverse)
		// 		{
		// 			a_reverse--;
		// 			b_reverse--;
		// 			double_reverse_rotate(stack_a, stack_b);
		// 		}
		// 		while (a_reverse--)
		// 			reverse_rotate_a(stack_a, 0);
		// 		while (b_reverse--)
		// 			reverse_rotate_b(stack_b, 0);
		// 	}
		// 	else
		// 	{
		// 		if (a_rotate < a_reverse)
		// 		{
		// 			while (a_rotate--)
		// 				rotate_a(stack_a, 0);
		// 		}
		// 		else
		// 		{
		// 			while (a_reverse--)
		// 				reverse_rotate_a(stack_a, 0);
		// 		}
		// 		if (b_rotate < b_reverse)
		// 		{
		// 			while (b_rotate--)
		// 				rotate_b(stack_b, 0);
		// 		}
		// 		else
		// 		{
		// 			while (b_reverse--)
		// 				reverse_rotate_b(stack_b, 0);
		// 		}
		// 	}
		// 	push_a(stack_a, stack_b);
		// 	return ;
		// }
		// else if (min(a_rotate, a_reverse) < state->lowest_moves)
		// {
		// 	if (min(a_rotate, a_reverse) > ft_lstsize(*stack_b) 
		// 	|| min(a_rotate, a_reverse) >= max_of(b_rotate, b_reverse))
		// 	{
		// 		if (a_rotate < a_reverse)
		// 		{
		// 			while (get_nth_idx(*stack_b, 0) != val)
		// 				double_rotate(stack_a, stack_b);
		// 			while (a_rotate--)
		// 				rotate_a(stack_a, 0);
		// 		}
		// 		else
		// 		{
		// 			while (get_nth_idx(*stack_b, 0) != val)
		// 			{
		// 				double_reverse_rotate(stack_a, stack_b);
		// 				a_reverse--;
		// 			}
		// 			while (a_reverse--)
		// 				reverse_rotate_a(stack_a, 0);
		// 		}
		// 		push_a(stack_a, stack_b);
		// 		return ;
		// 	}
		// }
		// else if (min(b_rotate, b_reverse) < state->lowest_moves)
		// {
		// 	if (min(b_rotate, b_reverse) > ft_lstsize(*stack_a) 
		// 	|| min(b_rotate, b_reverse) >= max_of(a_rotate, a_reverse))
		// 	{
		// 		if (b_rotate < b_reverse)
		// 		{
		// 			while (get_nth_idx(*stack_b, 0) != val)
		// 				double_rotate(stack_a, stack_b);
		// 			while (b_rotate--)
		// 				rotate_b(stack_b, 0);
		// 		}
		// 		else
		// 		{
		// 			while (get_nth_idx(*stack_b, 0) != val)
		// 			{
		// 				double_reverse_rotate(stack_a, stack_b);
		// 				b_reverse--;
		// 			}
		// 			while (b_reverse--)
		// 				reverse_rotate_b(stack_b, 0);
		// 		}
		// 		push_a(stack_a, stack_b);
		// 		return ;
		// 	}
		// }
		
// void	stack_b_export(t_list **stack_a, t_list **stack_b, t_state *state)
// {
// 	int	a_rotate;
// 	int	b_rotate;
// 	int	a_reverse;
// 	int	b_reverse;
	
// 	int unshared;
// 	int forward;
// 	int reverse;

// 	int val;
// 	int i = 0;
	
// 	int lowest_val = 0;
// 	int move_thresh = 100;
// 	while (get_nth_idx(*stack_b, i) != -1)
// 	{
// 		val = get_nth_idx(*stack_b, i);
// 		insert_pos(val, stack_a, stack_b, state);
// 		a_rotate = state->a_moves;
// 		b_rotate = state->b_moves;
// 		a_reverse = ft_lstsize(*stack_a) - a_rotate;
// 		b_reverse = ft_lstsize(*stack_b) - b_rotate;
		
// 		unshared = min(a_rotate, a_reverse) + min(b_rotate, b_reverse);
// 		forward = find_forward_shared(a_rotate, b_rotate);
// 		reverse = findd_reverse_shared(a_reverse, b_reverse);
		
// 		if (unshared <= min(forward, reverse))
// 		{
// 			if (unshared < move_thresh)
// 			{
// 				move_thresh = unshared;
// 				lowest_val = val;
// 			}
// 		}
// 		else if (forward < reverse)
// 		{
// 			if (forward < move_thresh)
// 			{
// 				move_thresh = forward;
// 				lowest_val = val;
// 			}
// 		}
// 		else
// 		{
// 			if (reverse < move_thresh)
// 			{
// 				move_thresh = reverse;
// 				lowest_val = val;
// 			}
// 		}
// 		i++;
// 	}
// 	// printf("Lowest Val: %d | Moves: %d\n", lowest_val ,move_thresh);
	
// }